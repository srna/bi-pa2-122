/* prog1-4.cpp */

#include <cstdlib>
#include <iostream>

using namespace std;

void vypis(int x, int y=0, int z=0) {
  cout << "x=" << x <<endl;
  cout << "y=" << y << endl;
  cout << "z=" << z << endl;
}
  
int main() {
  vypis(10,20,30);
  vypis(10,20);
  vypis(10);
  //system("PAUSE");
  return 0;
}
 
