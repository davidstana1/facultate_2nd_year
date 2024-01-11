#include<iostream>
#include<list>
#include<fstream>
#include "Bijuterii.h"
#include "Cercei.h"
#include "Lantisor.h"

using namespace std;

void adaugare_bijuterie(list<Bijuterii*>& lista_bijuterii,ifstream& fisier) {
	int pret, cod_bijuterie, lungime;
	string tip_inchizatoare, tip_piatra, material, tip;
	string material_bun, tip_inchizatoare_bun,tip_piatra_bun;
	
	try {
		fisier >> tip;

			if (tip == "Cercei") {
				fisier >> pret >> cod_bijuterie >> lungime;
				try {
					fisier >> material;
					if (material == "AurGalben")
						material_bun = material;
					else if (material == "AurAlb")
						material_bun = material;
					else if (material == "Argint")
						material_bun = material;
					else { throw(material); }
				}
				catch (string a) {
					cout << "Nu ati introdus bine materialul ! \n";
					cout << "Ati introdus : " << a << endl;
				}
				try {
					fisier >> tip_inchizatoare;
					if (tip_inchizatoare == "Arc")
						tip_inchizatoare_bun = tip_inchizatoare;
					else if (tip_inchizatoare == "Carlig")
						tip_inchizatoare_bun = tip_inchizatoare;
					else if (tip_inchizatoare == "Surub")
						tip_inchizatoare_bun = tip_inchizatoare;
					else { throw(tip_inchizatoare); }
				}
				catch (string b) {
					cout << "Nu ati introdus bine tip inchizatoare ! \n";
					cout << "Ati introdus : " << b << endl;
				}
				Cercei* cercei = new Cercei(pret, cod_bijuterie, lungime, material_bun, tip_inchizatoare_bun);
				lista_bijuterii.push_back(cercei);
				cout << "Ati introdus cerceii ! ";
			}
			else if (tip == "Lantisor") {
				fisier >> pret >> cod_bijuterie >> lungime;
				try {
					fisier >> material;
					if (material == "AurGalben")
						material_bun = material;
					else if (material == "AurAlb")
						material_bun = material;
					else if (material == "Argint")
						material_bun = material;
					else { throw(material); }
				}
				catch (string a) {
					cout << "Nu ati introdus bine materialul ! \n";
					cout << "Ati introdus : " << a << endl;
				}
				try {
					fisier >> tip_piatra;
					if (tip_piatra == "Ametist")
						tip_piatra_bun = tip_piatra;
					else if (tip_piatra == "Obsidian")
						tip_piatra_bun = tip_piatra;
					else if (tip_piatra == "Perla")
						tip_piatra_bun = tip_piatra;
					else { throw(tip_piatra); }
				}
				catch (string c) {
					cout << "Nu ati introdus bine tip piatra : \n";
					cout << "Ati introdus : " << c << endl;
				}
				Lantisor* lantisor = new Lantisor(pret, cod_bijuterie, lungime, material_bun, tip_piatra_bun);
				lista_bijuterii.push_back(lantisor);
				cout << "Ati introdus lantisorul ! ";
			}
			else { throw(tip); }
	}
	catch (string d) {
		cout << "Nu ati introdus bine tipul bijuterie ! ";
		cout << "Ati introdus" << d << endl;
	}
}

void afisare_bijuterii(list<Bijuterii*>& lista_bijuterii) {
	cout << "Afisare bijuterii : \n";
	for (auto bijuterii : lista_bijuterii) {
		bijuterii->afisare();
		cout << endl;
	}
}

void cautare_bijuterie_material(list<Bijuterii*>& lista_bijuterii) {
	string material;
	cout << "Introduceti material : ";
	cin >> material;
	for (auto bijuterii : lista_bijuterii) {
		if (material == bijuterii->getMaterial()) {
			bijuterii->afisare();
			cout << endl;
		}
	}
}

void afisare_cercei_tip_inchizatoare(list<Bijuterii*>& lista_bijuterii) {
	string tip_inchizatoare;
	cout << "Introduceti tip inchizatoare : ";
	cin >> tip_inchizatoare;
	for (auto bijuterii : lista_bijuterii) {
		Cercei* cercei = static_cast<Cercei*>(bijuterii);
		if (tip_inchizatoare == cercei->getTipInchizatoare()) {
			cercei->afisare();
			cout << endl;
		}
	}
}

void vanzare_bijuterie_cod(list<Bijuterii*>& lista_bijuterii) {
	int cod;
	cout << "Introduceti codul : ";
	cin >> cod;

	for (auto it = lista_bijuterii.begin();it != lista_bijuterii.end();) {
		if (cod == (*it)->getCod()) {
			if (Lantisor* lantisor = dynamic_cast<Lantisor*>(*it)) {
				if (lantisor->getTipPiatra() == "Perla") {
					Lantisor::incrementarePerle();
				}
			}
			delete* it;
			it = lista_bijuterii.erase(it);
		}
		else ++it;
	}
}

void aplicare_reducere_bijuterii_argint(list<Bijuterii*>& lista_bijuterii) {
	int pret;
	for (auto bijuterii : lista_bijuterii) {
		if (bijuterii->getMaterial() == "Argint") {
			pret = bijuterii->getPret() - (0.1 * bijuterii->getPret());
			bijuterii->setPret(pret);
		}
	}
}


int main() {
	list<Bijuterii*> lista_bijuterii;
	int opt;
	ifstream fisier("fisier.txt");
	if (!fisier) {
		cout << "Eroare la deschiderea fisierului ! ";
		exit(0);
	}

	while (1) {
		cout << "\n0.Iesire\n";
		cout << "1.Adaugare bijuterie\n";
		cout << "2.Afisare bijuterii\n";
		cout << "3.Cautare bijuterie dupa material\n";
		cout << "4.Afisare cercei dupa tip inchizatoare\n";
		cout << "5.Vanzare bijuterie cod\n";
		cout << "6.Reducere bijuterii argint\n";
		cout << "7.Cate s-au vandut cu perle ?\n";
		cout << "Introduceti optiunea : ";
		cin >> opt;
		switch (opt) {
		case 0:
			exit(0);
		case 1:
			adaugare_bijuterie(lista_bijuterii, fisier);
			break;
		case 2:
			afisare_bijuterii(lista_bijuterii);
			break;
		case 3:
			cautare_bijuterie_material(lista_bijuterii);
			break;
		case 4:
			afisare_cercei_tip_inchizatoare(lista_bijuterii);
			break;
		case 5:
			vanzare_bijuterie_cod(lista_bijuterii);
			break;
		case 6:
			aplicare_reducere_bijuterii_argint(lista_bijuterii);
			break;
		case 7:
			cout<<Lantisor::getNumarPerleVandute();
			break;
		}
	}
	return 0;
}