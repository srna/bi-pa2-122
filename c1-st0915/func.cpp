#include "func.h"
#include <iostream>

using namespace std;

void ctiPole(int& delka, int*& pole)
{
	cin >> delka;
	pole = new int[delka];
	for(int i = 0; i < delka; i++)
	{
		cin >> pole[i];
	}
}

void vypisPole(int delka, int* pole)
{
	for(int i = 0; i < delka; i++)
	{
		cout << pole[i] << " ";
	}
	cout << endl;
}

void vymazPole(int* pole)
{
	delete [] pole;
}

void seradPole(int delka,  int* pole)
{
    for(int i = 0; i < delka; i++)
    {
    	for(int j = 0; j < i; j++)
    	{
    		if(pole[i] < pole[j])
    		{
    			int temp = pole[i];
    			pole[i] = pole[j];
    			pole[j] = temp;
    		}
    	}
    }
}
