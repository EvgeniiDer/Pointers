#include"../DynamicOptimisation/Head/head.h"


int main()
{
    TwoDimensionalArray<float>array(5, 4);
    array.fill_array();
    array.print();
    std::cout << std::endl;
    array.push_row_back(true);
    array.print();
    array.push_row_front(true);
    array.print();

    return 0;
}