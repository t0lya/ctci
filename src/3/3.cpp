#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class SetOfStacks
{
private:
    stack<stack<T>> data;
    size_t currentSize;
    const size_t maxSize = 2;

    void printStack(stack<T> stack);

public:
    SetOfStacks()
    {
        stack<T> firstStack;
        data.push(firstStack);
        currentSize = 0;
    }

    size_t size() { return currentSize; };
    void push(T item);
    T pop();
    T popAt(uint index);
    void print();
};

template <typename T>
void SetOfStacks<T>::push(T item)
{
    if (data.top().size() < maxSize)
    {
        data.top().push(item);
    }
    else
    {
        stack<T> newStack;
        newStack.push(item);
        data.push(newStack);
    }

    currentSize++;
}

template <typename T>
T SetOfStacks<T>::pop()
{
    if (currentSize == 0)
        return T();

    T ret = data.top().top();
    data.top().pop();

    currentSize--;

    if (data.size() > 1 && data.top().empty())
        data.pop();

    return ret;
}

template <typename T>
void SetOfStacks<T>::printStack(stack<T> s)
{
    if (s.size() == 0)
        return;

    stack<T> tmp;
    while (s.size() > 0)
    {
        tmp.push(s.top());
        s.pop();
    }

    while (tmp.size() > 0)
    {
        auto item = tmp.top();
        cout << item << ' ';
        s.push(item);
        tmp.pop();
    }
}

template <typename T>
void SetOfStacks<T>::print()
{
    if (data.size() < 1)
        return;

    stack<T> stack = data.top();
    data.pop();
    print();
    printStack(stack);
    data.push(stack);
}

template <typename T>
T SetOfStacks<T>::popAt(uint index)
{
    if (index + 1 > data.size())
    {
        return T();
    }

    stack<stack<T>> tmpStackSet;
    while (data.size() > index + 1)
    {
        tmpStackSet.push(data.top());
        data.pop();
    }

    auto ret = data.top().top();
    data.top().pop();

    if (data.top().size() == 0)
    {
        data.pop();
    }

    while (tmpStackSet.size() > 0)
    {
        data.push(tmpStackSet.top());
        tmpStackSet.pop();
    }

    currentSize--;
    return ret;
}

int main()
{
    SetOfStacks<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    test.print();

    cout << endl
         << test.popAt(0) << endl;
    test.print();

    cout << endl
         << test.popAt(0) << endl;
    test.print();

    return 0;
}
