#include <iostream>
#include "citac.h"

using namespace std;

int main()
{
	Citac c;
	

	cout << "Hodnota: " << c.hodn() << endl;
	c.inc();
	cout << "Hodnota: " << c.hodn() << endl;
	c.dec();
	cout << "Hodnota: " << c.hodn() << endl;
	for (int i = 0; i < 1000; i++) c.inc();
	cout << "Hodnota: " << c.hodn() << endl;
	c.reset();
	cout << "Hodnota: " << c.hodn() << endl;
}
