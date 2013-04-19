// main2.cpp
// test prirazeni - nelze pouzit, je to spatne

#include <iostream>
#include <cstdlib>

#include "queue2.h"

using namespace std;

int main2b() {
  try {
    Queue<int> q(10);
    q.add(1); q.add(2); q.add(3); 
    Queue<int> q1;
    q1 = q;
    q.remove(); q.remove(); q.remove();
    for (int i=10; i<=18; i++)
      q.add(i);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.remove();
    }
    cout << endl;
    while (!q1.empty()) {
        cout << q1.front() << ' ';
        q1.remove();
    }
    cout << endl;    
  }
  catch (const char* s) {
    cout << "chyba: " << s << endl;
  }
  //system("PAUSE");
  return 0;
}
        

