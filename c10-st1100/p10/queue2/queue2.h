// queue2.h

#ifndef _QUEUE2_
#define _QUEUE2_

// implementace fronty pomoci pole
// s dynamicky danym poctem prvku

template <class T>
class Queue {
public:
  explicit Queue(int = 40);
  ~Queue();
  void add(const T&);
  T front() const;
  void remove();
  bool empty() const;
private:
  int celo, volny, pocet;
  int M;
  T* pole;
  void del();
  void cp(const Queue& q);
public:
  Queue(const Queue&);              // nelze kopirujici konstruktor
  Queue& operator=(const Queue&);   // nelze prirazeni - vadi v main2b
};

template <class T>
void Queue<T>::cp(const Queue& q)
{
  celo = q.celo; volny = q.volny; pocet = q.pocet;
  M = q.M;
  pole = new T[M];
  for(int i = 0; i < pocet; i++)
    pole[(i+celo)%M] = q.pole[(i+celo)%M];
}

template <class T>
void Queue<T>::del()
{
  delete [] pole;
  pole = 0;
}

template <class T>
Queue<T>::Queue(const Queue& q)
{
  cp(q);
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{
  if(this != &q)
  {
    del();
    cp(q);
  }
  return *this;
}

template <class T>
Queue<T>::Queue(int m) {
  celo = volny = pocet = 0;
  M = m;
  pole = new T[M];
}

template <class T>
Queue<T>::~Queue() {
  del();
}

template <class T>
void Queue<T>::add(const T& x) {
  if (pocet==M) throw "plna fronta";
  pole[volny++] = x; pocet++;
  if (volny>=M) volny = 0;
}

template <class T>
T Queue<T>::front() const {
  if (empty()) throw "cteni z prazdne fronty";
  return pole[celo];
}

template <class T>
void Queue<T>::remove() {
  if (empty()) return;
  celo++; pocet--;
  if (celo>=M) celo = 0;
}

template <class T>
bool Queue<T>::empty() const {
  return pocet==0;
}

#endif