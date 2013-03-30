#ifndef __COMPLEX_H_
#define __COMPLEX_H_

#include <iostream>

class Complex{
	float Re;
	float Im;
public:
	Complex(float real=0, float imag=0);
	float getRe() const {return Re;}
	float getIm() const {return Im;}
	float abs();

	friend bool operator==(const Complex &a, const Complex &b);
	friend bool operator!=(const Complex &a, const Complex &b);

	friend std::ostream& operator << (std::ostream& os, const Complex& c);
	friend Complex operator+(const Complex &a, const Complex &b);
	friend Complex operator-(const Complex &a, const Complex &b);

	friend const Complex& operator+=(Complex& lhs, const Complex& rhs);
};

#endif