#ifndef __QUEUE_H_
#define __QUEUE_H_

class Queue
{
	static const int size = 4;
	int count() const;
	int head, tail;
	int *Arr;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void push(int v);
	int  pop();
};

#endif
