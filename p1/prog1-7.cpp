/* prog1-7.cpp */

#include <iostream>

using namespace std;

int main() {
  bool a=true, b=false;
  //bool a=true, b=100; // vyzkosejte misto predchoziho radku
  int i = 100, j = 0;
  cout << "a=" << a << ", b=" << b << endl;
  cout << "a||b=" << (a||b) << endl;
  cout << "a+b=" << a+b << endl;
  a = i; b = j;
  cout << "a=" << a << ", b=" << b << endl;
  //system("PAUSE");
  return 0;
}
