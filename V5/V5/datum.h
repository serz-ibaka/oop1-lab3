#ifndef _DATUM_H_
#define _DATUM_H_
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

class GLosDatum : public exception {
public:
	const char* what() const override {
		return "Greska: los datum!";
	}
};

class Datum {
public:
	Datum(int d, int m, int g);

	friend bool operator==(const Datum& d1, const Datum& d2);
	friend ostream& operator<<(ostream& it, const Datum& d);

	int dohvDan() const { return dan; }
	int dohvMesec() const { return mesec; }
	int dohvGodina() const { return godina; }

	friend int operator-(const Datum& d1, const Datum& d2);

private:
	int dan, mesec, godina;
};

#endif