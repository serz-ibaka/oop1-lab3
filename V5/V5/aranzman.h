#ifndef _ARANZMAN_H_
#define _ARANZMAN_H_
#include "datum.h"
#include "smestaj.h"
#include "prevoz.h"
#include <exception>

class GDestinacijaRazlicita : public exception {
public:
	const char* what() const override {
		return "Greska: Destinacija se ne sme razlikovati!";
	}
};

class GNedodeljenAtribut : public exception {
public:
	const char* what() const override {
		return "Greska: Nisu dodeljeni atributi smestaja i prevoza!";
	}
};

class Aranzman {
public:
	Aranzman(const Destinacija& d, const Datum& p, const Datum& k);
	Aranzman(const Aranzman& a);
	Aranzman(Aranzman&& a);
	virtual ~Aranzman();

	Aranzman& operator=(const Aranzman& a);
	Aranzman& operator=(Aranzman&& a);

	Destinacija dohvDest() const;
	Datum dohvPocetak() const;
	Datum dohvKraj() const;
	int dohvTrajanje() const;
	double dohvCena() const;

	void postSmestaj(Smestaj& s);
	void postPrevoz(const Prevoz& p);

	friend ostream& operator<<(ostream& it, const Aranzman& a);

private:
	Destinacija dest;
	Datum pocetak, kraj;
	Smestaj* smestaj = nullptr;
	Prevoz* prevoz = nullptr;

	void kopiraj(const Aranzman& a);
	void premesti(Aranzman& a);
	void brisi();
};

#endif

//ispis
//destinacija
//smestaj
//cena
