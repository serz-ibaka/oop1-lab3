#include "destinacija.h"

Destinacija::Destinacija(const string& n, const string& o)
	: naziv(n), opis(o) {}

void Destinacija::oceni(unsigned int ocena) {
	if (ocena > 5) return;
	prosecnaOcena = (brojOcena * prosecnaOcena + ocena) / (brojOcena + 1);
	brojOcena++;
}

bool operator>(const Destinacija& d1, const Destinacija& d2) {
	return d1.prosecnaOcena > d2.prosecnaOcena;
}

bool operator<(const Destinacija& d1, const Destinacija& d2) {
	return d1.prosecnaOcena < d2.prosecnaOcena;
}

bool operator==(const Destinacija& d1, const Destinacija& d2) {
	return d1.naziv == d2.naziv;
}

bool operator!=(const Destinacija& d1, const Destinacija& d2) {
	return !(d1 == d2);
}

ostream& operator<<(ostream& it, const Destinacija& d) {
	return it << '[' << d.prosecnaOcena << "] " << d.naziv << " (" << d.opis << ")";
}
