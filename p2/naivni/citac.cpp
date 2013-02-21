/* citac - naivni styl */

#include <iostream>

using namespace std;

const int pocHodn = 0;

int main()
{
   int hodn;
   char volba;

   cout << "\nCitac - naivni styl\n";
   hodn = pocHodn;
   do {
      cout << "Hodnota = " << hodn << endl << endl;
      cout << "0) Konec\n1) Zvetsit\n2) Zmensit\n"
              "3) Nastavit\n";
              // dva retezce uvedene za sebou se spoji do jednoho
      cout << "Vase volba: ";
      cin >> volba;
 //     cin.ignore(100, '\n');
      switch (volba) {
       case '0': break;
       case '1': hodn++; break;
       case '2': hodn--; break;
       case '3': hodn = pocHodn; break;
       default:  cout << "Nedovolena volba\n";
      }
   } while (volba != '0');
   cout << "Konec\n";
 //system("PAUSE");
   return 0;
}
