/* list.cpp */

#include "list.h"

List::List() { begin = tail = mark = new Node; } 

List::~List() {
  Node *p;
  while (begin) { p  = begin; begin = begin->next; delete p; }
}

bool List::empty() const { return begin == tail; }

bool List::atBegin() const { return mark==begin; }

bool List::atEnd() const { return mark==tail; }

void List::toBegin() { mark = begin; }

void List::toEnd() { mark = tail; }

void List::toNext() {
  if (atEnd()) return;
  mark = mark->next;
}

void List::toPrev() {
  if (atBegin()) return;
  mark = mark->prev;
}

void List::insert(T x) {
  Node *p = new Node(x, mark);
  mark->prev = p;
  if (atBegin()) 
    begin = p;
  else
    p->prev->next = p;
}

void List::remove() {
  if (atEnd()) return;
  Node *p = mark;
  mark->next->prev = mark->prev;
  if (atBegin()) begin = mark->next;
  else           mark->prev->next = mark->next;
  mark = mark->next;
  delete p;
}
    
void List::removePrev() {
  if (atBegin()) return;
  toPrev();
  remove();
}

bool List::read(T &x) const {
  if (atEnd()) return false;
  x = mark->val;
  return true;
}
  
std::ostream& operator<<(std::ostream& s, const List& lst) {
  s << '[';
  List::Node *p = lst.begin;
  while (p) {
    if (p==lst.mark) s << '|';
    if (p!=lst.tail) s << p->val << ' ';
    p = p->next;
  }
  s << ']';
  return s;
}

