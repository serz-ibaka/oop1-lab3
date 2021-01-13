#include "sastojak.h"

Sastojak::Sastojak(const Namirnica& n, double k) 
	: nam(n), kolicina(k) {
	if (kolicina < 0) throw GNegativanUnos();
}

NutritivnaVrednost Sastojak::dohvNv() const {
	NutritivnaVrednost n = nam.dohvNv();
	return NutritivnaVrednost(n.dohvUh() * kolicina / 100, n.dohvMa() * kolicina / 100, n.dohvPr() * kolicina / 100);
}

double Sastojak::kalorija() const {
	return kolicina * dohvNv().kalorija() / 100;
}

ostream& operator<<(ostream& it, const Sastojak& s) {
	return it << '[' << s.kalorija() << "kcal] " << s.kolicina << "g x " << s.nam;
}
