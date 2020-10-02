#include <iostream>
#include <string>
#include <array>

using namespace std;

array<int, 128> toCharCount(string str)
{
    array<int, 128> charCount = {};
    for (auto x : str)
    {
        ++charCount[(int)(x)];
    }
    return charCount;
}

bool isPermutation(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    auto count1 = toCharCount(str1);
    auto count2 = toCharCount(str2);

    return count1 == count2;
}

int main()
{
    bool test = isPermutation("permutation", "titanomupra");

    cout << test;

    return 0;
}