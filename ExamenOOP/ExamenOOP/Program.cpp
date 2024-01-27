#include<iostream>
#include<list>
#include<fstream>
#include "Manager.h"
#include "User.h"
#include "Utilizatori.h"
using namespace std;

bool utilizatorExista(const list<Utilizatori*>& lista_utilizatori, const string& email) {
	for (const auto& utilizator : lista_utilizatori) {
		if (utilizator->getEmail() == email) {
			return true;  // Utilizatorul există deja în listă
		}
	}
	return false;  // Utilizatorul nu există în listă
}

//ii pentru daca nu folosesc override operator

void adaugare_utilizatori(list<Utilizatori*>& lista_utilizatori, ifstream& fisier) {
	string email, parola, nume, prenume, adresa,domeniu_actiune;
	int varsta,vechime;
	string tip_utilizator;

	fisier.clear();
	fisier.seekg(0, ios::cur);   //asta e pentru sa citesc tot din nou, but not good pt ca am chestia cu emailul
	

	while(fisier>>tip_utilizator)
	{
	try {

		if (tip_utilizator == "user") {
			User* user = new User();
			fisier >> *user;
			if (!utilizatorExista(lista_utilizatori, email)) {
				lista_utilizatori.push_back(user);
			}
			else {
				cout << "Utilizatorul cu email-ul " << email << " exista deja in lista. Adaugare omisa.\n";
			}
		}
		else if (tip_utilizator == "manager") {
			Manager* manager = new Manager();
			fisier >> *manager;
			if (!utilizatorExista(lista_utilizatori, email)) {
				lista_utilizatori.push_back(manager);
			}
			else {
				cout << "Utilizatorul cu email-ul " << email << " exista deja in lista. Adaugare omisa.\n";
			}
		}
		else { throw tip_utilizator; }
		
	}
	catch (string a) {
		cout << "Ati introdus gresit ! ";
		cout << "Ati introdus : " << a << endl;
	}
	}
}

void afisare_utilizatori(list<Utilizatori*>& lista_utilizatori) {
	for (auto user : lista_utilizatori) {
		user->afisare();
		cout << endl;
		/*if (typeid(*user) == typeid(User)) {
			cout << *user;
			cout << endl;
		}*/
	}
}

void cautare_utilizator(list<Utilizatori*>& lista_utilizatori) {
	string nume_cautat;
	cout << "Introduceti numele : ";
	cin >> nume_cautat;
	for (auto utilizator : lista_utilizatori) {
		if (utilizator->getNume() == nume_cautat) {
			utilizator->afisare();
			cout << endl;
		}
	}
}

void stergere_utilizator(list<Utilizatori*>& lista_utilizatori) {
	string email_cautat;
	cout << "Introduceti email : "; cin >> email_cautat;

	for (auto it = lista_utilizatori.begin(); it != lista_utilizatori.end();) {
		if (email_cautat == (*it)->getEmail()) {
			delete* it;
			it = lista_utilizatori.erase(it);
		}
		else ++it;
	}
}

void modificare_parola(list<Utilizatori*>& lista_utilizatori) {
	string email_cautat, parola_noua;
	cout << "Introduceti email-ul : ";
	cin >> email_cautat;
	cout << "Introduceti parola noua : ";
	cin >> parola_noua;
	for (auto utilizator : lista_utilizatori) {
		if (utilizator->getEmail() == email_cautat) {
			utilizator->setParola(parola_noua);
		}
	}
	cout << "Parola a fost modificata cu succes ! ";
}

int main() {
	list<Utilizatori*> lista_utilizatori;
	int optiune;
	ifstream fisier("fisier.txt");

	if (!fisier) {
		cout << "Fisier not working ! ";
		exit(0);
	}


	while (1) {
		cout << "\n0.Iesire\n";
		cout << "1.Adaugare utilizator\n";
		cout << "2.Afisare utilizatori\n";
		cout << "3.Cautare utilizator dupa nume\n";
		cout << "4.Stergere utilizator dupa email\n";
		cout << "5.Modificare parola\n";
		cout << "Introduceti optiunea : ";
		cin >> optiune;
		switch (optiune) {
		case 0:
			exit(0);
		case 1:
				adaugare_utilizatori(lista_utilizatori, fisier);
			break;
		case 2:
			afisare_utilizatori(lista_utilizatori);
			break;
		case 3:
			cautare_utilizator(lista_utilizatori);
			break;
		case 4:
			stergere_utilizator(lista_utilizatori);
			break;
		case 5:
			modificare_parola(lista_utilizatori);
			break;
		default:
			cout << "Nu exista optiunea aceasta ! ";
		}
	}


	return 0;
}