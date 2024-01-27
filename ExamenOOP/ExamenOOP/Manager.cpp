#include "Manager.h"
#include <iostream>

Manager::Manager() : Utilizatori("", "", "", ""),domeniu_actiune(""),vechime(0) {}

Manager::Manager(string email, string parola, string nume, string prenume, string domeniu_actiune, int vechime) : Utilizatori(email, parola,nume,prenume) {
	this->domeniu_actiune = domeniu_actiune;
	this->vechime = vechime;
}

void Manager::afisare() {
	Utilizatori::afisare();
	cout << "Domeniul de actiune : " << domeniu_actiune << endl << "Vechime : " << vechime << endl;
}

istream& operator>>(istream& is,Manager& manager) {
	Utilizatori& utilizatoriclasaBaza = manager;
	is >> utilizatoriclasaBaza;
	is >> manager.domeniu_actiune >> manager.vechime;
	return is;
}

ostream& operator<<(ostream& os,const Manager& manager) {
	const Utilizatori& utilizatoriclasaBaza = manager;
	os << utilizatoriclasaBaza;
	os << "Domeniu de actiune : " << manager.domeniu_actiune << endl << "Vechime : " << manager.domeniu_actiune << endl;
	return os;
}