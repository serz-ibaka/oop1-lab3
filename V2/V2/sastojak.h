#ifndef _SASTOJAK_H_
#define _SASTOJAK_H_
#include "namirnica.h"

class Sastojak {
public:
	Sastojak(const Namirnica& n, double k);

	const Namirnica& dohvNam() const { return nam; }
	double dohvKolicina() const { return kolicina; }

	NutritivnaVrednost dohvNv() const;

	double kalorija() const;

	friend ostream& operator<<(ostream& it, const Sastojak& s);

private:
	Namirnica nam;
	double kolicina;
};

#endif