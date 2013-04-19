// array.h

#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>

template <class Elem>
class Array {
public:
  explicit Array(int=10);
  Array(const Array&);
  ~Array();
  int length() const {return len;}
  Elem& operator[](int);
  const Elem& operator[](int) const;
  Array& operator=(const Array&);
  void extend(int);
private:
  Elem* array;
  int len;
  void copy(const Array&);
};

template <class Elem>
Array<Elem>::Array(int l) {
  len = l;
  array = new Elem[len];
  for (int i=0; i<len; i++)
    array[i] = Elem();
  std::cout<<"pole zalozeno "<<array<<" delka: "<<len<<std::endl;
}

template <class Elem>
Array<Elem>::Array(const Array<Elem>& a) {
  copy(a);
}

template <class Elem>
Array<Elem>::~Array() {
  std::cout<<"pole "<<array<<" destruovano"<<std::endl;
  delete [] array;
  len = 0;
}

template <class Elem>
Elem& Array<Elem>::operator[](int ind) {
  if (ind<0 || ind>=len)
    throw "nedovoleny index";
  return array[ind];
}
  
template <class Elem>
const Elem& Array<Elem>::operator[](int ind) const {
  if (ind<0 || ind>=len)
    throw "nedovoleny index";
  return array[ind];
}

template <class Elem>
Array<Elem>& Array<Elem>::operator=(const Array<Elem>& a) {
  if (this==&a) return *this;
  std::cout<<"pole "<<array<<" zruseno "<<std::endl;
  delete [] array;
  copy(a);
  return *this;
}

template <class Elem>
void Array<Elem>::extend(int nl) {
  if (nl<=len) return;
  Elem *narray = new Elem[nl];
  for (int i=0; i<len; i++) narray[i] = array[i];
  for (int i=len; i<nl; i++) narray[i] = Elem();
  std::cout<<"pole "<<array<<" extendovano do "<<narray
           <<" delka: "<<nl<<std::endl;
  delete [] array;
  array = narray;
  len = nl;
}

template <class Elem>
void Array<Elem>::copy(const Array<Elem>& a) {
  len = a.len;
  array = new Elem[len];
  for (int i=0; i<len; i++)
    array[i] = a.array[i];
  std::cout<<"pole "<<a.array<<" okopirovano do "<<array<<std::endl;
}

#endif
