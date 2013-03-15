/* 
 * File:   main.cpp
 * Author: Matej Nikl
 *
 * Created on March 14, 2013, 8:57 AM
 */
 
#include <iostream>

#include "bag_refs.h"

using namespace std;

int main()
{
    Bag a;

    a.append (5);
    a += 15;

    cout << "a: " << a;

    Bag b = a;
    Bag c;

    b += 1337;
    c += 112358; 
    c += -128;

    cout << "a: " << a;
    cout << "b: " << b;
    cout << "c: " << c;

    c = b;

    cout << "a: " << a;
    cout << "b: " << b;
    cout << "c: " << c;

    b.detach ();

    b += 105;
    b += 1;
    b += 2;

    cout << "a: " << a;
    cout << "b: " << b;
    cout << "c: " << c;

    c -= 1;
    c.remove (15);

    cout << "a: " << a;
    cout << "b: " << b;
    cout << "c: " << c;


    return 0;
}
