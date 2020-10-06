#include <iostream>
#include "linked-list.cpp"

Node *isCycle(LinkedList &list)
{
    Node *head = list.head;

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *slow = head->next;
    Node *fast = head->next->next;

    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            return nullptr;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return fast;
}

Node *cycleFirstNode(LinkedList &list)
{
    Node *cycleNode = isCycle(list);
    if (cycleNode == nullptr)
    {
        return nullptr;
    }

    // Using neat trick where slow/fast ptrs meet
    // at (-k mod L)th cycle node, where k is length
    // of non-cycle part and L is length of cycle.
    // Thus after k iterations, we should arrive at
    // first node of cycle.
    Node *nonCycleNode = list.head;
    while (nonCycleNode != cycleNode)
    {
        nonCycleNode = nonCycleNode->next;
        cycleNode = cycleNode->next;
    }

    return cycleNode;
}

int main()
{
    LinkedList test = {1, 2, 3, 4, 5};
    (test.head)->next->next->next->next->next = (test.head)->next->next;
    Node *cycleStart = cycleFirstNode(test);

    std::cout << cycleStart->data << endl;

    return 0;
}