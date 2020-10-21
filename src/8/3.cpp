#include <iostream>

using namespace std;

int _magicIndex(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;

    if (arr[mid] == mid)
    {
        return mid;
    }

    if (end - start == 0)
    {
        return -1;
    }

    if (arr[mid] < mid)
    {
        return _magicIndex(arr, mid, end);
    }
    else
    {
        return _magicIndex(arr, start, mid);
    }
}

int magicIndex(int arr[], int length)
{
    return _magicIndex(arr, 0, length);
}

int main()
{
    int arr[] = {-30, -10, 1, 2, 3, 4, 5, 7, 12, 13};
    cout << magicIndex(arr, 10);
    return 0;
}