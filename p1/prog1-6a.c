/* prog1-6a.c */

/* musi se kompilovat C kompilatorem, nikoli c++
 * ukazuje nedostatecnou kontrolu const v klasickem C
 * je pouze varovani pri kompilaci, ale konstanta se prepise 
 */

#include <stdio.h>
#include <stdlib.h>

void vymenaC(int *px, int *py) {
  int pom = *px;
  *px = *py;
  *py = pom;
}

int main(int argc, char** argv) {
  int a =10, b=20; 
  const int c = 100;
  printf("a= %d b= %d\n", a,b);
  vymenaC(&a, &b);
  printf("po vymene: a= %d b= %d\n", a,b);
  vymenaC(&a, &c);
  printf("po vymene: a= %d c= %d\n", a,c);

  return (EXIT_SUCCESS);
}

