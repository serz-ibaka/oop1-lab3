#ifndef _RACUN_H_
#define _RACUN_H_
#include "osoba.h"

class Racun {
public:
	Racun(const Osoba& o, const string& b);
	Racun(const Racun&) = delete;
	Racun& operator=(const Racun&) = delete;
	virtual ~Racun() { vlasnik = nullptr; }

	const Osoba& dohvOsoba() const { return *vlasnik; }
	const string& dohvBrojRacuna() const { return brojRacuna; }
	double dohvIznos() const { return iznos; }

	bool prenos(Racun& r, double iznos);
	Racun& operator+=(double iznos);

	virtual string valuta() const = 0;

	friend ostream& operator<<(ostream& it, const Racun& r);

private:
	const Osoba* vlasnik;
	string brojRacuna;
	double iznos = 0;
};

#endif