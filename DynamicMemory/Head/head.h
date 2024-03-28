#ifndef HEAD_H_
#define HEAD_H_
#include<iostream>
#include<ctime>

class MyArray{
    private:
        int ELEM;
        int *arr;
    public:
         MyArray(int _ELEM) : ELEM{_ELEM},
                              arr{new int[_ELEM]}
                            {
        std::cout << "!!Constructor!!" << std::endl;
        std::srand(std::time(0));
        for(int i = 0; i < ELEM; i++)
            {
                arr[i] = std::rand() % 100;
            }            
                            }
        int get_elem();
        void push_back(int);
        void push_front(int);
        void insert(int);
        void pop_back(int);
        void pop_front(int);
        void erase(int);
        void show_my_array();
        ~MyArray();

};


#endif