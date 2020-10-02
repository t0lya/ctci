#include <iostream>
#include <tuple>

using namespace std;

template <size_t sizeX, size_t sizeY>
tuple<int, int> findZero(int (&matrix)[sizeX][sizeY])
{
    for (size_t i = 0; i < sizeX; i++)
    {
        for (size_t j = 0; j < sizeY; j++)
        {
            if (matrix[i][j] == 0)
            {
                return {i, j};
            }
        }
    }

    return {NULL, NULL};
}

template <size_t sizeX, size_t sizeY>
void zeroMatrix(int (&matrix)[sizeX][sizeY])
{
    auto [zeroRow, zeroColumn] = findZero(matrix);

    if (!zeroRow && !zeroColumn)
    {
        return;
    }

    for (size_t i = zeroRow; i < sizeX; i++)
    {
        for (size_t j = 0; j < sizeY; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[zeroRow][j] = 0;
                matrix[i][zeroColumn] = 0;
            }
        }
    }

    for (size_t j = 0; j < sizeY; j++)
    {
        if (matrix[zeroRow][j] == 0 && j != zeroColumn)
        {
            for (size_t i = 0; i < sizeX; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < sizeX; i++)
    {
        if (matrix[i][zeroColumn] == 0)
        {
            for (size_t j = 0; j < sizeX; j++)
            {
                matrix[i][j] = 0;
            }
        }

        matrix[i][zeroColumn] = 0;
    }
}

template <size_t x, size_t y>
void printMatrix(int (&matrix)[x][y])
{
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            cout << matrix[i][j] << ' ';
        }

        cout << endl;
    }
}

int main()
{
    int test[4][4] = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
    };
    printMatrix(test);
    zeroMatrix(test);
    cout << "After:\n";
    printMatrix(test);

    return 0;
}

// Actually there is no need to find first zero.
// Could have just used first row, first column,
// and then nuke them at the very end if necessary.