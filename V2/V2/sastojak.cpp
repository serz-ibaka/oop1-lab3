#include "sastojak.h"

Sastojak::Sastojak(const Namirnica& n, double k) 
	: nam(n), kolicina(k) {
	if (kolicina < 0) throw GNegativanUnos();
}

double Sastojak::kalorija() const {
	return kolicina * dohvNv().kalorija() / 100;
}

ostream& operator<<(ostream& it, const Sastojak& s) {
	return it << '[' << s.kalorija() << "kcal] " << s.kolicina << "g x " << s.nam;
}
