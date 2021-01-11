#include "datum.h"

Datum::Datum(int d, int m, int g) : dan(d), mesec(m), godina(g) {
	bool nekorektno = false;
	if (mesec < 1 || dan < 1) nekorektno = true;
	else if (godina < 1900 || godina > 2022) nekorektno = true;
	else switch (mesec) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (dan > 31) nekorektno = true;
		break;
	case 4: case 6: case 9: case 11:
		if (dan > 30) nekorektno = true;
		break;
	case 2:
		if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) {
			if (dan > 29) nekorektno = true;
		}
		else if (dan > 28) nekorektno = true;
		break;
	default:
		nekorektno = true;
		break;
	}

	if (nekorektno) throw GLosDatum();

}

bool operator==(const Datum& d1, const Datum& d2) {
	return d1.dan == d2.dan && d1.mesec == d2.mesec && d1.godina == d2.godina;
}

bool operator!=(const Datum& d1, const Datum& d2) {
	return !(d1 == d2);
}

bool operator>(const Datum& d1, const Datum& d2) {
	return d1.godina > d2.godina ||
		d1.godina == d2.godina && d1.mesec > d2.mesec ||
		d1.godina == d2.godina && d1.mesec == d2.mesec && d1.dan > d2.dan;
}

bool operator<(const Datum& d1, const Datum& d2) {
	return !(d1 >= d2);
}

bool operator>=(const Datum& d1, const Datum& d2) {
	return d1 > d2 || d1 == d2;
}

bool operator<=(const Datum& d1, const Datum& d2) {
	return d1 < d2 || d1 == d2;
}

ostream& operator<<(ostream& it, const Datum& d) {
	return it << setw(2) << setfill('0') << d.dan << '.' 
		<< setw(2) << setfill('0') << d.mesec << '.' 
		<<  d.godina << '.';
}
