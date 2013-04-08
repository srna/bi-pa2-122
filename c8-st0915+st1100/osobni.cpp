#include <iostream>
#include <string>
#include "auto.h"
#include "osobni.h"

Osobni::Osobni ( const std::string & spz, 
			  	 const int & rokVyroby,
			  	 const int & pocetOsob ) : 
			Auto( spz, rokVyroby ), 
			pocetOsob( pocetOsob ) {}

int Osobni::getPocetOsob() const
{
	return pocetOsob;
}
std::ostream & Osobni::vypis ( std::ostream & os ) const
{
	Auto::vypis(os) << ", Pocet osob: " << pocetOsob;
	return os;
}