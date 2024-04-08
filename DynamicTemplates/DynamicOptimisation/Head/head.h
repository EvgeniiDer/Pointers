#ifndef HEAD_H_
#define HEAD_H_
#include<iostream>
#include<string>
#include<ctime>
#include<type_traits>
#include<iomanip>

template<typename T>
class TwoDimensionalArray
{
    private:
        int colm;
        int row;
        T** dimArray;
        T** allocate(const int&, const int&);//Allocate memory for two-dimensional array
        void clear(T** , const int&); //Free memory, delete two-dimensional array(We use a distructor in Class)
        void copy(T**, T**, const int&, const int&);//Copy from second two dimensional array to first;
    public:
        TwoDimensionalArray() : colm(0), row(0), dimArray(nullptr){}
        TwoDimensionalArray(const int _row, const int _colm): colm(_colm)
                                                             ,row(_row)
                                                             , dimArray(new T*[_row])
        {
            for(int i = 0; i < _row; i++)
                dimArray[i] = new T[_colm];
        }
        TwoDimensionalArray<T> &operator=(const TwoDimensionalArray<T>& arg) 
        {
            T** buffer = new T*[arg.row];
            for(int i = 0; i < arg.row; i++)
                buffer[i] = new T[arg.colm];
            for(int i = 0; i < arg.row; i++)
                for(int j = 0; j < arg.colm; j++)
                    buffer[i][j] = arg.dimArray[i][j];
            for(int i = 0; i < row; i++)
                delete[]dimArray[i];
            delete[]dimArray;
            dimArray = buffer;
            row = arg.row;
            colm = arg.colm;
            return *this;
        } 
        int getRow()const;
        int getColm()const;
        void fill_array(); // Fill array with random integer
        void print()const;
        void push_row_back(bool); // add row to back of tow-dimensional array
        void push_row_front(bool);// add row of two dimensional array to front
        bool insert_row(const int&, bool);// isert a row by index into a two dimensional array
        void pop_row_back();// pop row from back of two dimensional array
        void pop_row_front();// pop row from front of two dimensional array
        bool erase_row(const int&);// erase row by index from a two dimensional array
        void push_col_back(bool); // add column to the back of two dimensional array
        void push_col_front(bool); //add column to the front of two dimensional array
        bool insert_col(const int&, bool); //insert a column by index into a two dimensional array
        void pop_col_back();// pop a column from the back of two dimensional array
        void pop_col_front();// pop a column from the front of two dimensional array
        bool erase_col(const int&); // erase a column by the index from a two dimensonal array 
        ~TwoDimensionalArray(){
            for(int i = 0; i < row; i++)
                delete[]dimArray[i];
            delete[]dimArray;
        }

};

template<typename T>
int TwoDimensionalArray<T>::getRow()const
{
    return row;
}
template<typename T>
int TwoDimensionalArray<T>::getColm()const
{
    return colm;
}
template<typename T>
void TwoDimensionalArray<T>::fill_array() 
{
    srand(std::time(0));
    if(std::is_same_v<T, int>)
        {
            for(int i = 0; i < row; i++)
                for(int j = 0; j < colm; j++)
                    dimArray[i][j] = std::rand() %  100;
        }
    else if(std::is_same_v<T, double>)
        {
            for(int i = 0; i < row; i++)
                for(int j = 0; j < colm; j++)
                    dimArray[i][j] = static_cast<double>(std::rand()) / RAND_MAX * 100;
        }
    else if(std::is_same_v<T, float>)
        {
            for(int i = 0; i < row; i++)
                for(int j = 0; j < colm; j++)
                    dimArray[i][j] = static_cast<float>(std::rand()) / RAND_MAX * 100;
        }
    else if(std::is_same_v<T, char>)
        {
            
            for(int i = 0; i < row; i++)
                for(int j = 0; j < colm; j++)
                {
                    int random = rand() % 2;
                    if(random == 0)
                        dimArray[i][j] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                    else
                        dimArray[i][j] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                }
        }
}
template<typename T>
void TwoDimensionalArray<T>::print()const
{
    std::cout << std::endl;
    for(int i = 0; i < row; i++)
        {   
            for(int j = 0; j < colm; j++)
            {       
                   if(std::is_same_v<T, int>)
                   {
                        std::cout << "\t" <<  dimArray[i][j] << "\t";
                   }
                   else if(std::is_same_v<T, double>)
                   {
                        std::cout <<"\t" << std::fixed << std::setprecision(2) << dimArray[i][j] << "\t";
                   }
                   else if(std::is_same_v<T, char>)
                   {
                        std::cout << "\t" << dimArray[i][j] << "\t";
                   }
                   else if(std::is_same_v<T, float>)
                   {
                       std::cout <<"\t" << std::fixed << std::setprecision(2) << dimArray[i][j] << "\t";
                   }
            }
            std::cout << std::endl;
        }
    std::cout << "Total Row: " << TwoDimensionalArray::getRow() <<
                 " | Total Column: " << TwoDimensionalArray::getColm() << std::endl;
    std::cout << std::endl;
}
template<typename T>
T** TwoDimensionalArray<T>::allocate(const int& _row, const int& _colm)
{
    T** arr = new T*[_row];
    for(int i = 0 ; i < _row; i++)
        arr[i] = new T[_colm];
    return arr;
}
template<typename T>
void TwoDimensionalArray<T>::clear(T** _array, const int& _row)
{
    for(int i = 0; i < _row; i++)
        delete[]_array[i];
    delete[]_array;
    _array = nullptr;
}
template<typename T>
void TwoDimensionalArray<T>::copy(T** _array1, T** _array2, const int& _row, const int& _colm)
{
    for(int i = 0; i < _row; i++)
        for(int j = 0; j < _colm; j++)
            _array1[i][j] = _array2[i][j];
}
template<typename T>
void TwoDimensionalArray<T>::push_row_back(bool b)
{
    int bufferRow = row + 1;
    T** buffer = TwoDimensionalArray::allocate(bufferRow , colm);
    TwoDimensionalArray::copy(buffer, dimArray, row, colm);
    TwoDimensionalArray::clear(dimArray, row);
    if(std::is_same_v<T, int>)
        {
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
        }
    else if(std::is_same_v<T, double>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[bufferRow - 1][i] = 99.99;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[bufferRow - 1][i] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[bufferRow - 1][i] = 99.99;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[bufferRow - 1][i] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[bufferRow - 1][i] = 'Z';
                }
            else{
                    for(int i = 0; i < colm; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[bufferRow - 1][i] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[bufferRow - 1][i] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
    row = bufferRow;
    dimArray = buffer;
}
template<typename T>
void TwoDimensionalArray<T>::push_row_front(bool b)
{
    int bufferRow = row + 1;
    T** buffer = TwoDimensionalArray::allocate(bufferRow , colm);
    for(int i = 0; i < row; i++)    
        for(int j = 0; j < colm; j++)
            buffer[i + 1][j] = dimArray[i][j];   
    if(std::is_same_v<T, int>)
        {
         if(b == true)
                {  
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = 1111;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = rand() % 100;
                }  
        }
    else if(std::is_same_v<T, double>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = 11.11;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = 11.11;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[0][i] = 'A';
                }
            else{
                    for(int i = 0; i < colm; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[0][i] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[0][i] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = buffer;
}
template<typename T>
bool TwoDimensionalArray<T>::insert_row(const int& position, bool b)
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
    else
    {
        int bufferRow = row + 1;
        T** buffer = TwoDimensionalArray::allocate(bufferRow, colm);   
        for(int i = 0; i < realPosition; i++)
            for(int j = 0; j < colm; j++)
                buffer[i][j] = dimArray[i][j];
        if(std::is_same_v<T, int>)
            {
                if(b == true)
                    {  
                        for(int i = 0; i < colm; i++)
                            buffer[realPosition][i] = 5555;
                    }
                else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = rand() % 100;
                }  
            }
        else if(std::is_same_v<T, double>)
            {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = 55.55;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = 55.5;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < colm; i++)
                        buffer[realPosition][i] = 'H';
                }
            else{
                    for(int i = 0; i < colm; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[realPosition][i] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[realPosition][i] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
        for(int i = realPosition + 1; i < bufferRow; i++)
            for(int j = 0; j < colm; j++)
                {
                    buffer[i][j] = dimArray[i - 1][j];
                }
        TwoDimensionalArray::clear(dimArray, row);
        row = bufferRow;
        dimArray = buffer;
        return true;
    }
}
template<typename T>
void TwoDimensionalArray<T>::pop_row_back()
{
    int bufferRow = row - 1;
    T** buffer = TwoDimensionalArray::allocate(bufferRow, colm);
    TwoDimensionalArray::copy(buffer, dimArray, bufferRow, colm);
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = buffer;
}
template<typename T>
void TwoDimensionalArray<T>::pop_row_front()
{
    int bufferRow = row - 1;
    T** buffer = TwoDimensionalArray::allocate(bufferRow, colm);
    for(int i = 1; i < row; i++)
        for(int j = 0; j < colm; j++)
            {
                buffer[i - 1][j] = dimArray[i ][j];
            }
    TwoDimensionalArray::clear(dimArray, row);
    row = bufferRow;
    dimArray = buffer;
}
template<typename T>
bool TwoDimensionalArray<T>::erase_row(const int& position)
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
        T** buffer = TwoDimensionalArray::allocate(bufferRow, colm);   
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
        dimArray = buffer;
        return true;
    }

}
template<typename T>
void TwoDimensionalArray<T>::push_col_back(bool b)
{
    int bufferColm = colm + 1;
    T** buffer = TwoDimensionalArray::allocate(row, bufferColm);
    TwoDimensionalArray::copy(buffer, dimArray, row, bufferColm);
    if(std::is_same_v<T, int>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = 9999;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = rand() % 100;
                }  
        }
    else if(std::is_same_v<T, double>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = 99.99;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = 99.99;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][bufferColm - 1] = 'Z';
                }
            else{
                    for(int i = 0; i < row; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[i][bufferColm - 1] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[i][bufferColm - 1] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
    colm = bufferColm;
    dimArray = buffer;
}
template<typename T>
void TwoDimensionalArray<T>::push_col_front(bool b)
{
    int bufferColm = colm + 1;
    T** buffer = TwoDimensionalArray::allocate(row, colm);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < colm; j++)
            buffer[i][j + 1] = dimArray[i][j];
    if(std::is_same_v<T, int>)
        {
            if(b == true)
                {  
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = 1111;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = rand() % 100;
                }  
        }
    else if(std::is_same_v<T, double>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = 11.11;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = 11.11;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][0] = 'A';
                }
            else{
                    for(int i = 0; i < row; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[i][0] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[i][0] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
    TwoDimensionalArray::clear(dimArray, row);
    colm = bufferColm;
    dimArray = buffer;
}
template<typename T>
bool TwoDimensionalArray<T>::insert_col(const int& position, bool b)
{
    int realPosition = position -1;
    if(realPosition < 0 || realPosition > colm)
        {
            return false;
        }
    else if(realPosition == 0)
    {
        TwoDimensionalArray::push_col_front(b);
        return true;
    }
    else
    {
        int bufferColm = colm + 1;
        T** buffer = TwoDimensionalArray::allocate(row, bufferColm);   
        for(int i = 0; i < row; i++)
            for(int j = 0; j < realPosition; j++)
                buffer[i][j] = dimArray[i][j];

        if(std::is_same_v<T, int>)
            {
                if(b == true)
                    {  
                        for(int i = 0; i < row; i++)
                            buffer[i][realPosition] = 5555;
                    }
                else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = rand() % 100;
                }  
            }
        else if(std::is_same_v<T, double>)
            {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = 55.55;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = static_cast<double>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, float>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = 55.5;
                }
            else{
                    std::srand(time(0));
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = static_cast<float>(std::rand()) / RAND_MAX * 100;
                }  
        }
        else if(std::is_same_v<T, char>)
        {
            if(b == true)
                {
                    for(int i = 0; i < row; i++)
                        buffer[i][realPosition] = 'H';
                }
            else{
                    for(int i = 0; i < row; i++)
                    {
                        int random = rand() % 2;
                        if(random == 0)
                            buffer[i][realPosition] = static_cast<char>(rand() % (90 - 65 + 1) + 65);
                        else
                            buffer[i][realPosition] =static_cast<char>(rand() % (122 - 97 + 1) + 97);
                    }
                }  
        }
        for(int i = 0; i < row; i++)
            for(int j = realPosition; j < colm; j++)
                {
                    buffer[i][j + 1] = dimArray[i][j];
                }
        TwoDimensionalArray::clear(dimArray, row);
        colm = bufferColm;
        dimArray = buffer;
        return true;
    }
}
template<typename T>
void TwoDimensionalArray<T>::pop_col_back()
{
    int bufferColm = colm - 1;
    T** buffer = TwoDimensionalArray::allocate(row, bufferColm);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < bufferColm; j++)
            buffer[i][j] = dimArray[i][j];
    TwoDimensionalArray::clear(dimArray, row); 
    colm = bufferColm;
    dimArray = buffer;      
}
template<typename T>
void TwoDimensionalArray<T>::pop_col_front()
{
    int bufferColm = colm - 1;
    T** buffer = TwoDimensionalArray::allocate(row, bufferColm);
    for(int i = 0; i < row; i++)
        for(int j = 1; j < colm; j++)
            {
                buffer[i][j - 1] = dimArray[i ][j];
            }
    TwoDimensionalArray::clear(dimArray, row);
    colm = bufferColm;
    dimArray = buffer;

}
template<typename T>
bool TwoDimensionalArray<T>::erase_col(const int& position)
{
    int realPosition = position -1;
    if(realPosition < 0 || realPosition >= colm)
        {
            return false;
        }
    else if(realPosition == 0)
    {
        TwoDimensionalArray::pop_col_front();
        return true;
    }
    else if(realPosition == colm - 1)
    {
        TwoDimensionalArray::pop_col_back();
        return true;
    }
    else
    {
        int bufferColm = colm - 1;
        T** buffer = TwoDimensionalArray::allocate(row, bufferColm);   
        for(int i = 0; i < row; i++)
            for(int j = 0; j < realPosition; j++)
                buffer[i][j] = dimArray[i][j];

        for(int i = 0; i < row; i++)
            for(int j = realPosition; j < bufferColm; j++)
                {
                    buffer[i][j] = dimArray[i][j + 1];
                }
        TwoDimensionalArray::clear(dimArray, row);
        colm = bufferColm;
        dimArray = buffer;
        return true;
    }  
}


#endif