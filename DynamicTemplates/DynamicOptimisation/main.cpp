#include"../DynamicOptimisation/Head/head.h"


int main()
{
    TwoDimensionalArray<int>array(5, 5);
    array.fill_array();
    int p;
    std::cin >> p;
    array.insert_row(p, true);
    array.print();


    return 0;
}