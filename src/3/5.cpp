#include <iostream>
#include <stack>

using namespace std;

void insertStack(int item, stack<int> &s, stack<int> &tmp)
{
    int count = 0;
    while (!s.empty() && s.top() > item)
    {
        tmp.push(s.top());
        count++;
        s.pop();
    }

    s.push(item);

    while (count > 0)
    {
        s.push(tmp.top());
        tmp.pop();
        count--;
    }
}

void sortStack(stack<int> &s)
{
    stack<int> reverse;

    while (!s.empty())
    {
        auto item = s.top();
        s.pop();
        insertStack(item, reverse, s);
    }

    while (!reverse.empty())
    {
        s.push(reverse.top());
        reverse.pop();
    }
}

void print(stack<int> &s)
{
    if (s.empty())
        return;

    auto item = s.top();
    s.pop();
    print(s);
    cout << item << ' ';
    s.push(item);
}

int main()
{
    stack<int> test({3, 7, 12, 8, 9, 4, 16, 8, 2, 8, 4, 14, 7, 19});
    sortStack(test);
    print(test);

    return 0;
}