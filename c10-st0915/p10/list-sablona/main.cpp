/* main.cpp */

#include <cstdlib>

#include "list.h"

using namespace std;

List<int> szn;

int menu(void) {
  cout << "seznam operaci" << endl;
  cout << " 0. Ukoncit program\n";
  cout << " 1. insert\n";
  cout << " 2. remove\n";
  cout << " 3. removePrev\n";
  cout << " 4. toNext\n";
  cout << " 5. toPrev\n";
  cout << " 6. toBegin\n";
  cout << " 7. toEnd\n";
  cout << " 8. empty\n";
  cout << " 9. atBegin\n";
  cout << "10. atEnd\n";
  cout << "11. read\n";
  cout << "Zadej cislo operace" << endl;
  int op;
  do {
    cin >> op;
    if (op<0 || op>11) {
      cout << "operaci jsi zadal spatne, znovu" << endl;
      op = -1;
    }  
    cin.ignore(100, '\n');
  } while (op<0);
  return op;
}
    
int main() {
  int op;
  int x;
  do {
    cout << szn << endl;
    op = menu();
    switch (op) {
      case 1: cin >> x; szn.insert(x); break;
      case 2: szn.remove(); break;
      case 3: szn.removePrev(); break;
      case 4: szn.toNext(); break;
      case 5: szn.toPrev(); break;
      case 6: szn.toBegin(); break;
      case 7: szn.toEnd(); break;
      case 8: cout << szn.empty() << endl; break;
      case 9: cout << szn.atBegin() << endl; break;
      case 10: cout << szn.atEnd() << endl; break;
      case 11: if (szn.read(x)) cout << x << endl; break;
    }
  } while (op>0); 
  //system("PAUSE");
  return 0;
}
