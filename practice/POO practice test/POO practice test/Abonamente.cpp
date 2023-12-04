#include "Abonamente.h"

Abonamente::Abonamente(string data_creare,string nume,int CNP,int pret) {
	this->data_creare = data_creare;
	this->nume = nume;
	this->CNP = CNP;
	this->pret = pret;
}

void Abonamente::afisare() {
	cout << "Data creare : " << data_creare << endl << "Nume : " << nume << endl << "CNP : " << CNP << endl << "Pret : " << pret << endl;
}

string Abonamente::GetTipAbonament() const {
	return "Abonament";
}

string Abonamente::GetNume() const {
	return this->nume;
}