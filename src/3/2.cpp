#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class StackWithMin
{
private:
    stack<T> minStack;
    stack<T> data;

public:
    StackWithMin(){};

    void push(T item);
    T pop();
    T min()
    {
        if (minStack.empty())
            return T();

        return minStack.top();
    };
    void print();
};

template <typename T>
void StackWithMin<T>::push(T item)
{
    data.push(item);

    if (minStack.empty() || item < minStack.top())
    {
        minStack.push(item);
    }
};

template <typename T>
T StackWithMin<T>::pop()
{
    auto ret = data.top();
    data.pop();

    if (!minStack.empty() && ret == minStack.top())
    {
        minStack.pop();
    }

    return ret;
};

template <typename T>
void StackWithMin<T>::print()
{
    if (data.empty())
        return;

    auto item = data.top();
    data.pop();
    print();
    cout << item << ' ';
    data.push(item);
};

template <typename T>
void popAndPrintMin(StackWithMin<T> &stack)
{
    stack.pop();
    stack.print();
    cout << endl;
    cout << stack.min() << endl;
}

int main()
{
    StackWithMin<int> test;
    test.push(8);
    test.push(6);
    test.push(7);
    test.push(5);
    test.push(3);
    test.print();
    cout << endl;
    cout << test.min() << endl;

    popAndPrintMin<int>(test);
    popAndPrintMin<int>(test);
    popAndPrintMin<int>(test);
    popAndPrintMin<int>(test);

    return 0;
}