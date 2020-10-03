#include <iostream>
#include <unordered_set>
#include "linked-list.cpp"

void removeDupes(LinkedList &list)
{
    unordered_set<int> seen;

    Node *previous = nullptr;
    Node *current = list.head;
    while (current)
    {
        Node *next = current->next;

        if (seen.count(current->data))
        {
            delete current;
            previous->next = next;
        }
        else
        {
            previous = current;
            seen.insert(current->data);
        }

        current = next;
    }
}

int main()
{
    LinkedList test = {13, 14, 3, 64, 2, 3, 6, 14, 14, 3, 64};
    test.print();
    removeDupes(test);
    test.print();

    return 0;
}