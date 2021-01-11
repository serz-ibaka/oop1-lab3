#ifndef _RSD_RACUN_H_
#define _RSD_RACUN_H_
#include "racun.h"

class DinarskiRacun : public Racun {
public:
	DinarskiRacun(const Osoba& o, string b) : Racun(o, b) {}

	string valuta() const override { return "RSD"; }
};

#endif