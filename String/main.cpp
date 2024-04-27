#include"../String/head.h"

int main()
{
    MyString str = "TEMP dad Mam ";
    //std::cout << str.string_length();
    str.to_upper();
    str.shrink();

    std::cout << str.string_length() <<  std::endl;
    //std::cout << std::endl;

    return 0;
}