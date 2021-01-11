#ifndef _SABIRANJE_H_
#define _SABIRANJE_H_
#include "operator.h"
#include <string>

class Sabiranje : public Operator {
public:
	string dohvNatpis() const override { return "+"; }

	int prioritet() const override { return 1; }

	Element* kopija() const override { return new Sabiranje(*this); }
};

#endif