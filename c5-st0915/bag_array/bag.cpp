#include "bag.h"
#include <cstring>

using namespace std;

const int INIT_SIZE = 2;

Bag::Bag()
{
	size = INIT_SIZE;
	count = 0;
	data = new int[size];
}

Bag::Bag(const Bag& b)
{
	size = b.size;
	count = b.count;
	data = new int[size];
	memcpy(data, b.data, count*sizeof(int));
}

Bag& Bag::operator=(const Bag& b)
{
	if(this != &b)
	{
		delete [] data;
		size = b.size;
		count = b.count;
		data = new int[size];
		memcpy(data, b.data, count*sizeof(int));
	}
	return *this;
}

Bag::~Bag()
{
	delete [] data;
}

void Bag::resize(int newsize)
{
	int *newdata = new int[newsize];
	memcpy(newdata, data, count*sizeof(int));
	delete [] data;
	size = newsize;
	data = newdata;
}

void Bag::vloz(int a)
{
	if(size < count+1)
		resize(size*2);
	data[count++] = a;
}

void Bag::odeber(int a)
{
	int i = find(a);
	if(i >= count)
		return;
	if(size/2 > count-1 && size/2 >= INIT_SIZE)
		resize(size/2);
	data[i] = data[count-1];
	count--;
}

int Bag::find(int a)
{
	int i;
	for(i = 0; i < count; i++)
		if(data[i] == a)
			break;
	return i;
}

bool Bag::jeTam(int a)
{
	return find(a) < count;
}

Bag& Bag::operator+=(int a)
{
	vloz(a);
	return *this;
}

ostream& operator<<(std::ostream& os, const Bag& b)
{
	for(int i = 0; i < b.count; i++)
		os << b.data[i] << " ";
	return os;
}
