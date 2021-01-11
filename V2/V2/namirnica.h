#ifndef _NAMIRNICA_H_
#define _NAMIRNICA_H_
#include "nutritivnavrednost.h"
#include <string>

class GPrekoracenje : public exception {
public:
	const char* what() const override {
		return "Nutritivna vrednost veca od 100g!";
	}
};

class Namirnica {
public:
	Namirnica(const string& i, const NutritivnaVrednost& n, bool p);
	
	const string& dohvNaziv() const { return naziv; }
	const NutritivnaVrednost& dohvNv() const { return nv; }
	bool dohvPosna() const { return posna; }

	friend bool operator==(const Namirnica& n1, const Namirnica& n2);
	friend bool operator!=(const Namirnica& n1, const Namirnica& n2);

	friend ostream& operator<<(ostream& it, const Namirnica& n);
private:
	string naziv;
	NutritivnaVrednost nv;
	bool posna;

};

#endif