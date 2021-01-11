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
	Datum(int d = 1, int m = 1, int g = 2021);

	friend bool operator==(const Datum& d1, const Datum& d2);
	friend bool operator!=(const Datum& d1, const Datum& d2);
	friend bool operator>(const Datum& d1, const Datum& d2);
	friend bool operator<(const Datum& d1, const Datum& d2);
	friend bool operator>=(const Datum& d1, const Datum& d2);
	friend bool operator<=(const Datum& d1, const Datum& d2);

	friend ostream& operator<<(ostream& it, const Datum & d);

private:
	int dan, mesec, godina;
};

#endif