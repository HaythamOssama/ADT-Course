//============================================================================
// Name        : Lecture4Codes.cpp
// Author      : Haytham Osama
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Constructors and Destructors
//============================================================================

#include "Complex.h"

int main()
{

    /* Difference between this code and "Lecture 3 codes":
	 * 	1. Constructors and Destructors prototypes in h file.
	 * 	2. Constructors and Destructors implementation in cpp file.
	 * 	3. cout << "Add is called" is added in Add function
	 * */

    // define two objects from Complex class;
    Complex ob1; // Constructor 1 is called
    Complex ob2(10.5, 4.5); // Constructor 2 is called
    Complex ob3(4.5); // Constructor 3 is called

    // For Code in Page (7) : Uncomment from here
    //	ob1.Add(ob2);
    //	cout << "Real= " << ob1.GetReal() << " Imaginary= " << ob1.GetImag() << endl;
    // to this part

    // For code in Page (9): Follow these steps:
    //	1. In Complex.h  , go to Add Function and replace (Complex object) to (const Complex &object)
    //	2. In Complex.cpp, go to Add Function and replace (Complex object) to (const Complex &object)
    //  3. Uncomment from here
    //	ob1.Add(ob2);
    //	cout << "Real= " << ob1.GetReal() << " Imaginary= " << ob1.GetImag() << endl;
    // to here
    return 0;
}
