/* main.cpp */
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "queue.h"
int main() {
 Queue<int> positive, negative;
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

 Queue<float> fpositive, fnegative;
 float fnum;
 cout << "write a zero-terminated sequence of floats" <<
endl;
 cin >> fnum;
 while (fnum) {
   if (fnum>0) fpositive.push(fnum);
   else fnegative.push(fnum);
   cin >> fnum;
 }
 cout << "positive numbers:" << endl;
 while (!fpositive.isEmpty()) {
    fnum = fpositive.pop();
    cout << fnum << ' ';
 }
 cout << "\nnegative numbers:" << endl;
 while (!fnegative.isEmpty()) {
    fnum = fnegative.pop();
    cout << fnum << ' ';
 }
 cout << endl;
 return 0;
}