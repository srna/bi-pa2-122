#include <iostream>
#include "queue.h"

Queue::Item::Item(int v, Item *n)
{
	val = v;
	next = n;
}

Queue::Queue()
{
	head = tail = new Item(0, NULL);
}

Queue::~Queue()
{
	while(!isEmpty())
		pop();
	delete head;
}

bool Queue::isEmpty() const
{
	return head == tail;
}

void Queue::push(int v)
{
	tail->val = v;
	tail->next = new Item(0, NULL);
	tail = tail->next;
}

int Queue::pop()
{
	if(isEmpty())
		return 0;
	Item *tmp = head;
	head = head->next;
	int v = tmp->val;
	delete tmp;
	return v;
}
