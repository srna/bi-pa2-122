#include <iostream>
#include <cstring>

using namespace std;

class Zamestnanec
{
	char jmeno[26];
	char prijmeni[37];
	int id;
	static int __next_id;
public:
	Zamestnanec(const char* jm, const char* pr)
	{
		id = __next_id++;
		strncpy(jmeno, jm, 25);
		jmeno[25] = '\0';
		strncpy(prijmeni, pr, 36);
		prijmeni[36] = '\0';
	}
	virtual int plat() const = 0;
	ostream& vypis (ostream& os) const
	{
		os 	<< jmeno << " " << prijmeni 
			<< "(" << id << "), plat: "
			<< plat();
		return os;
	}
	virtual ~Zamestnanec() {}
	int getId() const {return id;}
};
int Zamestnanec::__next_id = 1;

class Delnik : public Zamestnanec
{
	int mzda;
	int hodin;
public:
	Delnik(const char* jm, const char* pr,
			int m, int h) 
			: Zamestnanec(jm, pr)
	{
		mzda = m;
		hodin = h;
	}
	int plat() const
	{
		return mzda*hodin;
	}
};

class Urednik : public Zamestnanec
{
	int mzda;
public:
	Urednik(const char* jm, const char* pr,
			int m) 
			: Zamestnanec(jm, pr)
	{
		mzda = m;
	}
	int plat() const
	{
		return mzda;
	}
};

class Firma
{
	int size, count;
	Zamestnanec** data;
public:
	Firma(int maxzam) : size(maxzam)
	{
		count = 0;
		data = new Zamestnanec*[size];
	}
	~Firma()
	{
		delete [] data;
	}
	Firma& vloz(Zamestnanec* zam)
	{
		data[count++] = zam;
		return *this;
	}
	Firma& odeber(int id)
	{
		int i;
		for(i = 0; i < count; i++)
			if(data[i]->getId() == id)
				break;
		if(count != i) // found
		{
			memmove(data+i, data+i+1, 
				(count-i-1)*sizeof(Zamestnanec*));
			count--;
		}
		return *this;
	}
	ostream& vypis(ostream& os) const
	{
		os << "Firma(" << count << " z " << size 
			<< ")" << endl;
		for(int i = 0; i < count; i++)
		{
			if(dynamic_cast<Urednik*>(data[i]))
				os << "Urednik: ";
			else if (dynamic_cast<Delnik*>(data[i]))
				os << "Delnik: ";
			else
				os << "Zamestnanec: ";
			data[i]->vypis(os) << endl;
		}
		return os;
	}
	int platy() const
	{
		int pl = 0;
		for(int i = 0; i < count; i++)
			pl += data[i]->plat();
		return pl;
	}
};

int main()
{
	Delnik d("Mako", "Jakopako", 100, 160);
	Urednik u("Mako", "Jako", 20000);
	d.vypis(cout) << endl;
	u.vypis(cout) << endl;

	Firma f(5);
	f 	.vloz(&d)
		.vloz(&u);

	f.vypis(cout);
	cout << "Soucet platu: " << f.platy() << endl;


	return 0;
}
