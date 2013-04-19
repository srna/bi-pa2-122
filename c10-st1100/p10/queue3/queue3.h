// queue3.h

#ifndef _QUEUE3_
#define _QUEUE3_

// implementace fronty rozsiritelnym polem

#include "array.h"

template <class T>
class Queue {
public:
    Queue();
    ~Queue() {std::cout<<"fronta destruovana"<<std::endl;}
    bool empty() const {return pocet==0;}
    void add(const T&);
    T front() const;
    void remove();
private:
    Array<T> pole;
    int celo;
    int volny;
    int pocet;
};

template <class T>        
Queue<T>::Queue() {pocet=0; celo=0; volny=0;}

template <class T>        
void Queue<T>::add(const T& x) {
    if (pocet==pole.length()) {
       pole.extend(2*pocet);
       for (int i=0; i<celo; i++)
          pole[pocet+i] = pole[i];
       volny += pocet;
    } 
    pole[volny] = x;
    pocet++;
    volny = (volny+1) % pole.length();
}

template <class T>        
T Queue<T>::front() const {
    if (empty()) throw "cteni z prazdne fronty";
    return pole[celo];
}

template <class T>        
void Queue<T>::remove() {
    if (empty()) return;
    celo = (celo+1) % pole.length();
    pocet--;
}
 
#endif        
