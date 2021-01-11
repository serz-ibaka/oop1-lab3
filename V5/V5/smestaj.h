#ifndef _SMESTAJ_H_
#define _SMESTAJ_H_
#include "destinacija.h"
#include <exception>

class GZvezdice : public exception {
public:
	const char* what() const override {
		return "Greska: Broj zvezdica izvan opsega [1, 5]!";
	}
};

enum Tip { HOTEL, APARTMAN };
const string tipovi[2] = { "HOTEL", "APARTMAN" };
const string zvezde[5] = { "*", "**", "***", "****", "*****" };

class Smestaj {
public:
	Smestaj(const Destinacija& d, Tip t, const string& n, int z, double c);

	const Destinacija& dohvDest() const { return dest; }
	const string& dohvTip() const { return tipovi[tip]; }
	const string& dohvNaziv() const { return naziv; }
	int dohvZvezdice() const { return zvezdice; }
	double dohvCena() const { return cena; }

	friend ostream& operator<<(ostream& it, const Smestaj& s);

private:
	Destinacija dest;
	Tip tip;
	string naziv;
	int zvezdice;
	double cena;
	
};

#endif