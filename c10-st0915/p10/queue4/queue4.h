// queue4.h 
// implementace fronty pomoci spojoveho seznamu

#include <iostream>

void pis(const char *txt);

template <class T>
class Queue {
public:
  Queue();
  Queue(const Queue& q)          { cop(q); }
  Queue& operator=(const Queue&);
  ~Queue()                       { del(); }
  void add(const T&);
  T front() const;
  void remove();
  bool empty() const;
private:
  struct Item {
    T val;
    Item *next;
    Item() {next = NULL;}
  };
  Item *celo, *volny;
  void del();
  void cop(const Queue&);
};

template <class T>
void Queue<T>::del() {
  Item *pom;
  while (celo) {
    pom = celo;
    celo = celo->next;
    delete pom;
  }
}

template <class T>
void Queue<T>::cop(const Queue& q) {
  Item *pq=q.celo, *pp;
  celo=volny=new Item;
  while (pq!=q.volny) {
    volny->val=pq->val;    
    pp=new Item;
    volny->next=pp; 
    volny=pp;
    pq=pq->next;
  }      
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& q) {
  if (this!= &q) {
    del();
    cop(q);
  }  
  return *this;
}

template <class T>
Queue<T>::Queue() {
  celo = volny = new Item;
}

template <class T>
void Queue<T>::add(const T& x) {
  volny->val = x;
  volny->next = new Item;
  volny = volny->next;
}

template <class T>
T Queue<T>::front() const {
  if (empty()) throw "cteni z prazdne fronty";
  return celo->val;
}

template <class T>
void Queue<T>::remove() {
  if (empty()) return;
  Item *pom = celo;
  celo = celo->next;
  delete pom;
}

template <class T>
bool Queue<T>::empty() const {
  return celo==volny;
}

