#include "Produs.h"

Produs::Produs(string nume, int pret) {
	this->nume = nume;
	this->pret = pret;
}

void Produs::afisare() {
	cout << "Nume : " << nume << endl << "Pret : " << pret<<endl;
}

string Produs::GetTip() const {
	return "Produs";
}

string Produs::GetNume() const {
	return nume;
}

int Produs::GetPret() const{
	return pret;
}