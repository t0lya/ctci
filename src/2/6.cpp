#include <iostream>
#include "linked-list.cpp"

using namespace std;

// O(n) space & time
bool isPalindromeRecursive(Node *node, int count, Node **next)
{
    if (count == 0)
    {
        *next = node;
        return true;
    }

    if (node && count == 1)
    {
        *next = node->next;
        return true;
    }

    auto isMiddlePalindrome = isPalindromeRecursive(node->next, count - 2, next);
    if (!isMiddlePalindrome)
    {
        return false;
    }

    auto isPalindrome = (node->data == (*next)->data) && isMiddlePalindrome;
    *next = (*next)->next;
    return isPalindrome;
}

bool isPalindrome(LinkedList &list)
{
    Node *dummy = nullptr;
    return isPalindromeRecursive(list.head, list.length, &dummy);
}

int main()
{
    LinkedList test = {1, 2, 3, 3, 2, 1};
    cout << isPalindrome(test) << endl;

    LinkedList test1 = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    cout << isPalindrome(test1) << endl;

    LinkedList test2 = {1, 2, 3, 4, 5, 5, 3, 2, 1};
    cout << isPalindrome(test2) << endl;

    LinkedList test3 = {99};
    cout << isPalindrome(test3) << endl;

    LinkedList test4 = {5, 7};
    cout << isPalindrome(test4) << endl;

    return 0;
}