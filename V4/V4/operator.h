#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include "element.h"

class Operator : public Element {
public:
	virtual int prioritet() const override = 0;

	friend bool operator>(const Operator& o1, const Operator& o2) {
		return o1.prioritet() > o2.prioritet();
	}
	friend bool operator<(const Operator& o1, const Operator& o2) {
		return o1.prioritet() < o2.prioritet();
	}

	char oznaka() const override { return 'O'; }
};

#endif