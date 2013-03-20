#include <iostream>

using namespace std;

template<class T>
class CNotFoundException
{
	T val;
public:
	T getVal() const { return val; }
	CNotFoundException(T val) : val(val) {}
	friend ostream& operator << (ostream& os, 
		const CNotFoundException& e)
	{
		os << "Nenajdena hodnota " << e.val << ".";
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
	if(i == n) throw CNotFoundException<T>(x);
	return i;
}

int main()
{
	const int n = 100;
	int p[n];
	char c[n];

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
	catch (const CNotFoundException<int>& e)
	{
		cerr << "Chyba: " << e << endl;
	}

	try {
		char y = '!';
		int cidx = find(c,n,y);
		cout << "Hodnota " << y << " sa nachadza "
			<< "na pozicii " << cidx << endl; 
	}
	catch (const CNotFoundException<char>& e)
	{
		cerr << "Chyba: " << e << endl;
	}


	return 0;
}
