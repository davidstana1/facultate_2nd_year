#include "Lantisor.h"
#include <iostream>

Lantisor::Lantisor(int pret, int cod_bijuterie, int lungime, string material, string tip_piatra) : Bijuterii(pret, cod_bijuterie, lungime, material) {
	this->tip_piatra = tip_piatra;
}

void Lantisor::afisare() {
	Bijuterii::afisare();
	cout << "Tip piatra : " << tip_piatra << endl;
}

int Lantisor::perleVandute = 0;

void Lantisor::incrementarePerle() {
	perleVandute++;
}

int Lantisor::getNumarPerleVandute() {
	return perleVandute;
}

string Lantisor::getTipPiatra() {
	return this->tip_piatra;
}