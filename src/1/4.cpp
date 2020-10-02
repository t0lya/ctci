#include <iostream>
#include <vector>

bool isPermutationOfPalindrome(char *string)
{
    std::vector<bool> charDict(128, false);

    for (int i = 0; string[i] != '\0'; i++)
    {
        char c = tolower(string[i]);
        if (c != ' ')
        {
            charDict[(int)c] = !charDict[(int)c];
        }
    }

    int count = 0;
    for (int i = 0; i < 128; i++)
    {
        count += charDict[i];
    }

    return count < 2;
}

int main()
{
    std::cout << isPermutationOfPalindrome("Tact Coa");
    return 0;
}