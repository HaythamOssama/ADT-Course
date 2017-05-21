//============================================================================
// Name        : Lecture2Codes.cpp
// Author      : Haytham Osama
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Implementing Complex Class
//============================================================================

#include "Complex.h"
// Complex.h includes iostream and using namespace std so there's no need to add them here again
// Adding them isn't considered as an error but it increases code size

int main()
{
    // Define 2 objects from class "Complex"
    Complex ob1, ob2;

    // Input Real/Imaginary of ob1 from user
    ob1.ReadComplex();

    // Set Real/Imaginary of ob2 from parameters
    ob2.SetReal(1);
    ob2.SetImag(-1);

    // Adds "ob2" real & imaginary parts to ob1 real & imaginary parts and stores result to ob1 real & imaginary parts
    ob1.Add(ob2);
    cout << "Add Function\n";
    // Print Results of Addition
    cout << "Real :" << ob1.GetReal() << " Imaginary :" << ob1.GetImag() << endl
         << endl;

    // Subtracts "ob2" real & imaginary parts from ob1 real & imaginary parts and stores result to ob1 real & imaginary parts
    ob1.Subtract(ob2);
    cout << "Subtract Function\n";
    // Print Results of Subtraction
    cout << "Real :" << ob1.GetReal() << " Imaginary :" << ob1.GetImag() << endl
         << endl;

    // Multiplies "ob2" real & imaginary parts with ob1 real & imaginary parts and stores result to ob1 real & imaginary parts
    ob1.Multiply(ob2);
    cout << "Multiply Function\n";
    // Print Results of Multiplication
    cout << "Real :" << ob1.GetReal() << " Imaginary :" << ob1.GetImag() << endl
         << endl;

    // Divides "ob2" real & imaginary parts over ob1 real & imaginary parts and stores result to ob1 real & imaginary parts
    ob1.Divide(ob2);
    cout << "Divide Function\n";
    // Print Results of Division
    cout << "Real :" << ob1.GetReal() << " Imaginary :" << ob1.GetImag() << endl
         << endl;

    // Print Magnitude and Phase of ob1's real and imaginary part
    cout << "Magnitude: " << ob1.GetMagnitude() << " - Phase: " << ob1.GetPhase();
    return 0;
}
