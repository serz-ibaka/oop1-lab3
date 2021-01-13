#include "privilegovani.h"

Privilegovani::Privilegovani(const string& n, int ma, int mi)
	: Tim(n, ma), min(mi) {
	if (min < 0) throw GNegativnaVrednost();
	cout << "Obicni";
}

Privilegovani& Privilegovani::operator=(const Privilegovani& p) {
	if (this != &p) {
		brisi();
		kopiraj(p);
		min = p.min;
	}
	return *this;
}

Privilegovani& Privilegovani::operator=(Privilegovani&& p)
{
	if (this != &p) {
		brisi();
		premesti(p);
		min = p.min;
	}
	return *this;
}

void Privilegovani::dodajIgraca(const Igrac& ig, int i) {
	if (ig.dohvVrednost() < min) throw GNedovoljnaVrednost();
	Tim::dodajIgraca(ig, i);
}

void Privilegovani::pisi(ostream& it) const {
	Tim::pisi(it);
	it << " (" << min << ")";
}
