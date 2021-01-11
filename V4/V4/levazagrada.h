#ifndef _LEVA_ZAGRADA_H_
#define _LEVA_ZAGRADA_H_
#include "element.h"
#include <string>

using namespace std;

class LevaZagrada : public Element {
public:
	char oznaka() const override { return '('; }
	string dohvNatpis() const override { return "("; }

	Element* kopija() const override { return new LevaZagrada(*this); }

private:
	int prioritet() const override { return 0; }
};

#endif