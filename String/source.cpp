#include"../String/head.h"

MyString::MyString(const MyString& _arg)
{
    SIZE = _arg.SIZE;
    str = new char[_arg.SIZE];
    for(int i = 0; i < _arg.SIZE; i++)
        str[0] = _arg.str[0];
    rv = _arg.rv;
}

MyString& MyString::operator=(const MyString& _arg)
{
    char* buffer = new char[_arg.SIZE];
    for(int i = 0; i < _arg.SIZE; i++)
        buffer[i] = _arg.str[i];
    delete[]str;
    str = buffer;
    SIZE = _arg.SIZE;
    rv = _arg.rv;
    return *this;
}
MyString::MyString(MyString&& _arg)
{
    SIZE = _arg.SIZE;
    str = _arg.str;
    rv = _arg.rv;
    _arg.SIZE = 0;
    _arg.str = nullptr;
    _arg.rv = 0;
}
MyString& MyString::operator=(MyString&& _arg)
{
    delete[]str;
    str = _arg.str;
    SIZE = _arg.SIZE;
    rv = _arg.rv;
    _arg.SIZE = 0;
    _arg.str = nullptr;
    _arg.rv = 0;
    return *this;
}
std::ostream& operator<<(std::ostream& stream, const MyString& _str)
{
    for(int i = 0; i < _str.SIZE; i++)
        stream << _str.str[i];
    return stream;
}
std::istream& operator>>(std::istream& is, MyString& _str)
{
    std::string buffer;
    is >> buffer;
    delete[]_str.str;
    _str.SIZE = buffer.size();
    _str.rv = buffer.size();
    _str.str = new char[buffer.size()];
    memcpy(_str.str,buffer.c_str(), _str.SIZE);
    return is;
}

char& MyString::operator[](const int& _n)
{
    return str[_n];
}
char MyString::operator[](const int& _n)const
{
    return str[_n];
}
int MyString::string_length()
{
    return SIZE;
}

void MyString::to_lower()
{
    char* buffer = new char[SIZE];
    for(int i = 0; i < SIZE; i++)
        buffer[i] = tolower(str[i]);
    delete[]str;
    str = buffer;
}
void MyString::to_upper()
{
    char* buffer = new char[SIZE];
    for(int i = 0; i < SIZE; i++)
        buffer[i] = toupper(str[i]);
    delete[]str;
    str = buffer;
}
void MyString::shrink()
{
    int spacecount = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(str[i] == ' ')
            spacecount++;
    }
    //std::cout << spacecount << std::endl;
    char* buffer = new char[SIZE - spacecount];
    for(int i = 0, j = 0; i < SIZE; i++, j++)
    {
        
        
        if(str[i] == ' ')
            {
                j--;
            }
        else
            {
                buffer[j] = str[i];
            }
    }
    delete[]str;
    str = buffer;
    SIZE = SIZE - spacecount;
    rv = SIZE - spacecount;   
}
bool MyString::is_palindrom()
{
    
}