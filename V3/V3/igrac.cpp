#include "igrac.h"

Igrac::Igrac(const string& i, int v) 
	: ime(i), vrednost(v) {
	if (vrednost < 0) throw GNegativnaVrednost();
}

void Igrac::povecaj(double procenat) {
	vrednost = vrednost + vrednost * procenat / 100;
}

void Igrac::smanji(double procenat) {
	if (procenat > 100) throw GNegativnaVrednost();
	povecaj(-procenat);
}

bool operator==(const Igrac& i1, const Igrac& i2) {
	return i1.ime == i2.ime && i1.vrednost == i2.vrednost;
}

bool operator!=(const Igrac& i1, const Igrac& i2) {
	return !(i1 == i2);
}

ostream& operator<<(ostream& it, const Igrac& i) {
	return it << i.ime << '#' << i.vrednost;
}
