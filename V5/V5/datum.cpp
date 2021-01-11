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

ostream& operator<<(ostream& it, const Datum& d) {
	return it << setw(2) << setfill('0') << d.dan << '.' 
		<< setw(2) << setfill('0') << d.mesec << '.' 
		<<  d.godina << '.';
}

int operator-(const Datum& d1, const Datum& d2) {
	const int brDana[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	int p1 = (d1.mesec > 2 ? d1.godina : d1.godina - 1);
	int p2 = (d2.mesec > 2 ? d2.godina : d2.godina - 1);
	int n1 = (d1.godina - 1950) * 365 + d1.dan;
	int n2 = (d2.godina - 1950) * 365 + d2.dan;
	
	for (int i = 0; i < d1.mesec - 1; i++) n1 += brDana[i];
	n1 += p1 / 4 - p1 / 100 + p1 / 400;


	for (int i = 0; i < d2.mesec - 1; i++)
		n2 += brDana[i];
	n2 += p2 / 4 - p2 / 100 + p2 / 400;

	return (n2 - n1);
}
