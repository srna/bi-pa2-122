// main1a.cpp
// skonci chybou

#include <iostream>
#include <cstdlib>

#include "queue1.h"

using namespace std;

int main1a() {
  try {
    Queue<int> q;
    q.add(1); q.add(2); q.add(3); q.remove(); q.remove();
    for (int i=1; i<=40/*Queue<int>::M*/; i++)
      q.add(i);
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.remove();
    }
    cout << endl;
  }
  catch (const char* s) {
    cout << "chyba: " << s << endl;
  }
  //system("PAUSE");
  return 0;
}
        

