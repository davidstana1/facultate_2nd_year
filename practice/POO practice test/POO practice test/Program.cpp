#include<iostream>
#include<list>
#include<fstream>

#include "Abonamente.h"
#include "Silver.h"
#include "Premium.h"

using namespace std;

int total_abonamente_silver = 0;
int total_abonamente_premium = 0;
int suma_totala = 0;

void inregistrare_abonament(list<Abonamente*>& lista_abonamente) {
	int CNP, pret, ore_aerobic = 6;
	string nume, interval_orar, tip, data_creare;

	try {
		cout << "Silver sau Premium ? \n";
		cin >> tip;
		if (tip == "Silver") {
			cout << "Introduceti data creare : ";cin >> data_creare;
			cout << "Introduceti nume : ";cin >> nume;
			cout << "Introduceti CNP : ";cin >> CNP;
			cout << "Introduceti pret : ";cin >> pret;
			cout << "Introduceti interval orar : " << endl;
			cout << "Alegeti dintre 8-12,12-16,14-18" << endl;
			try {
				string interval;
				cin >> interval;
				if (interval == "8-12")
					interval_orar = interval;
				else if (interval == "12-16")
					interval_orar = interval;
				else if (interval == "14-18")
					interval_orar = interval;
				else { throw(interval_orar); }
				Silver* silver = new Silver(data_creare, nume, CNP, pret, interval_orar);
				lista_abonamente.push_back(silver);
				total_abonamente_silver += 1;
				suma_totala += silver->GetPret();
			}
			catch (string b) {
				cout << "Nu ati introdus bine ! ";
			}

		}
		else if (tip == "Premium") {
			cout << "Introduceti data creare : ";cin >> data_creare;
			cout << "Introduceti nume : ";cin >> nume;
			cout << "Introduceti CNP : ";cin >> CNP;
			cout << "Introduceti pret : ";cin >> pret;
			Premium* premium = new Premium(data_creare, nume, CNP, pret, ore_aerobic);
			lista_abonamente.push_back(premium);
			total_abonamente_premium += 1;
			suma_totala += premium->GetPret();
		}
		else throw(tip);
		}
	catch (string tip) {
		if (tip != "Silver" || tip != "Premium")
			cout << "Ati introdus gresit ! " << endl;
	}
}

void afisare_abonamente(list<Abonamente*>& lista_abonamente) {
	cout << "Afisare abonamente : ";
	for (auto abonament : lista_abonamente) {
		abonament->afisare();
	}
}
	
void cautare_abonament_nume(list<Abonamente*>& lista_abonamente) {
	cout << "Introduceti nume : ";
	string nume_cautat;
	cin >> nume_cautat;
	for (auto abonament : lista_abonamente)
		if (nume_cautat == abonament->GetNume())
			abonament->afisare();
}

void cautare_abonament_interval_orar(list<Abonamente*>& lista_abonamente) {
	cout << "Introduceti interval orar";
	string interval;
	cin >> interval;
	
	for (auto abonament : lista_abonamente) {
		Silver* silver = static_cast<Silver*>(abonament);
		if (silver->interval_orar == interval)
			silver->afisare();
	}
}

void contorizare_abonament_premium(list<Abonamente*>& lista_abonamente) {
	cout << "Introduceti nume : ";
	string nume_cautat;
	cin >> nume_cautat;
	for (auto abonament : lista_abonamente) {
		Premium* premium = static_cast<Premium*>(abonament);
		if (premium->GetNume() == nume_cautat)
			premium->contorizare();
	}
}

void bilant(list<Abonamente*>& lista_abonamente) {
	ofstream outFile("bilant.txt");
	if (outFile.is_open()) {
		outFile << total_abonamente_silver << " " << total_abonamente_premium << " " << suma_totala;
		cout << "Bilantul vanzarilor a fost scris in fisierul bilant_vanzari.txt.\n";
	}
	else {
		cout << "Nu s-a putut deschide fisierul pentru scrierea bilantului vanzarilor.\n";
	}
}

int main() {
	list<Abonamente*> lista_abonamente;
	int opt;

	while (true) {
		cout << "\n0.Iesire" << endl;
		cout << "1.Adaugare abonament" << endl;
		cout << "2.Afisare abonamente" << endl;
		cout << "3.Cautare abonament nume " << endl;
		cout << "4.Cautare abonament silver interval orar" << endl;
		cout << "5.Contorizare abonament" << endl;
		cout << "6.Bilant";
		cout << "Introduceti optiunea : ";
		cin >> opt;
		switch (opt) {
		case 0:
			exit(0);
		case 1:
			inregistrare_abonament(lista_abonamente);
			break;
		case 2:
			afisare_abonamente(lista_abonamente);
			break;
		case 3:
			cautare_abonament_nume(lista_abonamente);
			break;
		case 4:
			cautare_abonament_interval_orar(lista_abonamente);
			break;
		case 5:
			contorizare_abonament_premium(lista_abonamente);
			break;
		case 6:
			bilant(lista_abonamente);
			break;
		default:
			cout << "Nu exista aceasta optiune ! ";
		}
	}


	return 0;
}