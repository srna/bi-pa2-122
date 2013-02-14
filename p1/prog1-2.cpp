/* prog1-2.cpp */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int x = -10;
  cout << "dekadicky " << x << endl;
  cout << "celkem 10 znaku " << setw(15) << setfill('.') << x << endl;
  cout << "osmickove " << oct << showbase << x << endl;
  cout << "sestnactkove " << hex << x << endl;
  cout << "dekadicky " << dec << x << endl;
  //system("PAUSE");
  return 0;
}
