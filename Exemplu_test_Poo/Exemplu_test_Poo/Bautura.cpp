#include "Bautura.h"

Bautura::Bautura(string nume, int pret, int cantitate, string tip) : Produs(nume, pret) {
	this->cantitate = cantitate;
	this->tip = tip;
}

void Bautura::afisare() {
	Produs::afisare();
	cout << "Cantitate : " << cantitate << " ml" << endl << "Tip : " << tip << endl;
}

string Bautura::GetTip() const {
	return "Bautura";
}

int Bautura::GetPret() const {
	return pret;
}

int Bautura::GetCantitate() {
	return cantitate;
}

void Bautura::SetCantitate(int cantitate) {
	this->cantitate = cantitate;
}