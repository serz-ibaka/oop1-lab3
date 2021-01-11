#include "mec.h"

Mec::Mec(Tim& t1, Tim& t2) 
	: Par(t1, t2) {}

void Mec::odigraj() {
	double vd = pod1->vrednost();
	double vg = pod2->vrednost();

	if (vd > vg) {
		ishod = POBEDA_DOMACIN;
		pod1->povecaj(10);
		pod2->smanji(10);
	}
	else if (vd == vg) {
		ishod = NERESENO;
	}
	else {
		ishod = POBEDA_GOST;
		pod1->smanji(10);
		pod2->povecaj(10);
	}
	odigran = true;
}

Par<int, int> Mec::poeni() const {
	if (!odigran) throw GNeodigran();

	if (ishod == POBEDA_DOMACIN) return Par<int, int>(*new int(3), *new int(0));
	if(ishod == NERESENO) return Par<int, int>(*new int(1), *new int(1));
	return Par<int, int>(*new int(0), *new int(3));
}

void Mec::pisi(ostream& it) const {
	Par::pisi(it);
	if (odigran) {
		switch (ishod) {
		case POBEDA_DOMACIN:
			cout << " Pobeda domacina."; break;
		case NERESENO:
			cout << " Neresen ishod.";  break;
		case POBEDA_GOST:
			cout << " Pobeda gosta."; break;
		}
	}
}
