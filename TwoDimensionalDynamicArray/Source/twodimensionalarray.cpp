#include"../Head/twodimensionalarray.h"


void TwoDimensionalArray::allocate(const int _row, const int _colm)
{
    row = _row;
    dimArray = new int*[_row];
    for(int i = 0; i < _row; i++)
    {
        dimArray[i] = &MyArray(_colm).FillOneDimensionalArray();
    }
   
    for(int i = 0; i < _row; i++)
        {
            for(int j = 0; j < 8; j++)
                std::cout << dimArray[i][j] << " ";
            std::cout << std::endl;
        }
            
}
void TwoDimensionalArray::print()const
{
 
}
