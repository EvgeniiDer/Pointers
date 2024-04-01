#include"../DynamicMemory/Head/head.h"

//constexpr int ELEM = 5;

int main()
{
    MyArray array(3);
    MyArray ar;
    std::cout << " Push Element 99999 at the back of Array! \n";
    array.push_back(99999);
    array.show_my_array();
    std::cout << "\n Push Element 11111 at the front of Array! \n";
    array.push_front(11111);
    array.show_my_array();
    int position, number;
    std::cout << "\n Enter the postion and number you would like to insert: \n";
    std::cin >> position >> number;
    std::cout << "\n";
    if(array.insert(position, number) == false)
    {
        return EXIT_FAILURE;
    }
    array.show_my_array();
    std::cout << "\n Pop Element of Array out from front\n";
    array.pop_front();
    array.show_my_array();
    std::cout << "\n";
    std::cout <<"\n Pop Element of Araay out from back\n";
    array.pop_back();
    array.show_my_array();
    std::cout <<"\n Enter the Element of Array out would like to erase\n";
    std::cout << "Total Elements of Array: " << array.get_elem() << std::endl;
    int rm;
    std::cin >> rm;
    if(!array.erase(rm))
    {
        std::cerr << "Elemetnt can't be less or equel 0 or more than Elemen of Array!!\n !!Failuer EXIT!!\n";
        return EXIT_FAILURE;
    }
    array.show_my_array();

    std::cout << "Total Array's ELEMENTS: " << array.get_elem() << std::endl;

    return 0;
}