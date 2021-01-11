#include "aranzman.h"

Aranzman::Aranzman(const Destinacija& d, const Datum& p, const Datum& k)
	: dest(d), pocetak(p), kraj(k) {}

Aranzman::Aranzman(const Aranzman& a)
	: dest(a.dest), pocetak(a.pocetak), kraj(a.kraj) { kopiraj(a); }

Aranzman::Aranzman(Aranzman&& a)
	: dest(a.dest), pocetak(a.pocetak), kraj(a.kraj) { premesti(a); }

Aranzman::~Aranzman() { brisi(); }

Aranzman& Aranzman::operator=(const Aranzman& a) {
	if (this != &a) {
		brisi();
		kopiraj(a);
	}
	return *this;
}

Aranzman& Aranzman::operator=(Aranzman&& a) {
	if (this != &a) {
		brisi();
		premesti(a);
	}
	return *this;
}

Destinacija Aranzman::dohvDest() const { return dest; }

Datum Aranzman::dohvPocetak() const { return pocetak; }

Datum Aranzman::dohvKraj() const { return kraj; }

int Aranzman::dohvTrajanje() const {
	return pocetak - kraj;
}

double Aranzman::dohvCena() const {
	if (!smestaj || !prevoz) throw GNedodeljenAtribut();
	return dohvTrajanje() * smestaj->dohvCena();
}

void Aranzman::postSmestaj(Smestaj& s) { 
	if (s.dohvDest() != dest) throw GDestinacijaRazlicita();
	smestaj = &s; 
}

void Aranzman::postPrevoz(const Prevoz& p) {
	if (p.dohvDest() != dest) throw GDestinacijaRazlicita();
	prevoz = new Prevoz(p);
}

void Aranzman::kopiraj(const Aranzman& a) {
	dest = a.dest;
	pocetak = a.pocetak; kraj = a.kraj;

	smestaj = new Smestaj(*a.smestaj);
	prevoz = new Prevoz(*a.prevoz);
}

void Aranzman::premesti(Aranzman& a) {
	dest = a.dest;
	pocetak = a.pocetak; kraj = a.kraj;

	smestaj = a.smestaj; a.smestaj = nullptr;
	prevoz = a.prevoz; a.prevoz = nullptr;
}

void Aranzman::brisi() {
	smestaj = nullptr;
	delete prevoz;
}

ostream& operator<<(ostream& it, const Aranzman& a) {
	return it << a.dest << endl << *a.smestaj << endl << a.dohvCena();
}
