#include "Silver.h"

Silver::Silver(string data_creare, string nume, int CNP, int pret, string interval) : Abonamente(data_creare, nume, CNP, pret) {
	this->interval_orar = interval;
}

void Silver::afisare() {
	Abonamente::afisare();
	cout << "Interval orar : " << interval_orar<<endl;
	
}

string Silver::GetTipAbonament() const {
	return "Silver";
}

int Silver::GetPret() {
	return this->pret;
}