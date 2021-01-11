#include "tim.h"

Tim::Tim(const string& n, int m) 
	: naziv(n), maks(m) {
	if (maks <= 0) throw GNegativanBrojIgraca();
	igraci = new Igrac * [maks];
	for (int i = 0; i < maks; i++) igraci[i] = nullptr;
}

Tim::Tim(const Tim& t) { kopiraj(t); }

Tim::Tim(Tim&& t) { premesti(t); }

Tim::~Tim() { brisi(); }

Tim& Tim::operator=(const Tim& t) {
	if (this != &t) {
		brisi();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t) {
	if (this != &t) {
		brisi();
		premesti(t);
	}
	return *this;
}

void Tim::dodajIgraca(const Igrac& ig, int i) {
	if (i < 0 || i >= maks) throw GLosIndeks();

	if (igraci[i]) delete igraci[i];
	else tren++;
	igraci[i] = new Igrac(ig);
}

const Igrac& Tim::operator[](int i) const {
	if (i < 0 || i >= maks || !igraci[i]) throw GLosIndeks();
	return *igraci[i];
}

double Tim::vrednost() const {
	double vrednost = 0;
	for (int i = 0; i < maks; i++) {
		if (igraci[i]) vrednost += igraci[i]->dohvVrednost();
	}

	if (tren == 0) return 0;
	return vrednost / tren;
}

void Tim::povecaj(double procenat) {
	for (int i = 0; i < maks; i++) {
		if (igraci[i]) igraci[i]->povecaj(procenat);
	}
}

void Tim::smanji(double procenat) {
	for (int i = 0; i < maks; i++) {
		if (igraci[i]) igraci[i]->smanji(procenat);
	}
}

void Tim::pisi(ostream& it) const {
	it << naziv << '[';

	int j = 0;
	for (int i = 0; i < maks; i++) {
		if (igraci[i]) {
			j++;
			it << *igraci[i];
			if (j != tren) it << ", ";
		}
	}
	it << ']';
}

void Tim::kopiraj(const Tim& t) {
	naziv = t.naziv;
	maks = t.maks;
	tren = t.tren;

	igraci = new Igrac * [maks];
	for (int i = 0; i < maks; i++) {
		if (t.igraci[i]) igraci[i] = new Igrac(*t.igraci[i]);
		else igraci[i] = nullptr;
	}
}

void Tim::premesti(Tim& t) {
	naziv = t.naziv;
	maks = t.maks;
	tren = t.tren;
	igraci = t.igraci;
	t.igraci = nullptr;
}

void Tim::brisi() {
	for (int i = 0; i < maks; i++) delete igraci[i];
}


bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.naziv != t2.naziv) return false;
	if (t1.maks != t2.maks) return false;
	for (int i = 0; i < t1.maks; i++) {
		if (!t1.igraci[i] && !t2.igraci[i]) continue;
		if (t1.igraci[i] && t2.igraci[i] && t1[i] == t2[i]) continue;
		else return false;
	}
	return true;
}

ostream& operator<<(ostream& it, const Tim& t) {
	t.pisi(it);
	return it;
}
