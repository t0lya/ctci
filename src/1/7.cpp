#include <iostream>

using namespace std;

template <size_t n>
void rotateMatrix(int (&matrix)[n][n])
{
    for (size_t i = 0; i < (n / 2); i++)
    {
        for (size_t j = i; j < n - 1 - i; j++)
        {
            int top = matrix[i][j];
            int right = matrix[j][n - 1 - i];
            int bottom = matrix[n - 1 - i][n - 1 - j];
            int left = matrix[n - 1 - j][i];

            matrix[i][j] = left;
            matrix[j][n - 1 - i] = top;
            matrix[n - 1 - i][n - 1 - j] = right;
            matrix[n - 1 - j][i] = bottom;
        }
    }
}

template <size_t n>
void printMatrix(int (&matrix)[n][n])
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }

        cout << endl;
    }
}

int main()
{
    int test1[5][5] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}};
    printMatrix(test1);
    rotateMatrix(test1);
    cout << "After rotation:\n";
    printMatrix(test1);

    cout << endl;
    int test2[4][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    };
    printMatrix(test2);
    rotateMatrix(test2);
    cout << "After rotation:\n";
    printMatrix(test2);

    return 0;
}