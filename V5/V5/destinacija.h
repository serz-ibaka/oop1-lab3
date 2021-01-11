#ifndef _DESTINACIJA_H_
#define _DESTINACIJA_H_
#include <string>
#include <iostream>
#include <exception>
#include <iomanip>

using namespace std;

class Destinacija {
public:
	Destinacija(const string& n, const string& o);
	
	void oceni(unsigned int ocena);
	
	const string& dohvNaziv() const { return naziv; }
	const string& dohvOpis() const { return opis; }
	double dohvProsecnaOcena() const { return prosecnaOcena; }

	friend bool operator>(const Destinacija& d1, const Destinacija& d2);
	friend bool operator<(const Destinacija& d1, const Destinacija& d2);
	friend bool operator==(const Destinacija& d1, const Destinacija& d2);
	friend bool operator!=(const Destinacija& d1, const Destinacija& d2);
	
	friend ostream& operator<<(ostream& it, const Destinacija& d);

private:
	string naziv, opis;
	int brojOcena = 0;
	double prosecnaOcena = 0;
};

#endif