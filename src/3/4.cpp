#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class MyQueue
{
private:
    stack<T> oldest;
    stack<T> newest;
    size_t queueSize = 0;

    void refreshOldest();

public:
    void add(T item);
    T remove();
    T peek();
    void print();
    size_t size() { return queueSize; };
};

template <typename T>
void MyQueue<T>::refreshOldest()
{
    if (oldest.empty())
    {
        while (!newest.empty())
        {
            oldest.push(newest.top());
            newest.pop();
        }
    }
}

template <typename T>
void MyQueue<T>::add(T item)
{
    newest.push(item);
    queueSize++;
}

template <typename T>
T MyQueue<T>::remove()
{
    if (oldest.empty() && newest.empty())
    {
        return T();
    }

    refreshOldest();

    auto ret = oldest.top();
    oldest.pop();
    queueSize--;

    return ret;
}

template <typename T>
T MyQueue<T>::peek()
{
    refreshOldest();
    return oldest.top();
}

template <typename T>
void MyQueue<T>::print()
{
    refreshOldest();
    stack<T> tmp;

    while (!oldest.empty())
    {
        auto item = oldest.top();
        cout << item << ' ';
        tmp.push(item);
        oldest.pop();
    }

    while (!tmp.empty())
    {
        oldest.push(tmp.top());
        tmp.pop();
    }

    cout << endl;
}

int main()
{
    MyQueue<int> test;
    test.add(3);
    test.add(5);
    test.add(9);
    test.print();

    cout << test.remove() << endl;
    test.print();
    cout << test.peek() << endl;

    return 0;
}