#include <iostream>
#include "citac.h"

using namespace std;

int Citac::hodn()
{
	return _hodn;
}

void Citac::inc()
{
	_hodn ++ ;
}

void Citac::dec()
{
	_hodn -- ;
}

void Citac::reset()
{
	_hodn = 0 ;
}
