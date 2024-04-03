#include"../TwoDimensionalDynamicArray/Head/twodimensionalarray.h"

int main()
{
    TwoDimensionalArray array(2, 5);
    std::cout << "  \nMemory was allocated for two dimensional array and it was filled with random integer values from 0 to 99\n";
    array.fill_array();
    array.print();
    std::cout << " \n Function push_row_back((false(random intege), true(last raw fill with 9999)) add row at the back of Two-Dimensional array\n";
    array.push_row_back(true);//true (9999), false (Random integer)
    array.print();
    std::cout << " \n Function push_row_front((false(random intege), true(last raw fill with 1111)) add row at the front of Two-Dimensional array\n";

    return 0;
}