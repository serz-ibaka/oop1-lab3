#include <iostream>
#include "operand.h"
#include "sabiranje.h"
#include "oduzimanje.h"
#include "mnozenje.h"
#include "deljenje.h"
#include "levazagrada.h"
#include "desnazagrada.h"
#include "lista.h"
#include "izraz.h"
#include "postfiksgenerator.h"

using namespace std;

int main() {
	Sabiranje s;
	Oduzimanje o;
	Mnozenje m;
	Deljenje d;
	LevaZagrada l;
	DesnaZagrada z;

	Izraz i;

	Operand a("a");
	Operand b("b");
	Operand c("c");

	//((((((i += l) += a) += s) += b) += z) += m ) += c;
	
	i += a;
	i += m;
	i += l;
	i += b;
	i += d;
	i += l;
	i += c;
	i += s;
	i += a;
	i += z;
	i += z;

	Izraz ii;

	ii = i;

	cout << ii << endl;

	PostfiksGenerator& g = PostfiksGenerator::generator();

	Izraz pf = g(ii);

	cout << pf << endl;

	return 0;
}