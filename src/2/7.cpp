#include <iostream>
#include "linked-list.cpp"

Node *getEnd(LinkedList &list)
{
    Node *end = list.head;

    while (end->next)
    {
        end = end->next;
    }

    return end;
}

bool areIntersecting(LinkedList &l1, LinkedList &l2)
{
    Node *l1End = getEnd(l1);
    Node *l2End = getEnd(l2);

    return l1End == l2End;
}

Node *getIntersection(LinkedList &l1, LinkedList &l2)
{
    if (!areIntersecting(l1, l2))
    {
        return nullptr;
    }

    Node *longer = l1.length > l2.length ? l1.head : l2.head;
    Node *shorter = l1.length >= l2.length ? l2.head : l1.head;
    int lengthDiff = l1.length > l2.length ? l1.length - l2.length : l2.length - l1.length;

    for (auto i = 0; i < lengthDiff; i++)
    {
        longer = longer->next;
    }

    while (longer != shorter)
    {
        longer = longer->next;
        shorter = shorter->next;
    }

    return longer;
}

int main()
{
    LinkedList l2 = {3, 5};
    LinkedList l1 = {666, 4, 6, 7, 8};
    l2.append(l1);

    std::cout << (getIntersection(l1, l2))->data << endl;
}