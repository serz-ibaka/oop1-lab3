#ifndef _OSOBA_H_
#define _OSOBA_H_
#include <string>
#include "datum.h"

class Osoba {
public:
	Osoba(const string& i, const string& m, const Datum& d);
	Osoba(const Osoba&) = delete;
	Osoba& operator=(const Osoba&) = delete;

	const string& dohvIme() const { return ime; }
	const string& dohvMaticni() const { return maticni; }
	const Datum& dohvDatum() const { return datum; }

	friend ostream& operator<<(ostream& it, const Osoba& o);

private:
	string ime, maticni;
	Datum datum;
};

#endif