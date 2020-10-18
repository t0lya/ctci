#include <iostream>
#include <bitset>

int insert(int N, int M, int i, int j)
{
    int mask = (~0 << (j + 1)) | ~(~0 << i);
    return (mask & N) | (M << i);
}

int main()
{
    int a = insert(0b10000000000, 0b10111, 2, 6);
    std::bitset<16> x(a);
    std::cout << x;

    return 0;
}