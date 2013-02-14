/* prog1-3.cpp */

#include <cstdlib>
#include <iostream>

using namespace std;

int na3(int x) {
  return x*x*x;
}

float na3(float x) {
  return x*x*x;
}

int main() {
  int a = 5;
  float b = 4.2;
  cout << a << "^3 = " << na3(a) << endl;
  cout << b << "^3 = " << na3(b) << endl;
  //system("PAUSE");
  return 0;
}
    
