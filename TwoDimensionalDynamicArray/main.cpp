#include"../TwoDimensionalDynamicArray/Head/twodimensionalarray.h"

int main()
{
    TwoDimensionalArray array2(5, 5);
    TwoDimensionalArray array = array2;
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
    std::cout << "Funciton pop_row_back() pop row from the back of two-dimensional array\n";
    array.pop_row_back();
    array.print();
    std::cout << "Function pop_row_front() pop a row from the front of the two-dimensional array\n";
    array.pop_row_front();
    array.print();
    std::cout << "Funciion erase_row(const int&) Erase the row number specified in the function argument\n";
    pos = 0;
    std::cin >> pos;
    if(array.erase_row(pos))
        array.print();
    else{
        std::cerr << "You entered position less then 1 or more " << array.getRow() <<
        "\n\t\t\aEXIT_FAILURE" <<  "\n";
        return EXIT_FAILURE;
    }
    std::cout << "\n Function push_col_back(false(random intege), true(last column fill with 9999 at the Back)) \n" <<
                 "add column at the back of two-dimensional array\n"; 
    array.push_col_back(true);
    array.print();
    std::cout << "\n Function push_col_front(false(random intege), true(last column fill with 1111 at the Front)) \n" <<
                 "add column at the front of two-dimensional array\n"; 
    array.push_col_front(true);
    array.print();

    std::cout << "\n Function insert_col(Position = Position - 1, (false(random intege), true( fill with 1111 at the Front column\n" << 
                    "9999 at the back, and 5555 in the middle)) insert a column according position\n";
    
    std::cout << "Enter the position(POSITION Must be not less 1 and no more the " << array.getColm() << "): ";
    pos = 0;
    std::cin >> pos;
    if(array.insert_col(pos, true))
        array.print();
    else{
        std::cerr << "You entered position less then 1 or more " << array.getColm() <<
        "\n\t\t\aEXIT_FAILURE" <<  "\n";
        return EXIT_FAILURE;
    }
    std::cout << "Funciton pop_col_back() pop column from the back of two-dimensional array\n";
    array.pop_col_back();
    array.print();
    std::cout << "Funciton pop_col_front() pop column from the front of two-dimensional array\n";
    array.pop_col_front();
    array.print();
    std::cout << "Funciion erase_col(const int&) Erase the column number specified in the function argument\n";
    pos = 0;
    std::cin >> pos;
    if(array.erase_col(pos))
        array.print();
    else{
        std::cerr << "You entered position less then 1 or more " << array.getColm() <<
        "\n\t\t\aEXIT_FAILURE" <<  "\n";
        return EXIT_FAILURE;
    }
    return 0;
}