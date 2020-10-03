#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data{0}, next{nullptr} {}
    Node(int i) : data{i}, next{nullptr} {}
    Node(int i, Node *next) : data{i}, next{next} {}
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head{new Node()} {};
    LinkedList(Node *node) : head{node} {};
    LinkedList(initializer_list<int> list)
    {
        Node *current, *previous = nullptr;
        int count = 0;
        for (auto i : list)
        {
            current = new Node(i);
            if (count == 0)
            {
                head = current;
            }
            if (previous)
            {
                previous->next = current;
            }
            previous = current;
            count++;
        }
    }
    ~LinkedList()
    {
        Node *current = head;

        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int i)
    {
        Node *current = head;
        while (current->next)
        {
            current = current->next;
        }

        current->next = new Node(i);
    }

    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << '\n';
    }
};