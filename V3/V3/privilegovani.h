#ifndef _PRIVILEGOVAN_H_
#define _PRIVILEGOVAN_H_
#include "tim.h"

class GNedovoljnaVrednost : public exception {
public:
	const char* what() const override {
		return "Greska: Igrac nema dovoljnu vrednost!";
	}
};

class Privilegovani : public Tim {
public:
	Privilegovani(const string& n, int ma, int mi);

	void dodajIgraca(const Igrac& ig, int i) override;

private:
	int min;

	void pisi(ostream& it) const override;
};

#endif