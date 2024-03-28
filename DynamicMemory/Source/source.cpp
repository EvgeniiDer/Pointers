#include "../Head/head.h"


int MyArray::get_elem()
{
    return ELEM;
}
void MyArray::show_my_array()
{
    int count = 1;
    for(int *i = arr; i != arr + ELEM; i++)
    {
        std::cout << count << ": " << *i << std::endl;
        count++;
    }
}
int MyArray::operator[](int n) const
{
    return arr[n];
}
int &MyArray::operator[](int n)
{
    return arr[n];
}

void MyArray::push_back(const int &addBack)
{
    ELEM++;
    int * newArr = new int[ELEM];
    for(int i = 0; i < ELEM - 1; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[ELEM - 1] = addBack;
    delete [] arr;
    arr = nullptr;
    arr = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArr[i];
    }
    delete[]newArr;
    newArr = nullptr;
}
void MyArray::push_front(const int &addFront)
{
    ELEM++;
    int *newArr = new int[ELEM];
    newArr[0] = addFront;
    for(int i = 0; i < ELEM; i++)
    {
        newArr[i + 1] = arr[i];
    }
    delete[]arr;
    arr = nullptr;
    arr = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArr[i];
    }
    delete[]newArr;
    newArr = nullptr;
}
int MyArray::insert(const int &_position, const int &addInsert)
{

    if(_position == 0 || _position > ELEM)
    {
        std::cerr << "The element cannot be less than 0 or More then ELEM\n Failuer EXIT";
        return false;
    }
    ELEM++;
    int *newArray = new int[ELEM];
    for(int i = 0; i < _position - 1; i++)
    {
        newArray[i] = arr[i];
    }
    newArray[_position - 1] = addInsert;
    for(int i = _position - 1 ; i < ELEM; i++)
    {
        newArray[i + 1] = arr[i];
    }
    delete[]arr;
    arr = nullptr;
    arr = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArray[i];
    }
    delete[] newArray;
    newArray = nullptr;
    return true;
}

void MyArray::pop_front()
{
    int newElement = ELEM;
    int *newArray = new int[--newElement];
    for(int i = 1; i < ELEM; i++)
    {
        newArray[i - 1] = arr[i];
    }
    delete[]arr;
    arr = nullptr;
    ELEM--;
    arr = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArray[i];
    }
    delete[]newArray;
    newArray = nullptr;
}
void MyArray::pop_back()
{
    ELEM--;
    int *newArray = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        newArray[i] = arr[i];
    }
    delete[]arr;
    arr = nullptr;
    arr = new int[ELEM];
    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArray[i];
    }
    delete[]newArray;
    newArray = nullptr;
}

int MyArray::erase(const int& _position)
{
    if(_position == 0 || _position > ELEM)
    {
        std::cerr << "The element cannot be less than 0 or More then ELEM\n Failuer EXIT";
        return false;
    }
    int newElement = ELEM;
    int *newArray = new int[--newElement];
    for(int i = 0; i < _position; i++)
    {
        newArray[i] = arr[i];
    }
    for(int i = _position + 1; i < ELEM; i++)
    {
        newArray[i - 1] = arr[i];
    }
    ELEM = newElement;
    delete[]arr;
    arr = nullptr;
    arr = new int[ELEM];

    for(int i = 0; i < ELEM; i++)
    {
        arr[i] = newArray[i];
    }
    delete[]newArray;
    newArray = nullptr;
    return 1;
}
MyArray::~MyArray()
{
    std::cout << "!!Distructor!!" << std::endl;
    delete[]arr;
    arr = nullptr;

}
