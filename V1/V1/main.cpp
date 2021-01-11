#include "rsdracun.h"

int f(int& i) {
	return 5;
}

int main() {
	try {
		Datum d1(10, 10, 2000);
		Osoba sergej("Sergej Prosic", "1010000710260", Datum(10,10,2000));
		DinarskiRacun sergej_racun(sergej, "170-000106452-78");

		Datum d2(9, 4, 2001);
		Osoba kristina("Kristina Marusic", "0904001520128", d2);
		DinarskiRacun kristina_racun(kristina, "170-000106453-78");

		cout << "Korisnici: " << endl << kristina << endl << sergej << endl;

		kristina_racun += 100000;

		cout << "Pre transfera: " << endl
			<< kristina_racun << endl
			<< sergej_racun << endl;
		kristina_racun.prenos(sergej_racun, 20000);
		cout << "Posle prvog transfera: " << endl
			<< kristina_racun << endl
			<< sergej_racun << endl;
		kristina_racun.prenos(sergej_racun, 100000);
		cout << "Posle drugog transfera: " << endl
			<< kristina_racun << endl
			<< sergej_racun << endl;
		
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}