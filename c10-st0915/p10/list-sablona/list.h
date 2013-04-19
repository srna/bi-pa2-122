/* list.h */

#ifndef _LIST_
#define _LIST_

#include <iostream>

template <class T>
class List {
public:
  List();
  ~List();
  void insert(T);       // vloz pred kurzor
  void remove();        // odstran prvek na kurzoru
  void removePrev();    // odtstran prvek pred kurzorem
  void toNext();        // kurzor na dalsi prvek
  void toPrev();        // kurzor na predchozi prvek
  void toBegin();       // kurzor na zacatek
  void toEnd();         // kurzor na konec
  bool empty()   const; // je seznam prazdny?
  bool atBegin() const; // je kurzor na zacatku?
  bool atEnd()   const; // je kurzor na konci
  bool read(T&)  const; // cteni z pozice kurzoru
  std::ostream& print(std::ostream&) const;  // metoda pro vypis

private:
  struct Node {
    Node *next, *prev;
    T val;
    Node(T x, Node *n) : val(x), next(n), prev(n->prev) {} // n nesmi byt NULL
    Node() : next(0), prev(0) {}
  };
  Node *begin;
  Node *tail;
  Node *mark;
  List(const List &);
  List& operator=(const List&);
};


template <class T>
List<T>::List() { begin = tail = mark = new Node; } 

template <class T>
List<T>::~List() {
  Node *p;
  while (begin) {
    p  = begin;
    begin = begin->next;
    delete p;
  }
}

template <class T>
bool List<T>::empty() const { return begin == tail; }

template <class T>
bool List<T>::atBegin() const { return mark==begin; }

template <class T>
bool List<T>::atEnd() const { return mark==tail; }

template <class T>
void List<T>::toBegin() { mark = begin; }

template <class T>
void List<T>::toEnd() { mark = tail; }

template <class T>
void List<T>::toNext() {
  if (atEnd()) return;
  mark = mark->next;
}

template <class T>
void List<T>::toPrev() {
  if (atBegin()) return;
  mark = mark->prev;
}

template <class T>
void List<T>::insert(T x) {
  Node *p = new Node(x, mark);
  mark->prev = p;
  if (atBegin()) 
    begin = p;
  else
    p->prev->next = p;
}

template <class T>
void List<T>::remove() {
  if (atEnd()) return;
  Node *p = mark;
  mark->next->prev = mark->prev;
  if (atBegin())
    begin = mark->next;
  else
    mark->prev->next = mark->next;
  mark = mark->next;
  delete p;
}
    
template <class T>
void List<T>::removePrev() {
  if (atBegin()) return;
  toPrev();
  remove();
}

template <class T>
bool List<T>::read(T &x) const {
  if (atEnd()) return false;
  x = mark->val;
  return true;
}
  
template <class T>
std::ostream& List<T>::print(std::ostream& s) const {
  s << '[';
  Node *p = begin;
  while (p) {
    if (p==mark) s << '|';
    if (p!=tail) s << p->val << ' ';
    p = p->next;
  }
  s << ']';
  return s;
}
   
template <class T>
std::ostream& operator<<(std::ostream& s, const List<T>& lst) {
  return lst.print(s);
}


#endif

