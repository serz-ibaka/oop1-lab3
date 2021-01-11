#ifndef _IZRAZ_H_
#define _IZRAZ_H_
#include "lista.h"
#include "element.h"
#include "operator.h"

class Izraz : public Lista<Element> {
public:
	Lista& operator+=(Element& p) override;
};

#endif