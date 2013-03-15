#ifndef __BAG_H_
#define __BAG_H_
#include <iostream>

class Bag
{
private:
	int *data;
	int size, count;
	void resize(int newsize);
	int find(int a);
public:
	Bag();
	Bag(const Bag& from);
	~Bag();
	void vloz(int a);
	void odeber(int a);
	bool jeTam(int a);
	Bag& operator+=(int a);
	Bag& operator=(const Bag& from);
	friend std::ostream& operator<<(std::ostream& os, const Bag& b);
};

#endif
