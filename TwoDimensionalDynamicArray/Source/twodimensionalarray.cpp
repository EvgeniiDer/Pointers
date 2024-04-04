#include"../Head/twodimensionalarray.h"


int TwoDimensionalArray::getRow()const
{
    return row;
}
int TwoDimensionalArray::getColm()const
{
    return colm;
}
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
    std::cout << "Total Row: " << TwoDimensionalArray::getRow() <<
                 " | Total Column: " << TwoDimensionalArray::getColm() << std::endl;
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
void TwoDimensionalArray::push_row_front(bool b)
{
    int bufferRow = row + 1;
    int **buffer = TwoDimensionalArray::allocate(bufferRow, colm);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < colm; j++)
            {
                buffer[i + 1][j] = dimArray[i][j];
            }
    if(b == true)
    {
        for(int i = 0; i < colm; i++)
            buffer[0][i] = 1111;
    }
    else{
            srand(time(0));
            for(int i = 0; i < colm; i++)
            buffer[0][i] = rand() % 100;
    }
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = TwoDimensionalArray::allocate(row, colm);
    TwoDimensionalArray::copy(dimArray, buffer, row, colm);
    TwoDimensionalArray::clear(buffer, row);
}
bool TwoDimensionalArray::insert_row(const int& position, bool b)
{
    int realPosition = position -1;
    if(realPosition < 0 || realPosition >= row)
        {
            return false;
        }
    else if(realPosition == 0)
    {
        TwoDimensionalArray::push_row_front(b);
        return true;
    }
    else if(realPosition == row - 1)
    {
        TwoDimensionalArray::push_row_back(b);
        return true;
    }
    else
    {
        int bufferRow = row + 1;
        int** buffer = TwoDimensionalArray::allocate(bufferRow, colm);   
        for(int i = 0; i < realPosition; i++)
            for(int j = 0; j < colm; j++)
                buffer[i][j] = dimArray[i][j];
        if(b == true)
            {
                for(int i = 0; i < colm; i++)
                    buffer[realPosition][i] = 5555;
            }
        else
            {
                srand(time(0));
                for(int i = 0; i < colm; i++)
                    buffer[realPosition][i] = rand() % 100;
            }
        for(int i = realPosition + 1; i < bufferRow; i++)
            for(int j = 0; j < colm; j++)
                {
                    buffer[i][j] = dimArray[i - 1][j];
                }
        TwoDimensionalArray::clear(dimArray, row);
        row = bufferRow;
        dimArray = TwoDimensionalArray::allocate(row, colm);
        dimArray = buffer;
        //!!!!!Another method below!!!!
        //TwoDimensionalArray::copy(dimArray, buffer, row, colm);
        //TwoDimensionalArray::clear(buffer, row);
        return true;
    }
}
void TwoDimensionalArray::pop_row_back()
{
    int bufferRow = row - 1;
    int** buffer = TwoDimensionalArray::allocate(bufferRow, colm);
    TwoDimensionalArray::copy(buffer, dimArray, bufferRow, colm);
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = TwoDimensionalArray::allocate(row, colm);
    dimArray = buffer;
}
void TwoDimensionalArray::pop_row_front()
{
    int bufferRow = row - 1;
    int** buffer = TwoDimensionalArray::allocate(bufferRow, colm);
    for(int i = 1; i < row; i++)
        for(int j = 0; j < colm; j++)
            {
                buffer[i - 1][j] = dimArray[i ][j];
            }
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = TwoDimensionalArray::allocate(row, colm);
    dimArray = buffer;
}
bool TwoDimensionalArray::erase_row(const int& position)
{
    int realPosition = position -1;
    if(realPosition < 0 || realPosition >= row)
        {
            return false;
        }
    else if(realPosition == 0)
    {
        TwoDimensionalArray::pop_row_front();
        return true;
    }
    else if(realPosition == row - 1)
    {
        TwoDimensionalArray::pop_row_back();
        return true;
    }
    else
    {
        int bufferRow = row - 1;
        int** buffer = TwoDimensionalArray::allocate(bufferRow, colm);   
        for(int i = 0; i < realPosition; i++)
            for(int j = 0; j < colm; j++)
                buffer[i][j] = dimArray[i][j];

        for(int i = realPosition; i < bufferRow; i++)
            for(int j = 0; j < colm; j++)
                {
                    buffer[i][j] = dimArray[i + 1][j];
                }
        TwoDimensionalArray::clear(dimArray, row);
        row = bufferRow;
        dimArray = TwoDimensionalArray::allocate(row, colm);
        dimArray = buffer;
        //!!!!!Another method below!!!!
        //TwoDimensionalArray::copy(dimArray, buffer, row, colm);
        //TwoDimensionalArray::clear(buffer, row);
        return true;
    }

}