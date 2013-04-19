// main3.cpp

#include <cstdlib>

#include "queue3.h"

using namespace std;

int main() {
  try {
    Queue<int> q;
    q.add(1); q.add(2); q.add(3); q.remove(); q.remove();
    for (int i=10; i<=35; i++)
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
        

