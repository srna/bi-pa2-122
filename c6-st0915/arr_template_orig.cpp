#include <iostream>

using namespace std;

class CInvalidIndexException
{
	int idx;
public:
	int getIdx() const { return idx; }
	CInvalidIndexException(int idx) : idx(idx) {}
	friend ostream& operator << (ostream& os, 
		const CInvalidIndexException& e)
	{
		os << "Neplatny index " << e.idx << ".";
		return os;
	}
};

template <class T>
int find(T* p, int n, const T& x)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(p[i] == x)
			break;
	}
	if(i == n) throw CInvalidIndexException(i);
	return i;
}

int main()
{
	const int n = 100;
	int p[n];
	char c[n];
	int nni[n], p_nni = 0;

	for(int i = 0; i < n; i++)
		p[i] = i;
	for(int i = 0; i < n; i++)
		c[i] = 'A'+i;
	c[n-1] = '\0';

	try {
		int x = 5000;
		int idx = find(p,n,x);
		cout << "Hodnota " << x << " sa nachadza "
			<< "na pozicii " << idx << endl; 
	}
	catch (const CInvalidIndexException& e)
	{
		cerr << "Chyba: " << e << endl;
		nni[p_nni++] = e.getIdx();
	}

	try {
		char y = '0';
		int cidx = find(c,n,y);
		cout << "Hodnota " << y << " sa nachadza "
			<< "na pozicii " << cidx << endl; 
	}
	catch (const CInvalidIndexException& e)
	{
		cerr << "Chyba: " << e << endl;
		nni[p_nni++] = e.getIdx();
	}

	cout << "Nenajdene indexy boli: ";
	for (int i = 0; i < p_nni; i++)
		cout << nni[i] << " ";
	cout << endl;

	return 0;
}
