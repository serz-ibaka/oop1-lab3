#ifndef _MNOZENJE_H_
#define _MNOZENJE_H_
#include "operator.h"
#include <string>

class Mnozenje : public Operator {
public:
	string dohvNatpis() const override { return "*"; }

	int prioritet() const override { return 2; }

	Element* kopija() const override { return new Mnozenje(*this); }
};

#endif