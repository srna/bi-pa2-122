/* 
 * File:   bag_refs.cpp
 * Author: Matej Nikl
 *
 * Created on March 14, 2013, 8:57 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#include "bag_refs.h"

using namespace std;

const int INIT_SIZE = 2;
const int GAP       = 10;

Bag::Pocket::Pocket ()
{
    cout << "Creating new pocket:" << setw (55 + GAP) << "" << this << endl;

    size  = INIT_SIZE;
    count = 0;
    refs  = 0;
    data  = new int [size];
}

Bag::Pocket::Pocket (const Pocket & from)
{
    cout << "Creating new pocket:" << setw (55 + GAP) << "" << this << endl;
    cout << "    as duplacita of:" << setw (55 + GAP) << "" << &from << endl;

    size = from.size;
    count = from.count;
    refs = 0;
    data = new int [size];

    memcpy (data, from.data, count * sizeof (int));
}

Bag::Pocket::~Pocket ()
{
    delete [] data;
}


Bag::Bag ()
{
    cout << "Creating new bag using new pocket:"
         << setw (17 + GAP) << "" << this << endl;

    Pocket * newPocket = new Pocket();
    connectTo (newPocket);
}



Bag::Bag (const Bag & b)
{
    cout << "Creating new bag using shared pocket:"
         << setw (14 + GAP) << "" << this << endl;
    
    connectTo (b.pocket);
}


Bag::~Bag ()
{
    disconnect ();
}

void Bag::connectTo (Pocket * ptr)
{
    cout << "Bag is connecting to pocket";

    pocket = ptr;
    ptr->refs++;

    printPtrs (this, 19);
}

void Bag::disconnect ()
{
    cout << "Bag is disconnecting from pocket";
    printPtrs (this, 14);
    pocket->refs--;

    if (pocket->refs == 0) {
        cout << "Deleting pocket, because no one is connected to it:"
             << setw (24 + GAP) << "" << pocket << endl;
        delete pocket;
    }
}

void Bag::resize (int newsize)
{
    cout << "Bag is ";
    if (newsize > pocket->size) {
        cout << "increasing";
    } else {
        cout << "decreasing";
    }

    cout << " size from " << setw (2) << pocket->size
         << " to " <<  setw (2) << newsize << " of pocket";
    printPtrs (this);
    
    int * newdata;
    newdata = new int [newsize];
    memcpy (newdata, pocket->data, pocket->count * sizeof(int));

    delete [] pocket->data;

    pocket->data = newdata;
    pocket->size = newsize;
}

void Bag::detach ()
{
    if (pocket->refs > 1) {
        cout << "Detaching from pocket";
        printPtrs (this, 25);

        Pocket * newpocket = new Pocket(*pocket);
        disconnect ();
        connectTo  (newpocket);
    }
}

void Bag::append (int val)
{
    if (pocket->size == pocket->count) {
        resize (pocket->size * 2);
    }

    cout << "Appending new value: " << setw (7) << val;
    printPtrs(this, 18);

    pocket->data[pocket->count++] = val;
}

void Bag::remove (int val)
{
    int result = find (val);

    cout << "Trying to remove " << setw (5) << val << " from pocket...";

    if (result >= 0) {
        pocket->data [result] = pocket->data [--(pocket->count)];
        cout << "success" << setw (2) << "";
    } else {
        cout << "not found";
    }
    printPtrs (this);
    
    if (pocket->size / 2  >= pocket->count && pocket-> size / 2 >= INIT_SIZE) {
        resize (pocket->size / 2);
    }

}

bool Bag::contains (int val)
{
    return find (val) >= 0;
}

int Bag::find (int val)
{
    for (int i = 0; i < pocket->count; i++) {
        if (pocket->data [i] == val) {
            return i;
        }
    }
    return -1;
}


Bag & Bag::operator += (int val)
{
    append (val);

    return *this;
}

Bag & Bag::operator -= (int val)
{
    remove (val);

    return *this;
}


Bag & Bag::operator  = (const Bag & from)
{
    if (this->pocket != from.pocket) {
        disconnect ();
        connectTo  (from.pocket);
    }

    return *this;
}

int & Bag::operator [] (int index)
{
    return pocket->data [index];
}

const int & Bag::operator [] (int index) const
{
    return pocket->data [index];
}


ostream & operator << (ostream & os, const Bag & bag)
{
    cout << "[";
    for (int i = 0; i < bag.pocket->count; i++) {
        os << bag [i];

        if (i < bag.pocket->count - 1) {
            os << " , ";
        }
    }

    os << "]" << endl;
    os << "   refs: "  << setw(2)  << bag.pocket->refs << endl;

    return os;
}


void printPtrs (Bag * bag, int indent)
{
    cout << setw (GAP + indent) << "";
    cout << "Bag: " << bag << ", Pocket: " << bag->pocket << endl;
}
