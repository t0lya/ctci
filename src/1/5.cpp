#include <iostream>

using namespace std;

bool isOneAway(const char *str1, const char *str2)
{
    bool edited = false;
    int length = min(strlen(str1), strlen(str2));

    for (int i = 0, j = 0; i < length; i++, j++)
    {
        if (str1[i] != str2[j])
        {
            if (edited)
            {
                return false;
            }

            edited = true;

            if (strlen(str1) > strlen(str2))
            {
                i++;
            }

            if (strlen(str2) > strlen(str1))
            {
                j++;
            }
        }
    }

    return true;
}

int main()
{
    cout << "pale, ple\n";
    cout << isOneAway("pale", "ple");

    cout << "\npale, pales\n";
    cout << isOneAway("pale", "pales");

    cout << "\npale, bale\n";
    cout << isOneAway("pale", "bale");

    cout << "\npale, bake\n";
    cout << isOneAway("pale", "bake");
}