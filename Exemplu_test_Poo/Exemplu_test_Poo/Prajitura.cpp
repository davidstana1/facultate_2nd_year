#include "Prajitura.h"

Prajitura::Prajitura(string nume, int pret, int gramaj, vector<string> ingrediente) : Produs(nume, pret) {
	this->gramaj = gramaj;
	this->ingrediente = ingrediente;
}

void Prajitura::afisare() {
	Produs::afisare();
	cout << "Gramaj : " << gramaj << " g"<< endl << "Ingrediente : ";
	for (auto ingredient : ingrediente) {
		cout << ingredient << ", ";
	}
	cout << endl;
}

string Prajitura::GetTip() const {
	return "Prajitura";
}

int Prajitura::GetGramaj() {
	return gramaj;
}

void Prajitura::SetGramaj(int gramaj) {
	this->gramaj = gramaj;
}

int Prajitura::GetPret() const{
	return pret;
}