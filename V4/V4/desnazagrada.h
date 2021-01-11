#ifndef _DESNA_ZAGRADA_H_
#define _DESNA_ZAGRADA_H_
#include "element.h"
#include <string>

using namespace std;

class DesnaZagrada : public Element {
public:
	char oznaka() const override { return ')'; }
	string dohvNatpis() const override { return ")"; }

	Element* kopija() const override { return new DesnaZagrada(*this); }

private:
	int prioritet() const { return 0; }
};

#endif