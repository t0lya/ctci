#include <iostream>
#include <string>

using namespace std;

string compress(const string str)
{
    if (!str.length())
    {
        return "";
    }

    char ch = str[0];
    int count = 0;
    string ret = "";

    for (auto i : str)
    {
        if (ch == i)
        {
            count++;
        }
        else
        {
            ret += ch + to_string(count);
            count = 1;
            ch = i;
        }
    }

    ret += ch + to_string(count);
    return ret.length() > str.length() ? ret : str;
}

int main()
{
    cout << compress("aaabbbbbbbccccccaaa");
    return 0;
}