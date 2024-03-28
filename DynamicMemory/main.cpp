#include"../DynamicMemory/Head/head.h"

//constexpr int ELEM = 5;

int main()
{
 
    MyArray array(3);
    std::cout << "Total Array's ELEMENTS: " << array.get_elem() << std::endl;
    array.show_my_array();
    std::cout << "Hellow World" << std::endl;
    return 0;
}