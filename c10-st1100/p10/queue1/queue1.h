// queue1.h

#ifndef _QUEUE1_
#define _QUEUE1_

// implementace fronty pomoci pole
// se staticky danym poctem prvku

template <class T>
class Queue {
public:
  Queue();
  void add(const T&);
  T front() const;
  void remove();
  bool empty() const;
private:
  //enum {M = 40};
  static const int M=40; // tak to jde take
  int celo, volny, pocet;
  T pole[M];
};

template <class T>
Queue<T>::Queue() {
  celo = volny = pocet = 0;
}

template <class T>
void Queue<T>::add(const T& x) {
  if (pocet==M) throw "plna fronta";
  pole[volny++] = x; pocet++;
  if (volny>=M) volny = 0;
}

template <class T>
T Queue<T>::front() const {
  if (pocet==0) throw "cteni z prazdne fronty";
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