#include "osoba.h"

Osoba::Osoba(const string& i, const string& m, const Datum& d) 
	: ime(i), maticni(m), datum(d) {}

ostream& operator<<(ostream& it, const Osoba& o) {
	return it << "O(" << o.ime << ", " << o.maticni << ", " << o.datum << ')';
}
