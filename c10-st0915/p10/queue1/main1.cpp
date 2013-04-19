// main1.cpp

#include <iostream>
#include <cstdlib>

#include "queue1.h"

using namespace std;


int main() {
  try {
    Queue<int> q;
    q.add(1); q.add(2); q.add(3); q.remove(); q.remove();
    for (int i=10; i<=35; i++)
      q.add(i);
    Queue<int> r;
    r = q;
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.remove();
    }
    cout << endl;
    while (!r.empty()) {
        cout << r.front() << ' ';
        r.remove();
    }
    cout << endl;
  }
  catch (const char* s) {
    cout << "chyba: " << s << endl;
  }
  //system("PAUSE");
  return 0;
}
        

