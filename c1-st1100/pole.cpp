#include <iostream>
#include "func.h"

using namespace std;

int main()
{
	int *pole;
	int delka;

	cout << "Zadej velikost a prvky pole:" << endl;
	ctiPole(delka, pole);
	cout << "Pole obsahuje: " << endl;
	vypisPole(delka, pole);
	seradPole(delka, pole);
	cout << "Serazene pole: " << endl;
	vypisPole(delka, pole);

	smazPole(pole);
}
