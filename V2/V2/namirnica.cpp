#include "namirnica.h"

Namirnica::Namirnica(const string& i, const NutritivnaVrednost& n, bool p) 
	: naziv(i), nv(n), posna(p) {
	if (n.dohvUh() + n.dohvMa() + n.dohvPr() > 100) throw GPrekoracenje();
}

bool operator==(const Namirnica& n1, const Namirnica& n2) {
	return n1.naziv == n2.naziv;
}

bool operator!=(const Namirnica& n1, const Namirnica& n2) {
	return n1.naziv != n2.naziv;
}

ostream& operator<<(ostream& it, const Namirnica& n) {
	return it << n.naziv << " - " << n.nv;
}
