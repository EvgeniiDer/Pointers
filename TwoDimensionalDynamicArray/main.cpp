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
    array.push_row_front(true);
    array.print();
    std::cout << "\n Function insert_row(Position = Position - 1, (false(random intege), true(last raw fill with 1111 at the Front \n" << 
                    "9999 at the back ant 5555 in the middle)) insert a row according position\n";
    int pos; 
    std::cout << "Enter the position(POSITION Must be not less 1 and no more the " << array.getRow() << "): ";
    std::cin >> pos;
    if(array.insert_row(pos, true))
        array.print();
    else{
        std::cerr << "You entered position less then 1 or more " << array.getRow() <<
        "\n\t\t\aEXIT_FAILURE" <<  "\n";
        return EXIT_FAILURE;
    }
    return 0;
}