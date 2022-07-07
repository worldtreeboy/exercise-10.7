//CREATED BY LIM XI QIANG
//ON 7th july 2022
//C++ DEITEL HOW TO PROGRAM exercise 10.7

#include <iostream>
#include <iomanip>
#include "DoubleSubscriptedArray.h"

using namespace std;

int main()
{
    doubleSubscriptedArray a1{6, 3}; //18 element array. 6 row 3 column
    doubleSubscriptedArray a2; //8x8 element by default

    //Create Array a3 using a1 as an initializer; print size and contents


    //print a1 size and contents
    cout << "size of DoubleSubscriptedArray a1 is: " << a1.getSize()
         << "\nArray after initialization: " << a1;

    cout << "size of DoubleSubscriptedArray a2 is: " << a2.getSize()
         << "\nArray after initialization: " << a2;

    cout << "Enter 30 integers: " << endl;
    cin >> a1 >> a2;

    cout << "\nAfter input, the DoubleSubscriptedArray contain:\n"
         << "a1: " << a1
         << "a2: " << a2;

    //use overloaded inequality(!=) operator
    cout << "\nEvaluating: a1 != a2" << endl;

    if(a1 != a2)
    {
        cout << "a1 and a2 are not equal" << endl;
    }


     doubleSubscriptedArray a3{a1};
    cout << "\nSize of DoubleSubscriptedArray a3 is " << a3.getSize()
         << "\nDoubleSubscriptedArray  after initialization: " << a3;

    //use overloaded assignment (=) operator
    cout << "\nAssigning a2 to a1: " << endl;
    a1 = a2; //note target Array is smaller

    cout << "a1: \n" << a1 << endl;
    cout << "a2: \n" << a2 << endl;

    //use overloaded equality(==) operator
    cout << "\nEvaluating: a1 == a2" << endl;

    if(a1 == a2)
    {
         cout << "a1 and a2 are equal" << endl;
    }

    cout << "a2(2,2): " << a2(2,2) << endl;
    cout << "a2(2,2) modified to 1000" << endl;
    a2(2,2) = 1000;
    cout << "after modification: " << endl;
    cout << "a2(2,2): " << a2(2,2) << endl;

}







