#include "../Head/head.h"


MyArray::MyArray(int _ELEM) : ELEM{_ELEM},
                              arr{new int[_ELEM]}
                            {
        std::cout << "!!Constructor!!" << std::endl;
        std::srand(std::time(0));
        for(int i = 0; i < ELEM; i++)
            {
                arr[i] = std::rand() % 100;
            } 
                       }
MyArray::MyArray(const MyArray& arg) : ELEM(arg.ELEM),
                                       arr(new int[arg.ELEM])
{
    for(int i = 0 ; i < ELEM; i++)
    {
        arr[i] = arg[i];
    }
}
MyArray &MyArray::operator=(const MyArray & arg)
{
    int *buffer = new int[arg.ELEM];
    std::copy(arg.arr, arg.arr + arg.ELEM, buffer);
    delete[]arr;
    arr = nullptr;
    arr = buffer;
    ELEM = arg.ELEM;
    return *this;
}
MyArray::MyArray(MyArray &&arg) : ELEM(arg.ELEM), arr(arg.arr)
{
    arg.ELEM = 0;
    arg.arr = nullptr;

}
MyArray &MyArray::operator=(MyArray &&arg)
{
    delete[]arr;
    arr = nullptr;
    arr = arg.arr;
    ELEM = arg.ELEM;
    arg.arr = nullptr;
    arg.ELEM = 0;
    return *this;

}
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
    
    int *newArr = new int[ELEM + 1];
    newArr[0] = addFront;
    for(int i = 0; i < ELEM; i++)
    {
        newArr[i + 1] = arr[i];
    }
    delete[]arr;
    arr = nullptr;
    ELEM++;
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

    if(_position <= 0 || _position > ELEM)
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

bool MyArray::erase(const int& _position)
{
    if(_position == 0 || _position > ELEM)
    {
        return false;
    }
    int position = _position - 1;
    int newElement = ELEM;
    std::cout << "Elem: " << newElement << std::endl;
    int *newArray = new int[--newElement];
    for(int i = 0; i < position ; i++)
    {
        newArray[i] = arr[i];
    }
    for(int i = position + 1; i < ELEM; i++)
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
    return true;
}
MyArray::~MyArray()
{
    std::cout << "!!Distructor!!" << std::endl;
    delete[]arr;
    arr = nullptr;

}
