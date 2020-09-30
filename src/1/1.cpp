#include <iostream>
#include <string>
#include <set>
using namespace std;

bool hasUniqueChars(string string)
{
    set<char> seen;

    for (auto x : string)
    {
        if (seen.count(x))
        {
            return false;
        }

        seen.insert(x);
    }

    return true;
}

int main()
{
    cout << hasUniqueChars("repeatingcharacters");
    cout << "\n";
    cout << hasUniqueChars("uniq");
    return 0;
}