#ifndef _OSOBNI_H_oirufoiseu7987h
#define _OSOBNI_H_oirufoiseu7987h

#include <iostream>
#include <string>
#include "auto.h"

class Osobni : public Auto 
{
	int pocetOsob;
public:
	Osobni ( const std::string & spz, 
		  	 const int & rokVyroby,
		  	 const int & pocetOsob );
	int getPocetOsob() const;
	std::ostream & vypis ( std::ostream & os ) const;
};

#endif //_OSOBNI_H_oirufoiseu7987h