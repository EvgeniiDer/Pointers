#ifndef HEAD_H_
#define HEAD_H_
#include<iostream>
#include<cstring>
class MyString
{
    private:
        int SIZE;
        char* str;
        int rv;
    public:
        MyString() : SIZE(0),
                     str(nullptr),
                     rv(0){};
        MyString(const char *_str) : SIZE(strlen(_str)),
                                     str(new char[strlen(_str)]),
                                     rv(strlen(_str))
            {
                for(size_t i = 0; i < strlen(_str); i++)
                {
                    str[i] = _str[i];
                }
            };
        MyString(const int& _sz, const int& _rv) : SIZE(_sz),
                                                   str(new char[_sz]),
                                                   rv(_rv){};  

        MyString(const MyString& _arg);
        MyString& operator=(const MyString& _arg);
        MyString(MyString&& _arg);
        MyString& operator=(MyString&& _arg);

        friend std::ostream& operator<<(std::ostream& _stream, const MyString& _str);
        friend std::istream& operator>>(std::istream& _is, MyString& _str);
        

        char& operator[](const int& _n);
        char operator[](const int& _n)const;
        
        
        //int reserve();
        //int resize();
        int string_length();
        void to_lower();
        void to_upper();
        void shrink();
        bool is_palindrom();
        bool is_int_number();
        int to_int_number();
        ~MyString(){
            delete[]str;
        }
};

#endif