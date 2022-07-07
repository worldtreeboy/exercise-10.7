//CREATED BY LIM XI QIANG
//ON 7th july 2022
//C++ DEITEL HOW TO PROGRAM exercise 10.7

#include <iostream>
#include <iomanip>
#include <stdexcept>

//CREATED BY LIM XI QIANG
//ON 7th july 2022
//C++ DEITEL HOW TO PROGRAM exercise 10.7

class doubleSubscriptedArray
{
    friend std::ostream& operator<<(std::ostream&, const doubleSubscriptedArray&);
    friend std::istream& operator>>(std::istream&, doubleSubscriptedArray&);
public:

    //default constructor
    explicit doubleSubscriptedArray(int row = 4, int column = 3);

    //copy constructor
    doubleSubscriptedArray (const doubleSubscriptedArray&);

    //destructor
    ~doubleSubscriptedArray();

    size_t getSize() const; //return size

    //assignment operator
    const doubleSubscriptedArray& operator=(const doubleSubscriptedArray&);


    //equality operator
    bool operator==(const doubleSubscriptedArray&) const;

    bool operator!=(const doubleSubscriptedArray& right) const
    {
        return ! (*this == right); //invokes Array::operator==
    }

    //function call operator for non-const objects return modifiable lvalue
    int& operator()(int, int = 0);

    //function call operator for const objects return r value
    int operator()(int, int = 0) const;


private:
    size_t size;
    int** ptr;
    int row;
    int column;
};
