#ifndef _PAR_H_
#define _PAR_H_
#include <iostream>

using namespace std;

template<typename T1, typename T2>
class Par {
public:
	Par(T1& t1, T2& t2)
		: pod1(&t1), pod2(&t2) {}
	Par(const Par& p) {
		pod1 = new T1(*p.pod1);
		pod2 = new T2(*p.pod2);
	}
	Par(Par&& p) {
		pod1 = p.pod1; p.pod1 = nullptr;
		pod2 = p.pod2; p.pod2 = nullptr;
	}
	virtual ~Par() {}

	void postavi1(const T1& t1) { pod1 = &t1; }
	void postavi2(const T2& t2) { pod2 = &t2; }

	const T1& dohvati1() const { return *pod1; }
	const T2& dohvati2() const { return *pod2; }

	friend bool operator==(const Par& p1, const Par& p2) {
		return *p1.pod1 == *p2.pod1 && *p1.pod2 == *p2.pod2;
	}
	friend bool operator!=(const Par& p1, const Par& p2) {
		return !(p1 == p2);
	}

	friend ostream& operator<<(ostream& it, const Par& p) {
		p.pisi(it);
		return it;
	}

protected:
	virtual void pisi(ostream& it) const {
		it << '[' << *pod1 << " - " << *pod2 << ']';
	}

	T1* pod1;
	T2* pod2;

};

#endif