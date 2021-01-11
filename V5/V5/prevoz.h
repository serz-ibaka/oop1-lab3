#ifndef _PREVOZ_H_
#define _PREVOZ_H_
#include "destinacija.h"

class Prevoz {
public:
	Prevoz(const Destinacija& d, double c);

	const Destinacija& dohvDest() const { return dest; }
	double dohvCena() const { return cena; }

private:
	Destinacija dest;
	double cena;
};

#endif