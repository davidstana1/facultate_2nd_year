#include "User.h"
#include <iostream>

User::User() : Utilizatori("", "", "", ""), varsta(0), adresa("") {}

User::User(string email, string parola, string nume, string prenume, int varsta, string adresa) : Utilizatori(email, parola,nume,prenume) {
	this->varsta = varsta;
	this->adresa = adresa;
}

void User::afisare() {
	Utilizatori::afisare();
	cout <<"Varsta : " << varsta << endl << "Adresa : " << adresa << endl;
}

istream& operator>>(std::istream& is,User& user) {
	Utilizatori& UtilizatoriClasaBaza = user;
	is >> UtilizatoriClasaBaza;
	is >> user.varsta >> user.adresa;
	return is;
}

ostream& operator<<(std::ostream& os,const User& user) {
	const Utilizatori& utilizatoriBaza = user; // Afisarea datelor din clasa de baza
	os << utilizatoriBaza;
	os << "Varsta : " << user.varsta<< "\nAdresa : " <<user.adresa<< endl;
	return os;
}