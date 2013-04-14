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
		strncpy(jmeno, jm, 25);
		jmeno[25] = '\0';
		strncpy(prijmeni, pr, 36);
		prijmeni[36] = '\0';
		id = __next_id++;
	}
	virtual int plat() const = 0;
	friend ostream& operator<<(ostream& os, const Zamestnanec& z)
	{
		os << z.id << ". " << z.jmeno << " "
			<< z.prijmeni << ", plat: " << z.plat();
		return os;
	}
	int getId() const
	{
		return id;
	}
};
int Zamestnanec::__next_id = 1;

class Delnik : public Zamestnanec
{
	int hod, mzda;
public:
	Delnik(const char* jm, const char* pr,
			int h, int m) 
		: Zamestnanec(jm, pr), hod(h), mzda(m)
		{}
	int plat() const
	{
		return hod*mzda;
	}
};

class Urednik : public Zamestnanec
{
	int mzda;
public:
	Urednik(const char* jm, const char* pr,
			int m) 
		: Zamestnanec(jm, pr), mzda(m)
		{}
	int plat() const
	{
		return mzda;
	}
};

class Firma
{
	int count, size;
	Zamestnanec** data;
public:
	Firma(int maxzam) : count(0), size(maxzam)
	{
		data = new Zamestnanec*[size];
	} 
	~Firma()
	{
		delete [] data;
	}
	Firma& vloz(Zamestnanec* z)
	{
		data[count++] = z;
		return *this;
	}
	Firma& odeber(int id)
	{
		int i;
		for(i = 0; i < count ; i++)
			if(data[i]->getId() == id)
				break;
		if(i != count) // found
		{
			memmove(data+i, data+i+1, 
				(count-i-1)*sizeof(Zamestnanec*));
			count--;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Firma& f)
	{
		os << "Firma, " << f.count << " zamestnancu" << endl;
		for(int i = 0; i < f.count; i++)
		{
			if(dynamic_cast<Delnik*>(f.data[i]))
				os << "Delnik: ";
			else if (dynamic_cast<Urednik*>(f.data[i]))
				os << "Urednik: ";
			else
				os << "Zamestnanec: ";
			os << *(f.data[i]) << endl;
		}
		return os;
	}
	int platy()
	{
		int pl = 0;
		for(int i = 0; i < count; i++)
			pl += data[i]->plat();
		return pl;
	}
};

int main(int argc, char const *argv[])
{
	Delnik d("Mako", "Jakopako", 100, 160);
	Urednik u("Mako", "Jako", 20000);

	cout << d << endl;
	cout << u << endl;

	Firma f(5);
	f.vloz(&d).vloz(&u);
	cout << f << endl;

	f.odeber(d.getId());
	cout << f << endl;

	cout << "Platy maju spolu " << f.platy() << endl;

	return 0;
}
