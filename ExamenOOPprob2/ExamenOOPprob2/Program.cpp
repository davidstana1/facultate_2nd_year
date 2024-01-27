#include<iostream>
#include<list>
#include<fstream>
#include"Dispozitiv.h"
#include"Smartwatch.h"
#include"Telefon.h"

using namespace std;

void adaugare_dispozitive(list<Dispozitiv*>& lista_dispozitive, ifstream& fisier) {
	string nume_proprietar, complexitate_reparare, problema, compatibilitate_SO,compatibilitate_SO_bun;
	int data_service, diagonala_ecran;
	string tip_dispozitiv;
	string complexitate_reparare_bun;

	fisier.clear();
	fisier.seekg(0, ios::cur);

	while (fisier >> tip_dispozitiv) {
		try {
			if (tip_dispozitiv == "Telefon") {
				/*fisier >> nume_proprietar >> data_service >> problema >> diagonala_ecran;
				try {
					fisier >> complexitate_reparare;
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
				}
				Telefon* telefon = new Telefon(nume_proprietar, data_service, problema, diagonala_ecran, complexitate_reparare_bun);
				lista_dispozitive.push_back(telefon);*/
				Telefon* telefon = new Telefon();
				fisier >> *telefon;
				lista_dispozitive.push_back(telefon);
			}
			else if (tip_dispozitiv == "Smartwatch") {
				/*fisier >> nume_proprietar >> data_service >> problema;
				try {
					fisier >> complexitate_reparare;
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
				}
				try {
					fisier >> compatibilitate_SO;
					if (compatibilitate_SO == "Android")
						compatibilitate_SO_bun = compatibilitate_SO;
					else if (compatibilitate_SO == "IOS")
						compatibilitate_SO_bun = compatibilitate_SO;
					else if (compatibilitate_SO == "Android-IOS")
						compatibilitate_SO_bun = compatibilitate_SO;
					else { throw compatibilitate_SO; }
				}
				catch (string c) {
					cout << "Ati introdus : " << c;
					cout << "Trebuia introdus : Android , IOS sau Android-IOS";
				}
				Smartwatch* smartwatch = new Smartwatch(nume_proprietar, data_service, problema, complexitate_reparare_bun, compatibilitate_SO_bun);
				lista_dispozitive.push_back(smartwatch);*/
				Smartwatch* smartwatch = new Smartwatch();
				fisier >> *smartwatch;
				lista_dispozitive.push_back(smartwatch);
			}
		}
		catch (string a) {
			cout << "Ati introdus : " << a;
			cout << "Trebuia introdus : Telefon sau Smartwatch";
		}
	}

}

void afisare_dispozitive(list<Dispozitiv*>& lista_dispozitive) {
	for (auto dispozitive : lista_dispozitive) {
		dispozitive->afisare();
		cout << endl;
	}
}

void cautare_telefoane_dupa_diagonala(list<Dispozitiv*>& lista_dispozitive) {
	int diagonala_cautata;
	cout << "Introduceti diagonala : ";
	cin >> diagonala_cautata;
	for (auto dispozitiv : lista_dispozitive) {
		Telefon* telefon = static_cast<Telefon*>(dispozitiv);
		if (telefon->getDiagonalaEcran() == diagonala_cautata) {
			telefon->afisare();
			cout << endl;
		}
	}
}

void ridicare_dispozitiv_dupa_nume(list<Dispozitiv*>& lista_dispozitive) {
	string nume;
	cout << "Introduceti numele : ";
	cin >> nume;
	for (auto it = lista_dispozitive.begin(); it != lista_dispozitive.end();) {
		if ((*it)->getNumeProprietar() == nume) {
			delete* it;
			it = lista_dispozitive.erase(it);
		}
		else ++it;
	}
	cout << "Dispozitivul a fost ridicat ! ";
}

void modificare_problema_dispozitiv(list<Dispozitiv*>& lista_dispozitive) {
	string nume, problema_noua;
	cout << "Introduceti nume : ";
	cin >> nume;
	cout << "Introduceti problema : ";
	cin >> problema_noua;
	for (auto dispozitiv : lista_dispozitive) {
		if (dispozitiv->getNumeProprietar() == nume) {
			dispozitiv->setProblema(problema_noua);
		}
	}
	cout << "Actualizare reusita ! \n";
}

bool comparaTelefoane(const Dispozitiv* tel1, const Dispozitiv* tel2) {
	return tel1->getNumeProprietar() < tel2->getNumeProprietar();
}

void afisare_alfabetica(const list<Dispozitiv*>& lista_dispozitive) {
	list<Dispozitiv*> copie_lista = lista_dispozitive;
	copie_lista.sort(comparaTelefoane);

	cout << "Afisare in ordine alfabetica:\n";
	afisare_dispozitive(copie_lista);
}


int main() {
	list<Dispozitiv*> lista_dispozitive;
	int optiune;
	ifstream fisier("fisier.txt");
	if (!fisier) {
		cout << "Error la fisier !";
		exit(0);
	}


	while (1) {
		cout << "\n1.Adaugare dispozitive\n";
		cout << "2.Afisare dispozitive\n";
		cout << "3.Cautare telefoane dupa diagonala ecranului\n";
		cout << "4.Modificarea descrierii problemei unui produs\n";
		cout << "5.Afisare in ordine alfabetica a telefoanelor dupa numele proprietarilor\n";
		cout << "6.Ridicare dispozitiv dupa nume\n";
		cout << "Introduceti optiunea dorita : ";
		cin >> optiune;
		switch (optiune) {
		case 0:
			exit(0);
		case 1:
			adaugare_dispozitive(lista_dispozitive,fisier);
			break;
		case 2:
			afisare_dispozitive(lista_dispozitive);
			break;
		case 3:
			cautare_telefoane_dupa_diagonala(lista_dispozitive);
			break;
		case 4:
			modificare_problema_dispozitiv(lista_dispozitive);
			break;
		case 5:
			afisare_alfabetica(lista_dispozitive);
			break;
		case 6:
			ridicare_dispozitiv_dupa_nume(lista_dispozitive);
			break;
		default:
			cout << "no good";
		}
	}

	return 0;
}