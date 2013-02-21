#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(int real, int imag){
	Re = real;
	Im = imag;
}

float Complex::abs(){
	return sqrt(Re*Re + Im*Im);
}

void Complex::print(){
	std::cout << std::hex <<Re<<"+"<<Im<<"i";
}


Complex Complex::add(const Complex& b) const
{
	return Complex(getRe()+b.getRe(), getIm()+b.getIm());
}

Complex Complex::diff(const Complex& b) const
{
	return Complex(getRe()-b.getRe(), getIm()-b.getIm());
}
