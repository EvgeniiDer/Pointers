#include"../String/head.h"

int main()
{
    MyString str = "32";
    //std::cout << str.string_length();
    str.to_upper();
    str.shrink();
    if(str.is_palindrom())
        std::cout << str << " " << "is palindrom!!";
    else 
        std::cout << str << " " << "is not palindrom!!";
    std::cout << std::endl;
    if(str.is_int_number())
        {
            std::cout << str << " " << "is digit!!";
            std::cout << "Convert from char to int: str.to_int_number() == " << str.to_int_number() << std::endl;
        }
    else
        std::cout << str << " " << "is not digit!!";
    std::cout << std::endl;
  
    return 0;
}