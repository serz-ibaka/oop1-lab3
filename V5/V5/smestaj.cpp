#include "smestaj.h"

Smestaj::Smestaj(const Destinacija& d, Tip t, const string& n, int z, double c)
	: dest(d), tip(t), naziv(n), zvezdice(z), cena(c) {
	if (zvezdice > 5 || zvezdice < 1) throw GZvezdice();
}

ostream& operator<<(ostream& it, const Smestaj& s) {
	return it << s.dohvTip() << ' ' << s.naziv << zvezde[s.zvezdice - 1];
}
