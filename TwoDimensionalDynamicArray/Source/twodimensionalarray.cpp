#include"../Head/twodimensionalarray.h"


void TwoDimensionalArray::fill_array() 
{
    srand(std::time(0));
    for(int i = 0; i < row; i++)
        for(int j = 0; j < colm; j++)
            dimArray[i][j] = std::rand() %  100;
            
}
void TwoDimensionalArray::print()const
{
    std::cout << std::endl;
    for(int i = 0; i < row; i++)
        {   
            for(int j = 0; j < colm; j++)
            {
                   std::cout << "\t" <<  dimArray[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    std::cout << std::endl;
}
void TwoDimensionalArray::print(int** arr, const int& _row, const int& _colm)const
{
    for(int i = 0; i < _row; i++)
    {
        std::cout << std::endl;
        for(int j = 0; j < _colm; j++)
        {
            std::cout << "\t" << arr[i][j] << "\t";
        }
    }
    std::cout << '\n';
}
int ** TwoDimensionalArray::allocate(const int& _row, const int& _colm)
{
    int** arr = new int*[_row];
    for(int i = 0 ; i < _row; i++)
        arr[i] = new int[_colm];
    return arr;
}
void TwoDimensionalArray::clear(int** _array, const int& _row)
{
    for(int i = 0; i < _row; i++)
        delete[]_array[i];
    delete[]_array;
    _array = nullptr;
}
void TwoDimensionalArray::copy(int** _array1, int** _array2, const int& _row, const int& _colm)
{
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _colm; j++)
            _array1[i][j] = _array2[i][j];
}
void TwoDimensionalArray::push_row_back(bool b)
{
    int bufferRow = row + 1;
    int** buffer = TwoDimensionalArray::allocate(bufferRow , colm);
    TwoDimensionalArray::copy(buffer, dimArray, row, colm);
    TwoDimensionalArray::clear(dimArray, row);
    if(b == true)
        {
            for(int i = 0; i < colm; i++)
                buffer[bufferRow - 1][i] = 9999;
        }
    else{
            std::srand(time(0));
            for(int i = 0; i < colm; i++)
                buffer[bufferRow - 1][i] = rand() % 100;
    }
    row = bufferRow;
    dimArray = TwoDimensionalArray::allocate(row, colm);
    TwoDimensionalArray::copy(dimArray, buffer, row, colm);
    TwoDimensionalArray::clear(buffer, row);
}
