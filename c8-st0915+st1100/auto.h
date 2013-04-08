#ifndef _AUTO_H_hkjhh876876kjh
#define _AUTO_H_hkjhh876876kjh

#include <iostream>
#include <string>

class Auto
{
	std::string spz;
	int rokVyroby;

public:
	Auto( const std::string & spz, 
		  const int & rokVyroby );
	std::string getSpz() const;
	int getRokVyroby() const;
	virtual std::ostream & vypis ( std::ostream & os ) const;
};

#endif //_AUTO_H_hkjhh876876kjh