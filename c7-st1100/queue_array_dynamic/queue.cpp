#include "queue.h"
#include "../cplx/complex.h"
#include <iostream>
#include <cmath>
using namespace std;

template<class T>
Queue<T>::Queue()
{
	size = 4;
	arr = new T[size];
	head = tail = -1;
}

template<class T>
Queue<T>::~Queue()
{
	delete [] arr;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return head == -1;
}

template<class T>
void Queue<T>::push(const T& v)
{
	// If the queue is empty
	if(isEmpty() && size > 0)
	{
		head = tail = 0;
		arr[tail] = v;
		return;
	}
	// If the queue is full
	if(count()+1 > size)
	{
		T *new_arr = new T[size*2];
		for(int i = 0; i < count(); i++)
			new_arr[i] = arr[(i+head)%size];
		delete [] arr;
		arr = new_arr;
		size *= 2;
		tail = count()-1;
		head = 0;
	}
	// Normal condition
	tail = (tail+1) % size;
	arr[tail] = v;
	//cout << "[D] count: " << count() << endl;
}

template<class T>
T Queue<T>::pop()
{
	T v = 0;
	// If the queue is empty
	if(isEmpty())
	{
		cout << "Queue is empty. Cannot pop." << endl;
	}
	// If count == 1
	if(count() == 1)
	{
		v = arr[head];
		head = tail = -1;
	}
	// If normal
	else
	{
		v = arr[head];
		head = (head+1)%size;
	}
	if(size > 4 && count() <= size/2)
	{
		T *new_arr = new T[size/2];
		for(int i = 0; i < count(); i++)
			new_arr[i] = arr[(i+head)%size];
		delete [] arr;
		arr = new_arr;
		size /= 2;
		tail = count()-1;
		head = 0;
	}
	return v;
}

template<class T>
int Queue<T>::count() const
{
	if(isEmpty())
		return 0;
	int c = tail - head + 1;
	if (c<0)
		c += size;
	return c;
}

void __helper_Queue()
{
	Queue<int> a;
	a.push(5);
	a.pop();
	Queue<float> b;
	b.push(4.4);
	b.pop();
	Queue<Complex> c;
	c.push(Complex(1,1));
	c.pop();
}
