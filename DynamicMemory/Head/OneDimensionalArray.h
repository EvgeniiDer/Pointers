#ifndef ONEDIMENSIONALARRAY_H_
#define ONEDIMENSIONALARRAY_H_
#include<iostream>
#include<ctime>
#include<algorithm>
class MyArray{
    private:
        int ELEM;
        int *arr;
    public:
        MyArray(): ELEM(0), arr(nullptr){} //Zakomentiroval Gluchit Visual Studio Code
        MyArray(const int _ELEM); 
        MyArray(const MyArray&);
        int* allocFillOneDimensionalArray();
        MyArray& operator=(const MyArray&);

        MyArray(MyArray&&);
        MyArray& operator=(MyArray&&);

        int operator[](int n)const;
        int &operator[](int n);                    
        int get_elem(); 
        void push_back(const int&);
        void push_front(const int&);
        int insert(const int&, const int&);
        void pop_front();       
        void pop_back();

        bool erase(const int&);
        void show_my_array();
        ~MyArray();

};


#endif