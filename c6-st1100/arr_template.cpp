#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const char* logfile = "arr_template.log";

template<class T>
class NotFoundException
{
	string file;
	int line;
	time_t t;
	struct tm * datetime;
	T val;
public:
	NotFoundException(const T& val) : val(val)
	{
		file = __FILE__;
		line = __LINE__;
		t = time(NULL);
		datetime = localtime( & t );
	}
	string getFile() { return file; }
	int getLine() { return line; }
	T getValue() { return val; }
	void log() const
	{
		ofstream ofs(logfile, ios::app);
		ofs << *this << endl;
		ofs.close();
	}
	friend ostream& operator << (ostream& os, 
		const NotFoundException& e)
	{
		os  << "[" << e.datetime->tm_year + 1900
			<< "-" << e.datetime->tm_mon+1
			<< "-" << e.datetime->tm_mday
			<< " " << e.datetime->tm_hour
			<< ":" << e.datetime->tm_min
			<< ":" << e.datetime->tm_sec
			<< "] " << e.file << ":" << e.line
			<< " error: " << "Item '" << e.val << "' not found";
		return os;
	}
};

template<class T>
T* find(T* p, int n, const T& x)
{
	T* r = NULL;
	for(int i = 0; i < n; i++)
		if(p[i] == x)
		{
			/*
				p[i] -> *(p+i)
				&p[i] -> p+i
			*/
			r = p+i;
			break;
		}
	if(r == NULL)
		throw NotFoundException<T>(x);
	return r;
}

int main()
{
	const int n = 10;
	int pi[n];
	char pc[n];
	for(int i = 0; i < n; i++)
	{
		pi[i] = i;
		pc[i] = 'A'+i;
	}

	try{
		int * pfi = find(pi,n,5);
		cout << "5 je na pozicii " 
			 << pfi - pi << endl;

		char * pfc = find(pc,n,'Z');
		cout << "Z je na pozicii " 
			 << pfc - pc << endl;
	}
	catch(const NotFoundException<int>& e)
	{
		e.log();
		cout << e << endl;
	}
	catch(const NotFoundException<char>& e)
	{
		e.log();
		cout << e << endl;
	}
	catch(const char* e)
	{
		cout << "Chyba: " << e << endl;
	}
	catch(...)
	{
		cout << "Neznama chyba" << endl;
	}

	return 0;
}
