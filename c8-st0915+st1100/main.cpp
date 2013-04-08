#include <iostream>
#include "auto.h"
#include "osobni.h"
#include "nakladni.h"

using namespace std;

int main() {
	Auto a("1A1 1234", 2012);
	Osobni o("1B1 1234", 2011, 5);
	Nakladni n("1C1 1234", 2010, 10);

	const int v = 3;
	Auto* p[v];
	p[0] = &a;
	p[1] = &o;
	p[2] = &n;

	for (int i = 0; i < v; ++i)
		p[i]->vypis(cout) << endl;
}