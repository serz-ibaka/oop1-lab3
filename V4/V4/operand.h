#ifndef _OPERAND_H_
#define _OPERAND_H_
#include "element.h"
#include <string>

using namespace std;

class Operand : public Element {
public:
	Operand(const string& n) : natpis(n) {}

	char oznaka() const override { return 'D'; }
	string dohvNatpis() const override { return natpis; }

	Element* kopija() const override { return new Operand(*this); }

private:
	string natpis;
	
	int prioritet() const override { return 0; }
};

#endif