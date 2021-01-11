#include "aranzman.h"

int main() {
	Destinacija dest("Kotor", "Stari grad i more");

	Datum poc(26, 7, 2020), kr(10, 8, 2020);

	Smestaj s(dest, APARTMAN, "Vila Jelena", 4, 1500);
	dest.oceni(4);
	dest.oceni(5);
	dest.oceni(4);

	Prevoz pr(dest, 4000);

	Aranzman ar(dest, poc, kr);

	ar.postPrevoz(pr);
	ar.postSmestaj(s);

	cout << ar << endl;
}