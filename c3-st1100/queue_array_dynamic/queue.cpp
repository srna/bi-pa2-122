#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

Queue::Queue()
{
	size = 4;
	arr = new int[size];
	head = tail = -1;
}

Queue::~Queue()
{
	delete [] arr;
}

bool Queue::isEmpty() const
{
	return head == -1;
}

void Queue::push(int v)
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
		int *new_arr = new int[size*2];
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

int Queue::pop()
{
	int v = 0;
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
		int *new_arr = new int[size/2];
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

int Queue::count() const
{
	if(isEmpty())
		return 0;
	int c = tail - head + 1;
	if (c<0)
		c += size;
	return c;
}
