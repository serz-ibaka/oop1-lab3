#ifndef _IGRAC_H_
#define _IGRAC_H_
#include <string>
#include <exception>
#include <iostream>

using namespace std;

class GNegativnaVrednost : public exception {
public:
	const char* what() const override {
		return "Greska: Negativna vrednost igraca!";
	}
};

class Igrac {
public:
	Igrac(const string& i, int v = 1000);

	const string& dohvIme() const { return ime; }
	int dohvVrednost() const { return vrednost; }

	void povecaj(double procenat);
	void smanji(double procenat);

	friend bool operator==(const Igrac& i1, const Igrac& i2);
	friend bool operator!=(const Igrac& i1, const Igrac& i2);

	friend ostream& operator<<(ostream& it, const Igrac& i);

private:
	string ime;
	int vrednost;
};

#endif