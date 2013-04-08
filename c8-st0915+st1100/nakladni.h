#ifndef _NAKLADNI_H_oirufoiseu7987h
#define _NAKLADNI_H_oirufoiseu7987h

#include <iostream>
#include <string>
#include "auto.h"

class Nakladni : public Auto 
{
	int nosnost;
public:
	Nakladni ( const std::string & spz, 
		  	 const int & rokVyroby,
		  	 const int & nosnost );
	int getNosnost() const;
	std::ostream & vypis ( std::ostream & os ) const;
};

#endif //_NAKLADNI_H_oirufoiseu7987h