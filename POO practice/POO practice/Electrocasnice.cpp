#include "Electrocasnice.h"
Electrocasnice::Electrocasnice(string producator,int pret) {
	this->producator = producator;
	this->pret = pret;
}

void Electrocasnice::afisare() {
	cout << producator << endl << pret << endl;
}

string Electrocasnice::tip() const {
	return "Electrocasnica";
}