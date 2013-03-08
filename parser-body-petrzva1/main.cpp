#include <iostream>
#include <fstream>
#include <string>
#include <iostream>

#include "students.h"

using namespace std;

#define FILENAME	30 // hodnota udava maximalni delku souboru

/*Vstupem programu jsou soubory s daty(username body).
Ten je zpracuje a vypise na obrazovku, pripadne do souboru.
Delka nazvu souboru je definovana hodnotou FILENAME. Program je schopen zaznamenat maximalne STUDENTSMAX originalnich
usernamu. Tutu hodnotu lze upravit v students.h(nastavena na 50). 
Program zpracovava data po radcich. Kazda radka by mela byt ve tvaru:
username mezera pocet bodu. Tolerovany jsou ruzne syntaxe zapisu.(zaporna hodnota bodu, mezery na zac. radku a pod.)
Username je definovany jako prvnich 8 znaku, ve kterych neni mezera. Pak muze nasledovat libovolny pocet
mezer a odradkovani.
Data jsou pridavana do pole struktur ktera se po zpracovani posledniho souboru vypise na obrazovku,
pripadne lze zvolit vytvoreni souboru s vystupem.
*/


int main( int argc, char * argv [] )
{
	Students List;
	string retezec;
	ifstream ifs;
	int i = 1;
	int cisloRadku=0;
	string volba="";
	cout << endl;
	if(argc == 1)  //nebyli zadany nazvy souboru
	{
		cout<<"Pri spousteni programu zadejte nazvy souboru, ktere chcete zpracovat oddelene mezeramy."<<endl;
		return 0;
	}
	while(i<argc )  //zpracovani jednotlivych souboru
	{
		
		ifs.open(argv[i]);
		if(!ifs.good()) //chybne zadane jmeno
		{
			if(argc == 2) //zadan jediny soubor a chybne ->ukoncim program
			{
			cout<<"Chyba pri praci se souborem. Pravdepodobne spatne zadane jmeno : "<<argv[i]<<endl;
			i++;
			ifs.close();
			return 0;
			}else
			{
			cout<<"Chyba pri praci se souborem. Pravdepodobne spatne zadane jmeno : "<<argv[i]<<endl;
			i++;
			ifs.close();
			}
		}
    	else
    	{
	   		cout<< "Aktualne zpracovavam soubor : "<<argv[i] <<endl;
	   		i++;
	   		cisloRadku = 0;
	   		while(!ifs.eof())  
	        {            
	        		cisloRadku++;
	                getline(ifs,retezec);
	                if(retezec=="")break;
	                if(!List.ParseData(retezec))
	                cout<<"Tato chyba vznikla na radku cislo : " << cisloRadku<<endl;
	   		}
	   		ifs.close();
	   		cout<<"-------------------------"<<endl<<endl;
   		}

   	}	
   	
  		
		
		List.SortByScore();
		List.PrintAll();

		
		cout<<endl<<"Prejete si importovat data do souboru?(A/N)"<<endl;
		cin>>volba;
		if(volba[0]=='A' ||volba[0]=='a')
		{
			cout<<"Zadej jmeno souboru: "<<endl;
			char *jmenoSouboru = new char [FILENAME];
			cin>>jmenoSouboru;
			List.PrintToFile(jmenoSouboru);
			delete [] jmenoSouboru;
		}

		return 0;
}





