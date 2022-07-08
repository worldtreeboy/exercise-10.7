//CREATED BY LIM XI QIANG
//ON 7th july 2022
//C++ DEITEL HOW TO PROGRAM exercise 10.7

#include "DoubleSubscriptedArray.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>



using namespace std;
//default constructor
doubleSubscriptedArray :: doubleSubscriptedArray (int row1, int column1)
                 : size{((row1 > 0 && column1 > 0) ? static_cast<size_t>(row1 * column1) :
                        throw invalid_argument{"row and column must be greater than 0"})},
                   ptr{new int*[row1]{}},
                   row{row1},
                   column{column1}
                   {
                       //constructor body
                       for(int i = 0; i < row; i++)
                       {
                           ptr[i] = new int[column];
                       }

                       //intialize everything to 0
                       for(int i = 0; i < row; i++)
                       {
                           for(int j = 0; j < column; j++)
                           {
                               *(ptr[i] + j) = 0;
                           }
                       }
                   }

//copy constructor
doubleSubscriptedArray :: doubleSubscriptedArray (const doubleSubscriptedArray& arrayCopy)
                : size{arrayCopy.size}, ptr{new int*[arrayCopy.row]}, row{arrayCopy.row}, column{arrayCopy.column}
                {
                    //constructor body
                    for(int i = 0; i < row; i++)
                    {
                        ptr[i] = new int[arrayCopy.column];
                        for(int j = 0; j < arrayCopy.column; j++)
                        {
                            *(ptr[i] + j) = *(arrayCopy.ptr[i] + j);  //copy into object
                        }
                    }
                }

//destructor
doubleSubscriptedArray::~doubleSubscriptedArray()
{
    for(int i = 0; i < row; i++)
    {
        delete ptr[i];
    }
    delete[] ptr;  //release pointer-based array space
    ptr = nullptr;  //set to nullptr
}


//return number of elements of array
size_t doubleSubscriptedArray :: getSize() const
{
    return size;
}

//overloaded assignment operator;
//consst return avoids; (a1 = a2) = a3
const doubleSubscriptedArray& doubleSubscriptedArray::operator=(const doubleSubscriptedArray& rhs)
{
    if(&rhs != this)
    {
        //avoids self assignemnt
        //for arrays of different sizes, deallocate original
        //left side Array, then allocate new left side Array
        if(size != rhs.size)
        {
            delete [] ptr;  //release space
            ptr = nullptr;
            size = rhs.size;
            row = rhs.row;
            column = rhs.column;
            ptr = new int*[row];

            for(int i = 0; i < row; i++)
            {
                ptr[i] = new int[column];
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < column; j++)
            {
                *(ptr[i] + j) = *(rhs.ptr[i] + j);
            }
        }
    }

    return *this;
}


bool doubleSubscriptedArray::operator==(const doubleSubscriptedArray& rhs) const
{
    if(size != rhs.size || row != rhs.row || column != rhs.column)
    {
        return false;
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            if(*(ptr[i] + j) != *(rhs.ptr[i] + j))
            {
                return false;
            }
        }
    }

    return true;
}

int& doubleSubscriptedArray::operator()(int row1, int column1)
{
    //check out of range
    if(row1 < 0 || column1 < 0 || column1 > column || row1 > row || row1 * column1 > size)
    {
        throw out_of_range("parameter out of range1");
    }

    return *(ptr[row1] + column1);

}

int doubleSubscriptedArray::operator()(int row1, int column1) const
{
    //check out of range
    if(row1 < 0 || column1 < 0 || column1 > column || row1 > row || row1 * column1 > size)
    {
        throw out_of_range("parameter out of range2");
    }

    return *(ptr[row1] + column1);

}

//overloaded input operator for class doubleSubscriptedArray
istream& operator >> (istream& input, doubleSubscriptedArray& a)
{
    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            input >> *(a.ptr[i] + j);
        }
    }

    return input;
}

//overloaded output operator for class doubleSubscriptedArray
ostream& operator<<(ostream& output, const doubleSubscriptedArray& a)
{
    //output private ptr-based array
    for(int i = 0; i < a.row; i++)
    {
        for(int j = 0; j < a.column; j++)
        {
            output <<  *(a.ptr[i] + j) << "   ";
        }
        cout << endl;
    }
    return output;
}



