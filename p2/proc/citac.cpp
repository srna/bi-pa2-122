/* citac - proceduralni styl */

#include <iostream>

using namespace std;

const int pocHodn = 0;
int hodn;

int menu()
/* vypise nabidku a precte volbu
   vrati: 0 ... konec, 1,2,3 ... operace s citacem
*/
{
   char volba;
   cout << endl;
   do {
      cout << "0) Konec\n";
      cout << "1) Zvetsit\n";
      cout << "2) Zmensit\n";
      cout << "3) Nastavit\n";
      cout << "Vase volba: ";
      cin >> volba;
      cin.ignore(100, '\n');
      if (volba < '0' || volba > '3') {
         cout << "Nedovolena volba\n";
         volba = 'e';
      }
   } while (volba == 'e');
   return volba - '0';
}

void citac(int op)
/* provede operaci op s citacem Hodn */
{
   switch (op) {
    case 1: hodn++; break;
    case 2: hodn--; break;
    case 3: hodn = pocHodn;
   }
}

int main()
{
   int volba;

   cout << "\nCitac - proceduralni styl\n";
   hodn = pocHodn;
   do {
      cout << "Hodnota = " << hodn << endl;
      volba = menu();
      if (volba > 0)
         citac(volba);
   } while (volba > 0);
   cout << "Konec\n";
 //system("PAUSE");
   return 0;
}
