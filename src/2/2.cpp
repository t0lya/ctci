#include <iostream>
#include <tuple>
#include "linked-list.cpp"

using namespace std;

tuple<const Node *, int> kthToLast(const Node *current, int k)
{
    if (current->next == nullptr)
    {
        return {current, 1};
    }

    auto [ret, count] = kthToLast(current->next, k);

    if (count == k)
    {
        return {ret, count};
    }
    else
    {
        return {current, count + 1};
    }
}

int main()
{
    LinkedList test = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    auto [kthToLastNode, count] = kthToLast(test.head, 4);
    cout << kthToLastNode->data << endl
         << count;

    return 0;
}