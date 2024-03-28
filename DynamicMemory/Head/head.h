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
        int operator[](int n)const;
        int &operator[](int n);                    
        int get_elem(); 
        void push_back(const int&);
        void push_front(const int&);
        int insert(const int&, const int&);
        void pop_back();

        void pop_front();
        void erase(int);
        void show_my_array();
        ~MyArray();

};


#endif