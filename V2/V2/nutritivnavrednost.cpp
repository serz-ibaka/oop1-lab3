#include "nutritivnavrednost.h"

NutritivnaVrednost::NutritivnaVrednost(double u, double m, double p)
	: uh(u), ma(m), pr(p) {
	if (uh < 0 || ma < 0 || pr < 0) throw GNegativanUnos();
}

NutritivnaVrednost operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2) {
	double uh = n1.uh + n2.uh;
	double ma = n1.ma + n2.ma;
	double pr = n1.pr + n2.pr;
	return NutritivnaVrednost(uh, ma, pr);
}

double NutritivnaVrednost::kalorija() const {
	return 4 * (uh + pr) + 9 * ma;
}

ostream& operator<<(ostream& it, const NutritivnaVrednost& n) {
	return it << "[uh: " << n.uh << ", ma: " << n.ma << ", pr: " << n.pr << ']';
}
