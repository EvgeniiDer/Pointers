#include"../Head/head.h"

void FillArrayRandov(int _arr[], const int length)
{
    std::srand(time(0));
    for(int i = 0; i < length; i++)
    {
        _arr[i] = std::rand() % 100;
    }
}
void ShowArray(const int _arr[], const int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << _arr[i] << "\t";
    }
}
