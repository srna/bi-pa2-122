#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(float real, float imag){
	Re = real;
	Im = imag;
}

float Complex::abs(){
	return sqrt(Re*Re + Im*Im);
}

std::ostream& operator << (std::ostream& os, const Complex& c){
	os <<c.Re<<"+"<<c.Im<<"i";
	return os;
}

Complex operator - (const Complex& a, const Complex& b)
{
	return Complex(a.Re-b.Re, a.Im-b.Im);
}

Complex operator +(const Complex& x, const Complex& y) {
	return Complex(x.Re+y.Re, x.Im+y.Im);
}

bool operator== (const Complex& lhs, const Complex& rhs)
{
	return lhs.Re == rhs.Re && lhs.Im == rhs.Im;
}
bool operator!= (const Complex& lhs, const Complex& rhs)
{
	return !(lhs == rhs);
}

