#include "sastojak.h"
#include "lista.h"

int main() {
	try {
		NutritivnaVrednost n1(20, 10, 5);
		NutritivnaVrednost n2(5, 30, 10);
		NutritivnaVrednost n3(10, 10, 40);

		Namirnica h("hleb", n1, true);
		Namirnica m("maslac", n2, false);
		Namirnica p("piletina", n3, false);

		Sastojak hl(h, 200);
		Sastojak ma(m, 50);
		Sastojak pi(p, 400);

		Lista<Sastojak> l;

		((l += hl) += ma) += pi;

		for (l.naPrvi(); l.imaTek(); l.naSled()) {
			cout << l.dohvTek() << endl;
		}
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}