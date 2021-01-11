#ifndef _NUTRITIVNA_VREDNOST_H_
#define _NUTRITIVNA_VREDNOST_H_
#include <exception>
#include <iostream>

using namespace std;

class GNegativanUnos : public exception {
public:
	const char* what() const override {
		return "Greska: Negativan unos!";
	}
};

class NutritivnaVrednost {
public:
	NutritivnaVrednost(double u, double m, double p);

	double dohvUh() const { return uh; }
	double dohvMa() const { return ma; }
	double dohvPr() const { return pr; }

	friend NutritivnaVrednost operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2);

	double kalorija() const;

	friend ostream& operator<<(ostream& it, const NutritivnaVrednost& n);

private:
	double uh, ma, pr;

};

#endif