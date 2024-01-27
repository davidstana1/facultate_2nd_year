#include "Smartwatch.h"
#include <iostream>

Smartwatch::Smartwatch() : Dispozitiv("", 0, "", ""),compatibilitate_SO("") {}

Smartwatch::Smartwatch(string nume_proprietar, int data_service, string problema,string complexitate_reparare, string compatibilitate_SO) : Dispozitiv(nume_proprietar, data_service, compatibilitate_SO, problema) {
	this->compatibilitate_SO = compatibilitate_SO;
}

void Smartwatch::afisare() {
	Dispozitiv::afisare();
	cout << "Compatibilitate sistem de operare : " << compatibilitate_SO << endl;
}

istream& operator>>(istream& input, Smartwatch& smartwatch) {
	Dispozitiv& dispozitivBaza = smartwatch;
	input >> dispozitivBaza;
	input >> smartwatch.compatibilitate_SO;
	return input;
}

ostream& operator<<(ostream& output, const Smartwatch& smartwatch) {
	const Dispozitiv& dispozitivBaza = smartwatch;
	output << dispozitivBaza;
	output << "Compatibilitate SO : " << smartwatch.compatibilitate_SO << endl;
	return output;
}