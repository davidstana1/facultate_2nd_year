#include<iostream>
#include<string>
#include<list>
#include<fstream>

#include "all_classes.h"

using namespace std;

void adaugare_electrocasnica(list<Electrocasnice*>& lista_electrocasnice,ifstream& fisier) {
	string producator, tip_arzatoare, tip;
	int pret, nr_programe;
	int opt;


	//cout << "Introduceti ce doriti sa adaugati(Aragaz/Masina Spalat) : ";

	try {
		//cin >> tip;
		fisier >> tip;
			if (tip == "Aragaz")
			{
				/*cout << "Introduceti producator : "; cin >> producator;
				cout << "Introduceti pret : "; cin >> pret;
				cout << "Introduceti tip arzatoare : "; cin >> tip_arzatoare;*/
				fisier >> producator >> pret >> tip_arzatoare;
				Aragaz* aragaz = new Aragaz(producator, pret, tip_arzatoare);
				lista_electrocasnice.push_back(aragaz);
			}
			else if (tip == "Masina")
			{
				/*cout << "Introduceti producator : "; cin >> producator;
				cout << "Introduceti pret : "; cin >> pret;
				cout << "Introduceti numar programe : "; cin >> nr_programe;*/
				fisier >> producator >> pret >> nr_programe;
				MasinaSpalat* masina_spalat = new MasinaSpalat(producator, pret, nr_programe);
				lista_electrocasnice.push_back(masina_spalat);
			}
		else throw(tip);
	}
	catch (string tip) {
		if (tip != "Aragaz" || tip != "Masina")
		cout << "Ati introdus gresit !\n";
		
			
	}
}

void afisare_electrocasnice(list<Electrocasnice*>& lista_electrocasnice) {
	cout << "Afisare electrocasnice : \n";
	for (auto electrocasnic : lista_electrocasnice) {
		electrocasnic->afisare();
		cout << endl;
	}
}

void cautare_aragaz_arzatoare(list<Electrocasnice*>& lista_electrocasnice) {
	string tip_arzator;
	cout << "Tip arzator : ";
	cin >> tip_arzator;
	for (auto aragaz : lista_electrocasnice) {
		Aragaz* aragaz_ = static_cast<Aragaz*>(aragaz);
		if (aragaz_->tip_aragaz == tip_arzator)
			aragaz->afisare();
		cout << endl;
	}
	
}

int main() {
	list<Electrocasnice*> lista_electrocasnice;

	int opt;

	ifstream fisier("fisier.txt");
	if (!fisier) {
		cout << "Eroare la deschiderea fisierului pentru citire! ";
		exit(0);
	}

	while (true) {
		cout << "0.Iesire" << endl;
		cout << "1.Introduceti electrocasnica" << endl;
		cout << "2.Afisare electrocasnice" << endl;
		cout << "3.Cautare aragaz dupa tip_aragaz" << endl;
		cout << "Optiunea dvs : " << endl;
		cin >> opt;
		switch (opt) {
		case 0:
			exit(0);
		case 1:
			adaugare_electrocasnica(lista_electrocasnice,fisier);
			break;
		case 2:
			afisare_electrocasnice(lista_electrocasnice);
			break;
		case 3:
			cautare_aragaz_arzatoare(lista_electrocasnice);
			break;
		default:
			cout << "nu exista aceasta opt ! ";
		}
	}

	fisier.close();
	return 0;
}