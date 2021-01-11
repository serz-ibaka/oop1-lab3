#ifndef _LISTA_H_
#define _LISTA_H_
#include <exception>
#include <iostream>

using namespace std;

class GPrazna : public exception {
public:
	const char* what() const override {
		return "Greska: Prazna lista!";
	}
};

template<typename T>
class Lista {
public:
	Lista() {}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	virtual ~Lista() { brisi(); }

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}

	virtual Lista& operator+=(T& p);

	const T& operator-();
	const T& operator*();
	const T& operator~();

	int dohvBrojPod() const { return n; }

	friend ostream& operator<<(ostream& it, const Lista& l) {
		Elem* tek = l.prvi;
		while (tek) {
			it << *tek->pod << ' ';
			tek = tek->sled;
		}
		return it;
	}

protected:
	struct Elem {
		T* pod;
		Elem* sled, * pret;
		Elem(T* t, Elem* s = nullptr, Elem* p = nullptr)
			: pod(t), sled(s), pret(p) {}
	};

	Elem* prvi = nullptr, * posl = nullptr;
	int n = 0;

	virtual void kopiraj(const Lista& l) {
		prvi = posl = nullptr;

		Elem* tek = l.prvi;
		while (tek) {
			(*this) += *(tek->pod);
			tek = tek->sled;
		}
	}
	virtual void premesti(Lista& l) {
		prvi = l.prvi; l.prvi = nullptr;
		posl = l.posl; l.posl = nullptr;
	}
	void brisi() {
		while (prvi) {
			Elem* st = prvi;
			prvi = prvi->sled;
			delete st->pod;
			delete st;
		}
	}
};

template<typename T>
Lista<T>& Lista<T>::operator+=(T& p) {
	posl = (prvi ? posl->sled : prvi) = new Elem(&p, nullptr, posl);
	n++;
	return *this;
}

template<typename T>
const T& Lista<T>::operator-() {
	if (n == 0) throw GPrazna();

	T* t = posl->pod;
	Elem* novi = posl->pret;
	posl->pod = nullptr;
	posl->pret = nullptr;
	delete posl;
	posl = novi;
	if (!posl) prvi = nullptr;
	n--;
	return *t;
}

template<typename T>
const T& Lista<T>::operator*() {
	if (n == 0) throw GPrazna();

	T* t = prvi->pod;
	Elem* novi = prvi->sled;
	prvi->pod = nullptr;
	prvi->pret = nullptr;
	delete prvi;
	prvi = novi;
	if (!prvi) posl = nullptr;
	n--;
	return *t;
}

template<typename T>
const T& Lista<T>::operator~() {
	if (n == 0) throw GPrazna();
	return *(posl->pod);
}

#endif