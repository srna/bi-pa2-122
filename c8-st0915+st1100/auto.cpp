#include <iostream>
#include <string>
#include "auto.h"

using namespace std;

Auto::Auto( const string & spz, 
	  		const int & rokVyroby ) : 
			spz(spz),
			rokVyroby(rokVyroby) {}
string Auto::getSpz() const
{
	return spz;
}
int Auto::getRokVyroby() const
{
	return rokVyroby;
}
ostream & Auto::vypis ( ostream & os ) const
{
	os << "SPZ: " << spz << ", Rok vyroby: " << 
		rokVyroby;
	return os;
}