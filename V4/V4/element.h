#ifndef _ELEMENT_H_
#define _ELEMENT_H_
#include <string>
#include <iostream>

using namespace std;

class Element {
public:
	virtual char oznaka() const = 0;
	virtual string dohvNatpis() const = 0;

	virtual Element* kopija() const = 0;

	virtual int prioritet() const = 0;

	friend ostream& operator<<(ostream& it, const Element& e) {
		return it << e.dohvNatpis();
	}
};

#endif