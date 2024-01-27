#include "Utilizatori.h"
#include <iostream>

Utilizatori::Utilizatori(string email, string parola,string nume,string prenume) {
	this->email = email;
	this->parola = parola;
	this->nume = nume;
	this->prenume = prenume;
}

void Utilizatori::afisare() {
	cout << "Email : " << email << endl << "Parola : " << parola << endl << "Nume : " << nume << endl << "Prenume : " << prenume << endl;
}

string Utilizatori::getNume() {
	return this->nume;
}

void Utilizatori::setParola(string parola_modificata) {
	this->parola = parola_modificata;
}

string Utilizatori::getEmail() {
	return this->email;
}

bool Utilizatori::operator==(const Utilizatori& other) const {
	return this->email == other.email;
}

istream& Utilizatori::citire(istream& is) {
	is >> email >> parola >> nume >> prenume;
	return is;
}

ostream& Utilizatori::afisare(ostream& os) const {
	os << "Email: " << email << "\nParola: " << parola << "\nNume: " << nume << "\nPrenume: " << prenume << "\n";
	return os;
}

istream& operator>>(istream& is, Utilizatori& utilizator) {
	return utilizator.citire(is);
}

ostream& operator<<(std::ostream& os, const Utilizatori& utilizator) {
	return utilizator.afisare(os);
}
