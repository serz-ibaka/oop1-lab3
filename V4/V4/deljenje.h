#ifndef _DELJENJE_H_
#define _DELJENJE_H_
#include "operator.h"
#include <string>

class Deljenje : public Operator {
public:
	string dohvNatpis() const override { return "/"; }

	int prioritet() const override { return 2; }

	Element* kopija() const override { return new Deljenje(*this); }
};

#endif