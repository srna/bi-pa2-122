#ifndef __QUEUE_H_
#define __QUEUE_H_

template<class T>
class Queue
{
	int size;
	int count() const;
	int head, tail;
	T *arr;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void push(const T& v);
	T  pop();
};

#endif
