/* prog1-6.cpp */

#include <cstdlib>
#include <iostream>

using namespace std;

void vymenaC(int *px, int *py) {
  int pom = *px;
  *px = *py;
  *py = pom;
}

void vymenaCPP(int& x, int &y) {
  int pom = x;
  x = y;
  y = pom;
}

int main() {
  int a =10, b=20; 
  cout << "a=" << a << " b=" << b << endl;
  vymenaC(&a, &b);
  cout << "po vymene: a=" << a << " b=" << b << endl;
  vymenaCPP(a, b);
  cout << "po vymene: a=" << a << " b=" << b << endl;
  
/* co nejde
  float x, y; const int c = 100;
  vymenaC(&x, &y);
  vymenaC(&a, &c);
  vymenaCPP(x, y);
  vymenaCPP(a, c);
*/

  //system("PAUSE");
  return 0;
}
