#include "Aragaz.h"

Aragaz::Aragaz(string producator, int pret, string tip_aragaz) : Electrocasnice(producator, pret) {
	this->tip_aragaz = tip_aragaz;
}

void Aragaz::afisare() {
	Electrocasnice::afisare();
	cout << tip_aragaz << endl;
}

string Aragaz::tip() const {
	return "Aragaz";
}