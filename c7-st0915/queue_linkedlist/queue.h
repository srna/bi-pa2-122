#ifndef __QUEUE_H_
#define __QUEUE_H_

template<class T>
class Queue
{
	struct Item
	{
		T val;
		Item *next;
		Item(const T& v, Item *n);
	};
	Item *head, *tail;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void push(const T& v);
	T pop();
};

#endif
