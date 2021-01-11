#ifndef _ODUZIMANJE_H_
#define _ODUZIMANJE_H_
#include "operator.h"
#include <string>

class Oduzimanje : public Operator {
public:
	string dohvNatpis() const override { return "-"; }

	int prioritet() const override { return 1; }

	Oduzimanje* kopija() const override { return new Oduzimanje(*this); }
};

#endif