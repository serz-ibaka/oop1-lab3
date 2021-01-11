#include "izraz.h"

Lista<Element>& Izraz::operator+=(Element& p) {
	posl = (prvi ? posl->sled : prvi) = new Elem(p.kopija(), nullptr, posl);
	n++;
	return *this;
}