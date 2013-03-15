#include "bag.h"
#include <cstring>

using namespace std;

#define INIT_SIZE 2

//const int INIT_SIZE = 2;

Bag::Bag(){
	size = INIT_SIZE;
	count=0;
	data = new int [size];
}

Bag::~Bag(){
	delete [] data;
}

Bag::Bag(const Bag& b){
	size=b.size;
	count=b.count;
	data= new int[size];
	//zkopirovat obsah
	memcpy(data,b.data,count*sizeof(int));
}

void Bag::vloz(const int& i){
	if(size <count+1){
		resize(size*2);
	}
	data[count++] = i;
}

void Bag::resize(int newsize){
	int *newdata = new int[newsize];
	memcpy(newdata,data,count*sizeof(int));
	delete [] data;
	data=newdata;
	size= newsize;
}

void Bag::odeber(const int& i){
	//muzeme prvek odebrat?
	int index=find(i);
	if(index >=count){
		return;
	}
	//zmensit pamet
	//1.staci nam polovina? 2.muzeme zmensovat?
	if(size/2 > count-1 && size/2 >=INIT_SIZE)
		resize(size/2);
	
	//odeber prvek
	data[index]=data[count-1];
	//zmensit count
	count --;
}

int Bag::find(const int& i){
	
	for(int in=0;in<count;in++){
		if(data[in]==i)return in;
	}
	return count;
}


bool Bag::jeTam(const int& i){
	return find(i)<count;
}

Bag& Bag::operator+=(int i){
	vloz(i);
	return *this;
}

Bag& Bag::operator=(const Bag& b){
	//neni to ten samy?
	if(this != &b){
		//smaz vlastni prvky
		delete [] data;
		size=b.size;
		count=b.count;
		data= new int[size];
		//zkopirovat obsah
		memcpy(data,b.data,count*sizeof(int));
	}
	return *this;
}

ostream& operator<<(ostream& os, const Bag& b){
	for(int i=0;i<b.count;i++){
		os << b.data[i] << " ";
	}
	return os;
}



















