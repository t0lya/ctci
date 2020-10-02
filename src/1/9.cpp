#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string str2)
{
    return str1.find(str2) != string::npos;
}

bool isRotation(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }

    // if s1 = s2 then vacuously true.
    // if s2 is substring of s1 + s1,
    // then part of s2 is in first s1
    // and another part of s2 is in second s1.
    // but the second part of s2 has to equal
    // the remaining portion of first s1.
    // thus second part of s2 + first part of s2 = s1.
    return isSubstring(str1 + str1, str2);
}

int main()
{
    cout << isRotation("waterbottle", "erbottlewat") << endl;
    cout << isRotation("waterbotsle", "erbottlewat");
    return 0;
}