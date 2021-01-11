#include "racun.h"

Racun::Racun(const Osoba& o, const string& b) : vlasnik(&o), brojRacuna(b) {}

bool Racun::prenos(Racun& r, double i) {
	if (i > iznos) {
		cout << "Transfer neuspesan!" << endl;
		return false;
	}
	iznos -= i;

	r += i;
	cout << "Uspesan transfer!" << endl;
	return true;
}

Racun& Racun::operator+=(double i) { 
	iznos += i; 
	return *this;
}

ostream& operator<<(ostream& it, const Racun& r) {
	return it << "R:" << r.brojRacuna << ":=:" << r.iznos << '-' << r.valuta();
}
