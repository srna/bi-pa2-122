#ifndef __COMPLEX_H_
#define __COMPLEX_H_
class Complex{
	int Re;
	int Im;
public:
	Complex(int real=0, int imag=0);
	int getRe() const {return Re;}
	int getIm() const {return Im;}
	float abs();
	void print();

	Complex add(const Complex& b) const;
	Complex diff(const Complex& b) const;
};



#endif