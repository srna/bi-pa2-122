/* main.cpp */
#include <iostream>
using namespace std;
#include "complex.h"

int main(void) {
	Complex x(1,1), y(2,2), z; 

	float a = 1.2;
	z = a;
	cout << z << endl;
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	z = x + y;
	cout << "x+y=" << z << endl;
	z = x - y;
	cout << "x-y=" << z << endl; 
	cout << "x+1=" << x+1 << endl; 
	cout << "2+x=" << 2+x << endl; 

	cout << "z=" << (z += 5) << endl;
	cout << "z=" << z << endl;

	Complex td = a;
	cout << (td==a ? "stejne":"ruzne") << endl;
	return 0; 
}