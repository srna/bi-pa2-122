#ifndef __QUEUE_H_
#define __QUEUE_H_

class Queue
{
	int size;
	int count() const;
	int head, tail;
	int *arr;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void push(int v);
	int  pop();
};

#endif
