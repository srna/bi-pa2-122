#include <iostream>
#include "func.h"

using namespace std;

int main()
{
	int delka;
	int *pole;
	cout << "Zadej velikost pole a prvky: " << endl;
	ctiPole(delka, pole);
	cout << "Zadane pole: " << endl;
	vypisPole(delka, pole);
	seradPole(delka, pole);
	cout << "Serazene pole: " << endl;
	vypisPole(delka, pole);
	vymazPole(pole);

	return 0;
}
