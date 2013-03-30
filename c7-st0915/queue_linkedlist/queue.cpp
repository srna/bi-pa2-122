#include <iostream>
#include "queue.h"

template<class T>
Queue<T>::Item::Item(const T& v, Item *n)
{
	val = v;
	next = n;
}

template<class T>
Queue<T>::Queue()
{
	head = tail = NULL;
}

template<class T>
Queue<T>::~Queue()
{
	while(!isEmpty())
		pop();
	delete head;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return head == NULL;
}

template<class T>
void Queue<T>::push(const T& v)
{
	if(isEmpty())
		head = tail = new Item(v, NULL);
	else
	{
		tail->next = new Item(v, NULL);
		tail = tail->next;
	}
}

template<class T>
T Queue<T>::pop()
{
	if(isEmpty())
		throw "Cannot pop from empty queue.";
	Item *tmp = head;
	head = head->next;
	if(head == NULL)
		tail = NULL;
	T v = tmp->val;
	delete tmp;
	return v;
}


void __helper_template_Queue()
{
	Queue<int> a;
	a.push(5);
	Queue<float> b;
	b.push(5.5);
}

