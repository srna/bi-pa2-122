#include <iostream>
#include <string>
#include "auto.h"
#include "nakladni.h"

Nakladni::Nakladni ( const std::string & spz, 
			  	 const int & rokVyroby,
			  	 const int & nosnost ) : 
			Auto( spz, rokVyroby ), 
			nosnost( nosnost ) {}

int Nakladni::getNosnost() const
{
	return nosnost;
}
std::ostream & Nakladni::vypis ( std::ostream & os ) const
{
	Auto::vypis(os) << ", Nosnost: " << nosnost;
	return os;
}