#include "Telefon.h"
#include <iostream>

Telefon::Telefon() : Dispozitiv("", 0, "", ""), diagonala_ecran(0){}

Telefon::Telefon(string nume_proprietar, int data_service,string problema, int diagonala_ecran,string complexitate_reparare) : Dispozitiv(nume_proprietar, data_service, complexitate_reparare, problema) {
	this->diagonala_ecran = diagonala_ecran;
}

void Telefon::afisare() {
	Dispozitiv::afisare();
	cout << "Diagonala ecran : " << diagonala_ecran << endl;
}

int Telefon::getDiagonalaEcran() {
	return this->diagonala_ecran;
}

istream& operator>>(istream& input, Telefon& telefon) {
	Dispozitiv& dispozitivBaza = telefon;
	input >> dispozitivBaza;
	input >> telefon.diagonala_ecran;
	return input;
}

ostream& operator<<(ostream& output,const Telefon& telefon) {
	const Dispozitiv& dispozitivBaza = telefon;
	output << dispozitivBaza;
	output << "Diagonala ecran : " << telefon.diagonala_ecran << endl;
	return output;
}