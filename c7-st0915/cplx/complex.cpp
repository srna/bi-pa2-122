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

std::ostream& operator << (std::ostream& os, const Complex& c)
{
	os << c.Re << " + " << c.Im << "i";
	return os;
}

Complex operator+(const Complex &a, const Complex &b)
{
	return Complex(a.Re+b.Re,a.Im+b.Im);
}
Complex operator-(const Complex &a, const Complex &b)
{
	return Complex(a.Re-b.Re,a.Im-b.Im);
}

const Complex& operator+=(Complex& lhs, const Complex& rhs)
{
	lhs.Re += rhs.Re;
	lhs.Im += rhs.Im;
	return const_cast<const Complex&>(lhs);
}

bool operator==(const Complex &a, const Complex &b)
{
	return ((a.Re==b.Re) && (a.Im==b.Im));
}
	bool operator!=(const Complex &a, const Complex &b)
	{
		return !(a==b);
	}

