/* main.cpp */
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "queue.h"
int main() {
 Queue positive, negative;
 int num;
 cout << "write a zero-terminated sequence of integers" <<
endl;
 cin >> num;
 while (num) {
   if (num>0) positive.push(num);
   else negative.push(num);
   cin >> num;
 }
 cout << "positive numbers:" << endl;
 while (!positive.isEmpty()) {
    num = positive.pop();
    cout << num << ' ';
 }
 cout << "\nnegative numbers:" << endl;
 while (!negative.isEmpty()) {
    num = negative.pop();
    cout << num << ' ';
 }
 cout << endl;
 return 0;
}