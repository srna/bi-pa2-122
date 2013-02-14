// prog1-5.cpp

#include <cstdlib>
#include <iostream>

using namespace std;

inline int max(int x, int y)
{	return x>=y ? x : y; }

#define MAX(x,y) ((x)>=(y) ? (x) : (y))

int main()
{ int a=10;
  cout << max(a++,4) << endl;
  cout << a << endl;
  cout << MAX(a++,4) << endl;
  cout << a << endl;
//system("PAUSE");
  return 0;
}
