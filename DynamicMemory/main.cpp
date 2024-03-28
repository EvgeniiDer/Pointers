#include"../DynamicMemory/Head/head.h"

//constexpr int ELEM = 5;

int main()
{
 
    MyArray array(3);
    
    array.push_back(99999);
    array.push_front(11111);
    int position, number;
    std::cout << "Enter the postion and number you would like to insert: \n";
    std::cin >> position >> number;
    std::cout << "\n";
    if(array.insert(position, number) == false)
    {
        return EXIT_FAILURE;
    }
    
    array.show_my_array();
    array.pop_back();
    std::cout << "\n";
    array.show_my_array();
    std::cout << "Total Array's ELEMENTS: " << array.get_elem() << std::endl;
    return 0;
}