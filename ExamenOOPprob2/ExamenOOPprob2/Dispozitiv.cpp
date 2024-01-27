#include "Dispozitiv.h"
#include <iostream>


Dispozitiv::Dispozitiv(string nume_proprietar, int data_service, string complexitate_reparare, string problema) {
	this->nume_proprietar = nume_proprietar;
	this->data_service = data_service;
	this->complexitate_reparare = complexitate_reparare;
	this->problema = problema;
}

void Dispozitiv::afisare() {
	cout << "Nume proprietar : " << nume_proprietar << "\nData in care a fost preluat de service : " << data_service << "\nComplexitate reparare : " << complexitate_reparare << "\nProblema : " << problema<<endl;
}

string Dispozitiv::getNumeProprietar() const {
	return this->nume_proprietar;
}

void Dispozitiv::setProblema(string problema){
	this->problema = problema;
}

istream& Dispozitiv::citire(istream& is) {
	string complexitate_reparare_bun;
	is >> nume_proprietar >> data_service;
	try {
		is >> complexitate_reparare;
		if (complexitate_reparare == "mica")
			complexitate_reparare_bun = complexitate_reparare;
		else if (complexitate_reparare == "medie")
			complexitate_reparare_bun = complexitate_reparare;
		else if (complexitate_reparare == "mare")
			complexitate_reparare_bun = complexitate_reparare;
		else { throw complexitate_reparare; }
	}
	catch (string b) {
		cout << "Ati introdus " << b;
		cout << "Trebuia introdus mica,medie sau mare";
		exit(0);
	}
	is >> problema;
	return is;
}

ostream& Dispozitiv::afisaresmek(ostream& os) const {
	os<< "Nume proprietar : " << nume_proprietar << "\nData in care a fost preluat de service : " << data_service << "\nComplexitate reparare : " << complexitate_reparare << "\nProblema : " << problema << endl;
	return os;
}

istream& operator>>(istream& is, Dispozitiv& dispozitiv) {
	return dispozitiv.citire(is);
}

ostream& operator<<(ostream& os,const Dispozitiv& dispozitiv) {
	return dispozitiv.afisaresmek(os);
}