#include <iostream>

using namespace std;

int waysTo3Step(int steps)
{
    if (steps == 0 || steps == 1)
    {
        return 1;
    }

    if (steps == 2)
    {
        return 2;
    }

    if (steps == 3)
    {
        return 4;
    }

    int a = 1;
    int b = 2;
    int c = 4;
    unsigned long long int ret;
    for (int i = 3; i < steps; i++)
    {
        ret = a + b + c;
        a = b;
        b = c;
        c = ret;
    }

    return ret;
}

int main()
{
    cout << waysTo3Step(30);
    return 0;
}