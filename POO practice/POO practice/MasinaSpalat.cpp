#include "MasinaSpalat.h"

MasinaSpalat::MasinaSpalat(string producator, int pret, int nr_programe) : Electrocasnice(producator, pret) {
	this->nr_programe = nr_programe;
}

void MasinaSpalat::afisare() {
	Electrocasnice::afisare();
	cout << nr_programe << endl;
}

string MasinaSpalat::tip() const{
	return "Masina spalat";
}