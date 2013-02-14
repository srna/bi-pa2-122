/* prog1-1.cpp */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int x;

// vstup a vystup ve stylu C
  printf("zadej cele cislo\n");
  scanf("%d", &x);
  printf("zadal jsi %d\n", x);
  
// vstup a vystup ve stylu C++
  cout << "zadej cele cislo" << endl;
  cin >> x;
  cout << "zadal jsi " << x << endl;
  
  //system("PAUSE");
  return 0;
}
