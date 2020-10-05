#include <iostream>
#include "linked-list.cpp"

void partition(LinkedList &list, int pivot)
{
    Node *current = list.head;

    while (current && current->next)
    {
        if (current->next->data < pivot)
        {
            Node *next = current->next;
            current->next = current->next->next;
            next->next = list.head;
            list.head = next;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    LinkedList test = {3, 5, 8, 7, 5, 3, 10, 1, 2, 1, 15, 4, 4};
    partition(test, 5);
    test.print();

    return 0;
}