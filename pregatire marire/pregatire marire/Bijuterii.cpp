#include "Bijuterii.h"
#include <iostream>

Bijuterii::Bijuterii(int pret, int cod_bijuterie, int lungime, string material) {
	this->pret = pret;
	this->cod_bijuterie = cod_bijuterie;
	this->lungime = lungime;
	this->material = material;
}

void Bijuterii::afisare() {
	cout << "Pret : " << pret << endl << "Cod bijuterie : " << cod_bijuterie << endl << "Lungime : " << lungime << endl << "Material : " << material << endl;
}

string Bijuterii::getMaterial() {
	return this->material;
}

int Bijuterii::getCod() {
	return this->cod_bijuterie;
}

int Bijuterii::getPret() {
	return this->pret;
}

void Bijuterii::setPret(int x) {
	this->pret = x;
}