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
	Privilegovani(const Privilegovani& p) : Tim(p), min(p.min) {}
	Privilegovani(Privilegovani&& p) noexcept : Tim(p), min(p.min) {}

	Privilegovani& operator=(const Privilegovani& p);
	Privilegovani& operator=(Privilegovani&& p);

	void dodajIgraca(const Igrac& ig, int i) override;

private:
	int min;

	void pisi(ostream& it) const override;
};

#endif