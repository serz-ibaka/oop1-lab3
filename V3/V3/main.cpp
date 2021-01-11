#include "mec.h"

int main() {
	try {
		Igrac i1("Sergej", 1500),
			i2("Kristina", 10000),
			i3("Katarina", 2500),
			i4("Darko", 1200);

		Tim n("FK Hemofarm Vrsac", 10);
		n.dodajIgraca(i1, 0);
		n.dodajIgraca(i2, 4);
		n.dodajIgraca(i3, 7);
		n.dodajIgraca(i4, 2);

		Privilegovani pt("FK Sumadija", 10, 1500);
		pt.dodajIgraca(i1, 0);
		pt.dodajIgraca(i2, 4);
		pt.dodajIgraca(i3, 7);
		// pt.dodajIgraca(i4, 2);

		
		Mec m(n, pt);
		m.odigraj();
		cout << m << endl;
		cout << n << endl << pt << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}