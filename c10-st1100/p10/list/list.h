/* list.h */

#ifndef _LIST_
#define _LIST_

#include <iostream>

typedef int T;

class List {
public:
  List();
  ~List();
  void insert(T);      // vloz pred kurzor
  void remove();       // odstran prvek na kurzoru
  void removePrev();   // odtstran prvek pred kurzorem
  void toNext();       // kurzor na dalsi prvek
  void toPrev();       // kurzor na predchozi prvek
  void toBegin();      // kurzor na zacatek
  void toEnd();        // kurzor na konec
  bool empty()  const; // je seznam prazdny?
  bool atBegin()const; // je kurzor na zacatku?
  bool atEnd()  const; // je kurzor na konci
  bool read(T&) const; // cteni z pozice kurzoru
  friend std::ostream& operator<<(std::ostream&, const List&);
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

#endif
