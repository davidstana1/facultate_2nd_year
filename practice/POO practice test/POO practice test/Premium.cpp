#include "Premium.h"

Premium::Premium(string data_creare, string nume, int CNP, int pret,int ore_aerobic) : Abonamente(data_creare, nume, CNP, pret) {
	this->ore_aerobic = ore_aerobic;
}

void Premium::afisare() {
	Abonamente::afisare();
	cout << "Ore aerobic : " << ore_aerobic<<endl;
}

string Premium::GetTipAbonament() const {
	return "Premium";
}

void Premium::contorizare() {
	this->ore_aerobic -= 1;
}

int Premium::GetPret() {
	return this->pret;
}