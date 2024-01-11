#include "Cercei.h"
#include <iostream>

Cercei::Cercei(int pret, int cod_bijuterie, int lungime, string material, string tip_inchizatoare) : Bijuterii(pret,cod_bijuterie,lungime,material) {
	this->tip_inchizatoare = tip_inchizatoare;
}

void Cercei::afisare() {
	Bijuterii::afisare();
	cout << "Tip inchizatoare : " <<tip_inchizatoare<< endl;
}

string Cercei::getTipInchizatoare() {
	return this->tip_inchizatoare;
}