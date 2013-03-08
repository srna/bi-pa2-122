#ifndef __QUEUE_H_
#define __QUEUE_H_

class Queue
{
	struct Item
	{
		int val;
		Item *next;
		Item(int v, Item *n);
	};
	Item *head, *tail;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	void push(int v);
	int pop();
};

#endif
