#ifndef __COMPLEX_H_
#define __COMPLEX_H_
#include <iostream>
class Complex{
	float Re;
	float Im;
public:
	Complex(float real=0, float imag=0);
	float getRe() const {return Re;}
	float abs();
	float getIm() const {return Im;}

	friend std::ostream& operator << (std::ostream& os, 
		const Complex& c);

	friend Complex operator +(const Complex& x, const Complex& y);
	friend Complex operator -(const Complex& x, const Complex& y);

	friend bool operator== (const Complex& lhs, const Complex& rhs);
	friend bool operator!= (const Complex& lhs, const Complex& rhs);
};

#endif
