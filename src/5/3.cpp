#include <iostream>

using namespace std;

int flipLength(int num)
{
    int ret = 1;
    int count1 = 0;
    int count2 = 0;
    bool hasFlipped1 = false;
    bool hasFlipped2 = true;

    while (num != 0)
    {
        int val = num & 1;
        if (val == 1)
        {
            count1++;
            count2++;
        }
        else if (hasFlipped1 && !hasFlipped2)
        {
            hasFlipped2 = true;
            count2++;

            hasFlipped1 = false;
            ret = count1 > ret ? count1 : ret;
            count1 = 0;
        }
        else if (hasFlipped2 && !hasFlipped1)
        {
            hasFlipped1 = true;
            count1++;

            hasFlipped2 = false;
            ret = count2 > ret ? count2 : ret;
            count2 = 0;
        }

        num >>= 1;
    }

    return ret;
}

int main()
{
    cout << flipLength(1775);
    return 0;
}