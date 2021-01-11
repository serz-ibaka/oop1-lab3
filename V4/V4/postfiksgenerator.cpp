#include "postfiksgenerator.h"

Izraz& PostfiksGenerator::operator()(const Izraz& i) {
    Lista<Element> stek;
    Izraz pom = i;
    Izraz* postfiks = new Izraz();
    int rang = 0;
    const Element* tren = &(*pom);

    while (pom.dohvBrojPod()) {
        if (tren->oznaka() == 'D') {
            rang++;
            *postfiks += *const_cast<Element*>(tren);
        }
        else {
            while (stek.dohvBrojPod() != 0 &&
                (//(tren->oznaka() == '(' && (~stek).oznaka() =='(') ||
                    (tren->oznaka() == ')' && (~stek).oznaka() != '(') ||
                    (tren->oznaka() != '(' && tren->oznaka() != ')' && tren->prioritet() <= (~stek).prioritet()))) {
                const Element& tr = -stek;
                *postfiks += const_cast<Element&>(tr);
                rang--;
                if (rang < 1) throw GPostfiks();
            }
            if (tren->oznaka() != ')') stek += *const_cast<Element*>(tren);
            else -stek;
        }
        tren = &(*pom);
    }

    if (tren->oznaka() == 'D') {
        rang++;
        *postfiks += *const_cast<Element*>(tren);
    }

    while (stek.dohvBrojPod() != 0) {
        const Element& tr = -stek;
        if (tr.oznaka() != '(') {
            *postfiks += const_cast<Element&>(tr);
            rang--;
        }
    }
    if (rang != 1) throw GPostfiks();

    return *postfiks;
}
