#ifndef __CITAC_H_
#define __CITAC_H_

class Citac {
	int _hodn;
public:
	Citac(int h = 0) { _hodn = h; }
	~Citac() { _hodn = 0; }
	int hodn();
	void inc();
	void dec();
	void reset();
};

#endif
