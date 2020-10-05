#include <iostream>
#include "linked-list.cpp"

void deleteMiddle(Node *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return;
    }

    Node *next = node->next;
    node->data = next->data;
    node->next = next->next;

    delete next;
}

int main()
{
    LinkedList test = {1, 2, 3, 4, 5, 6, 7};
    deleteMiddle((test.head)->next->next->next);
    test.print();

    return 0;
}