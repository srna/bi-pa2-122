/* main.cpp */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "zasobnik.h"

using namespace std;

bool jeOteviraci(char z) {
   return z=='(' || z=='[' || z=='{';
}

bool jeZaviraci(char z) {
   return z==')' || z==']' || z=='}';
}

char zaviraciK(char z) {
   if (z=='(') return ')';
   if (z=='[') return ']';
   if (z=='{') return '}';
   return z;
}

int main() {
   const int MaxDelkaRadku = 100; 
   Zasobnik zasobnik(3);
   cout << "zadejte radek se zavorkami" << endl;
   char radek[MaxDelkaRadku];
   fgets(radek, MaxDelkaRadku, stdin);
   int i, delka = strlen(radek);;
   for (i=0; i<delka; i++) {
      char znak = radek[i];
      cout << znak;
      if (jeOteviraci(znak))
        zasobnik.vloz(znak);
      else if (jeZaviraci(znak)) {
        if (zasobnik.jePrazdny())
           chyba("k teto zavorce chybi oteviraci");
        char ocekavany = zaviraciK(zasobnik.odeber());
        if (znak!=ocekavany)
          chyba("nespravna zaviraci zavorka");
      }
   }
   if (!zasobnik.jePrazdny()) 
      chyba("chybi zaviraci zavorka(y)");
   cout << endl;
 //system("PAUSE");
   return 0;
}



