#include "../Head/head.h"


int MyArray::get_elem()
{
    return ELEM;
}
void MyArray::show_my_array()
{
    int count = 1;
    for(int *i = arr; i != arr + ELEM; i++)
    {
        std::cout << count << ": " << *i << std::endl;
        count++;
    }
}
MyArray::~MyArray()
{
    std::cout << "!!Distructor!!" << std::endl;
    delete[]arr;
    arr = nullptr;

}
