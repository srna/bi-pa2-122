/* 
 * File:   bag_refs.h
 * Author: Matej Nikl
 *
 * Created on March 14, 2013, 8:57 AM
 */

#include <iostream>

using namespace std;

class Bag {
private:
    struct Pocket {
        int *data;
        int size, count, refs;
        Pocket  ();
        Pocket  (const Pocket & from);
        ~Pocket ();
    };
    
    Pocket * pocket;

    void connectTo  (Pocket * ptr);
    void disconnect ();
    void resize     (int newsize);
public:
    Bag  ();
    Bag  (const Bag & from);
    ~Bag ();


    void detach     ();
    void append     (int a);
    void remove     (int a);
    bool contains   (int a);
    int  find       (int a);

    Bag       & operator += (int a);
    Bag       & operator -= (int a);
    Bag       & operator  = (const Bag & from);
    int       & operator [] (int index);
    const int & operator [] (int index) const;


    friend ostream & operator << (ostream & os, const Bag & b);

    
    friend void printPtrs (const Bag * bag, int indent = 0);
};
