#ifndef TWODIMENSIONALARRAY_H_
#define TWODIMENSIONALARRAY_H_
#include</Users/aleksandrsapran/cpp-search-server/Pointers/DynamicMemory/Head/OneDimensionalArray.h>

class TwoDimensionalArray: public MyArray
{
    private:
    int row;
    int **demArray;
    public:
        TwoDimensionalArray() : MyArray(), row(0){
            
        }
        TwoDimensionalArray(const int, const int);
        void allocate(void);//Allocate memory for two-dimensional array
        void clear(void);// Free memory, delete two-dimensional array
        void push_row_back(void); // add row to back of tow-dimensional array
        void push_row_front(void);// add row of two dimensional array to front
        void insert_row(void);// isert a row by index into a two dimensional array

        void pop_row_back(void);// pop row from back of two dimensional array
        void pop_row_front(void);// pop row from front of two dimensional array
        void erase_row(void);// erase row by index from a two dimensional array

        void push_col_back(void); // add column to the back of two dimensional array
        void push_col_front(void); //add column to the front of two dimensional array
        void insert_col(void); //insert a column by index into a two dimensional array

        void pop_col_back(void);// pop a column from the back of two dimensional array
        void pop_col_front(void);// pop a column from the front of two dimensional array
        void erase_col(void); // erase a column by the index from a two dimensonal array
        ~TwoDimensionalArray(){};

};





#endif