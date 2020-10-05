#include <iostream>
#include "linked-list.cpp"

Node *sumNode(Node *n1, Node *n2, int carry = 0)
{
    if (n1 == nullptr && n2 == nullptr && carry == 0)
    {
        return nullptr;
    }

    int i1 = 0, i2 = 0;

    if (n1)
    {
        i1 = n1->data;
    }

    if (n2)
    {
        i2 = n2->data;
    }

    int sum = i1 + i2 + carry;
    auto newNode = new Node(sum % 10);
    newNode->next = sumNode(n1 ? n1->next : nullptr, n2 ? n2->next : nullptr, sum / 10 % 10);

    return newNode;
}

LinkedList *sumList(LinkedList &list1, LinkedList &list2)
{
    return new LinkedList(sumNode(list1.head, list2.head));
}

int main()
{
    LinkedList d1 = {7, 5, 8, 3, 5};
    LinkedList d2 = {5, 9, 8, 4, 9};
    auto sum = sumList(d1, d2);
    sum->print();
    std::cout << 53857 + 94895;

    return 0;
}