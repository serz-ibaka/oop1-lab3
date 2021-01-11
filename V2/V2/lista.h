#ifndef _LISTA_H_
#define _LISTA_H_
#include <exception>

using namespace std;

class GNemaTek : public exception {
public:
	const char* what() const override {
		return "Nema tekuceg elementa!";
	}
};

template<typename T>
class Lista {
public:
	Lista() {}
	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;
	~Lista() { isprazni(); }

	void dodajNaKraj(const T& t) {
		posl = (prvi ? posl->sled : prvi) = new Elem(t);
	}
	Lista& operator+=(const T& t) { dodajNaKraj(t);  return *this; }

	void naPrvi() const { tek = prvi; }
	void naSled() const;
	
	bool imaTek() const { return tek; }
	const T& dohvTek() const;

	void isprazni();

private:
	struct Elem {
		T pod;
		Elem* sled;

		Elem(const T& t, Elem* s = nullptr)
			: pod(t), sled(s) {}
	};

	Elem* prvi = nullptr, *posl = nullptr;
	mutable Elem* tek = nullptr;
};

template<typename T>
void Lista<T>::naSled() const {
	if (tek) tek = tek->sled;
}

template<typename T>
const T& Lista<T>::dohvTek() const {
	if (!imaTek()) throw GNemaTek();
	return tek->pod;
}

template<typename T>
void Lista<T>::isprazni() {
	while (prvi) {
		Elem* st = prvi;
		prvi = prvi->sled;
		delete st;
	}
	prvi = posl = tek = nullptr;
}

#endif