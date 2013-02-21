/* zasobnik.cpp */

#include <iostream>
#include <cstdlib>

#include "zasobnik.h"

Zasobnik::Zasobnik(int maxDelka) {
  maxVrch = maxDelka-1;
  prvky = new TypPrvku[maxDelka];
  vrch = -1;
}

Zasobnik::~Zasobnik() {
  delete [] prvky;
  maxVrch = -1;
  prvky = NULL;
  vrch = -1;
}

void Zasobnik::vloz(TypPrvku p) {
  if (vrch<maxVrch) 
     prvky[++vrch] = p;
  else {
     chyba("preteceni zasobniku");
  }
}

TypPrvku Zasobnik::odeber() {
  if (vrch>=0) 
    return prvky[vrch--];
  else {
     chyba("odebirani z prazdneho zasobniku");
  }
}
    
bool Zasobnik::jePrazdny() {
  return vrch<0;
}
    
void chyba(const char *str) {
   std::cout << " chyba: " << str << std::endl;
 //system("PAUSE");
   exit(1);
}





