#ifndef _TIM_H_
#define _TIM_H_
#include "igrac.h"

class GNegativanBrojIgraca : public exception {
public:
	const char* what() const override {
		return "Greska: Maksimalan broj igraca mora biti veci od 0!";
	}
};

class GLosIndeks : public exception {
public:
	const char* what() const override {
		return "Greska: Indeks je van opsega!";
	}
};

class Tim {
public:
	Tim(const string& n, int m);
	Tim(const Tim& t);
	Tim(Tim&& t);
	virtual ~Tim();

	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);

	virtual void dodajIgraca(const Igrac& ig, int i);

	int dohvTren() const { return tren; }

	const Igrac& operator[](int i) const;

	double vrednost() const;

	friend bool operator==(const Tim& t1, const Tim& t2);

	friend ostream& operator<<(ostream& it, const Tim& t);

	void povecaj(double procenat);
	void smanji(double procenat);

protected:
	Igrac** igraci;
	
	virtual void pisi(ostream& it) const;
private:
	string naziv;
	int maks;
	int tren = 0;

	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void brisi();

};

#endif