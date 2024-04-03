#ifndef TWODIMENSIONALARRAY_H_
#define TWODIMENSIONALARRAY_H_
#include<iostream>

class TwoDimensionalArray
{
    private:
        int colm;
        int row;
        int **dimArray;
        void print(int**, const int&, const int&)const;
        int** allocate(const int&, const int&);//Allocate memory for two-dimensional array
        void clear(int** , const int&); //Free memory, delete two-dimensional array(We use a distructor in Class)
        void copy(int**, int**, const int&, const int&);//Copy from second two dimensional array to first;
    public:
        TwoDimensionalArray() : colm(0), row(0), dimArray(nullptr){}
        TwoDimensionalArray(const int _row, const int _colm): colm(_colm)
                                                             ,row(_row)
                                                             , dimArray(new int*[_row])
        {
            for(int i = 0; i < _row; i++)
                dimArray[i] = new int[_colm];
        }        
        int getRow()const;
        int getColm()const;
        void fill_array(); // Fill array with random integer
        void print()const; 
        void push_row_back(bool); // add row to back of tow-dimensional array
        void push_row_front(bool);// add row of two dimensional array to front
        
        bool insert_row(const int&, bool);// isert a row by index into a two dimensional array
        void pop_row_back(void);// pop row from back of two dimensional array
        void pop_row_front(void);// pop row from front of two dimensional array
        void erase_row(void);// erase row by index from a two dimensional array
        void push_col_back(void); // add column to the back of two dimensional array
        void push_col_front(void); //add column to the front of two dimensional array
        void insert_col(void); //insert a column by index into a two dimensional array
        void pop_col_back(void);// pop a column from the back of two dimensional array
        void pop_col_front(void);// pop a column from the front of two dimensional array
        void erase_col(void); // erase a column by the index from a two dimensonal array
        ~TwoDimensionalArray(){
            for(int i = 0; i < row; i++)
                delete[]dimArray[i];
            delete[]dimArray;
        }

};





#endif