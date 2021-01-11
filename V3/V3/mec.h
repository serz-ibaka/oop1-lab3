#ifndef _MEC_H_
#define _MEC_H_
#include "par.h"
#include "privilegovani.h"

class GNeodigran : public exception {
public:
	const char* what() const override {
		return "Greska: Mec nije odigran";
	}
};

enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
const string ishodi[3] = { "POBEDA_DOMACIN", "NERESENO", "POBEDA_GOST" };

class Mec : public Par<Tim, Tim> {
public:
	Mec(Tim& t1, Tim& t2);

	const Tim& domacin() const { return dohvati1(); }
	const Tim& gost() const { return dohvati2(); }

	void odigraj();

	bool dohvOdigran() const { return odigran; }

	Par<int, int> poeni() const;



private:
	Ishod ishod = NERESENO;
	bool odigran = false;

	void pisi(ostream& it) const override;
};

#endif