/*
 * Complex.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: haytham
 */
#include "Complex.h"

// Sets real and imaginary parts to 0
Complex::Complex()
{
    cout << "Constructor 1 is called\n";
    real = 0.0;
    imag = 0.0;
}

// Sets real part to arg_real and imag part to arg_imag
Complex::Complex(double arg_real, double arg_imag)
{
    cout << "Constructor 2 is called\n";
    real = arg_real;
    imag = arg_imag;
}

// Sets real and imaginary part to num
Complex::Complex(double num)
{
    cout << "Constructor 3 is called\n";
    real = num;
    imag = num;
}

Complex::~Complex()
{
    cout << "Destructor is called.\n";
}

bool Complex::ReadComplex()
{
    // Take input from user and save it to real and imaginary parts of "this" object
    cout << "Enter Real Part\n";
    cin >> real;
    cout << "Enter Imaginary Part\n";
    cin >> imag;
    return true;
}

double Complex::GetReal()
{
    return real;
}

double Complex::GetImag()
{
    return imag;
}

void Complex::SetReal(double arg_real)
{
    real = arg_real;
}

void Complex::SetImag(double arg_imag)
{
    imag = arg_imag;
}

void Complex::Add(Complex object)
{

    //real = real + object.GetReal();
    real = real + object.real;
    // imag = imag + object.GetImag();
    imag = imag + object.imag;
    cout << "Add is called\n";
}

void Complex::Subtract(Complex object)
{
    real = real - object.GetReal();
    // or real = real + object.real;
    imag = imag - object.GetImag();
    // or imag = imag + object.imag;
}

void Complex::Multiply(Complex object)
{
    // (a+bi)(c+di)= (ac-bd) + i (bc + ad)

    double temp_real, temp_imag;
    temp_real = real * object.real - imag * object.imag;
    temp_imag = imag * object.real + real * object.imag;

    real = temp_real;
    imag = temp_imag;
}

void Complex::Divide(Complex object)
{
    // Multiply by object's conjugate
    double temp_real, temp_imag;

    temp_real = (real * object.real + imag * object.imag) / (object.real * object.real + object.imag * object.imag);
    temp_imag = (imag * object.real - real * object.imag) / (object.real * object.real + object.imag * object.imag);

    real = temp_real;
    imag = temp_imag;
}

double Complex::GetMagnitude()
{
    return sqrt(real * real + imag * imag);
}

double Complex::GetPhase()
{
    // Returns tan inverse of complex number in radians, so it's converted to degrees
    return atan2(imag, real) * 180 / PI;
}
