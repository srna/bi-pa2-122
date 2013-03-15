#ifndef BAG_H 

#define BAG_H
#include <iostream>

class Bag
{

private:
	int *data;
	int size,count;
	void resize(int newsize);
	int find(const int& i);

public:
	Bag();
	Bag (const Bag& b);
	~Bag();
	void vloz(const int& i);
	void odeber(const int& i);
	bool jeTam(const int& i);

	friend std::ostream& operator<<(std::ostream& os, const Bag& b);
	Bag& operator+=(int i);
	Bag& operator=(const Bag& b);
	
};

#endif 