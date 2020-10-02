#include <iostream>

void urlify(char *string, int trueLength)
{
    int end = std::strlen(string) - 1;

    for (int i = trueLength - 1; i >= 0; i--)
    {
        if (string[i] != ' ')
        {
            string[end] = string[i];
            end--;
        }
        else
        {
            string[end] = '0';
            string[end - 1] = '2';
            string[end - 2] = '%';
            end -= 3;
        }
    }
}

int main()
{
    char test[] = "Mr John Smith    ";
    urlify(test, 13);
    std::cout << test;
    return 0;
}