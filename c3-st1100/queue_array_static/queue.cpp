#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
	Arr = new int[size];
	head = tail = -1;
}

Queue::~Queue()
{
	delete [] Arr;
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
		Arr[tail] = v;
	}
	// If the queue is full
	else if(count()+1 > size)
	{
		cout << "Queue is full. Cannot push." << endl;
		return;
	}
	// Normal condition
	else
	{
		tail = (tail+1) % size;
		Arr[tail] = v;
	}
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
		v = Arr[head];
		head = tail = -1;
	}
	// If normal
	else
	{
		v = Arr[head];
		head = (head+1)%size;
	}
	//cout << "[D] count: " << count() << endl;
	return v;
}

int Queue::count() const
{
	int c = tail - head + 1;
	if (c<0)
		c += size;
	return c;
}
