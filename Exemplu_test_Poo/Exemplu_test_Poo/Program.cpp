#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<vector>

#include "Produs.h"
#include "Bautura.h"
#include "Prajitura.h"

using namespace std;

void adaugare_produse(list<Produs*>& lista_produse) {
	string nume, tip;
	int pret, gramaj, cantitate;
	vector<string> ingrediente;
	string tip_bautura;
	cout << "Prajitura sau Bautura : ";
	try {
		cin >> tip;
		if (tip == "Prajitura")
		{
			cout << "Nume : "; cin >> nume;
			cout << "Pret : "; cin >> pret;
			cout << "Gramaj (in grame) : "; cin >> gramaj;
			do {
				string ingredient;
				cout << "Ingrediente (introduce stop pentru a opri) : ";
				cin >> ingredient;

				if (ingredient != "stop") {
					ingrediente.push_back(ingredient);
				}
				else
				{
					break;
				}
			} while (true);
			Prajitura* prajitura = new Prajitura(nume, pret, gramaj, ingrediente);
			lista_produse.push_back(prajitura);
		}
		else if (tip == "Bautura") {
			cout << "Nume : "; cin >> nume;
			cout << "Pret : "; cin >> pret;
			cout << "Cantitate (in ml)"; cin >> cantitate;
			try {
				cout << "Tip (cafea/apa/suc)";
				string tipBautura;
				cin >> tipBautura;
				if (tipBautura == "cafea") {
					tip_bautura = tipBautura;
				}
				else if (tipBautura == "apa") {
					tip_bautura = tipBautura;
				}
				else if (tipBautura == "suc") {
					tip_bautura = tipBautura;
				}
				else {
					throw(tip_bautura);
				}
				Bautura* bautura = new Bautura(nume, pret, cantitate, tip_bautura);
				lista_produse.push_back(bautura);
			}
			catch (string b) {
				cout << "Nu ati introdus bine " << endl;
				cout << "Trebuia introdus : " << b;
			}

		}
		else throw(tip);

	}
	catch(string tip){
		if (tip != "Prajitura" || tip != "Bautura")
			cout << "Ati introdus gresit ! " << endl;
}
}

void afisare_produse(list<Produs*>& lista_produse) {
	cout << "Afisare produse : " << endl;
	for (auto produs : lista_produse) {
		produs->afisare();
		cout << endl;
	}
}

void cautare_produs_nume(list<Produs*>& lista_produse) {
	string nume_cautat;
	cout << "Introduceti ce produs doriti sa cautati : ";
	cin >> nume_cautat;
	for (auto produs : lista_produse) {
		if (produs->GetNume() == nume_cautat)
			produs->afisare();
	}
		
}

void afisare_prajituri_fara_zahar(list<Produs*>& lista_produse) {
	for (auto prajituri : lista_produse) {
		bool exist = false;
		Prajitura* prajituri_ = static_cast<Prajitura*>(prajituri);
		for (auto ingredient : prajituri_->ingrediente)
			if (ingredient == "zahar") {
				exist = true;
				break;
			}
		if (exist == false)
			prajituri_->afisare();
	}
	       
}
int total_prajituri = 0;
int total_bauturi = 0;
int suma_totala = 0;
void vanzare_produs(list<Produs*>& lista_produse) {
	string produs_vandut;
	cout << "Produs dorit : ";
	cin >> produs_vandut;
	string tip;

	for (auto it = lista_produse.begin(); it != lista_produse.end();) {
		Produs* produs = *it;
		tip = produs->GetTip();
		if (tip == "Prajitura") {
			Prajitura* prajitura = dynamic_cast<Prajitura*>(produs);
			if (prajitura->GetNume() == produs_vandut) {
				int gramaj;
				cout << "Introduceti cantitatea care o doriti sa o vindeti : ";
				cin >> gramaj;

				if (prajitura->GetGramaj() >= gramaj) { // verific daca am ce vinde
					prajitura->SetGramaj(prajitura->GetGramaj() - gramaj);

					cout << "Vanzare realizata ! " << endl;
					cout << "Produs vandut : " << prajitura->GetNume() << endl;
					cout << "Gramaj vandut : " << gramaj << endl;
					cout << "Pret total : " << (gramaj * prajitura->GetPret()) / 100 << endl;
					cout << "Cantitate ramasa : " << (prajitura->GetGramaj()) << endl;

					total_prajituri += 1;
					suma_totala += gramaj * prajitura->GetPret() / 100;

					if (prajitura->GetGramaj() == 0) {
						cout << "Ati ramas fara prajitura respectiva ! "; //nu merge
						delete* it;
						it = lista_produse.erase(it);
						if (lista_produse.empty()) {
							break;  // Ieșire din buclu dacă lista e goală
						}
					}
					else {
						++it;
					}
				}
			}


		}
		else if (tip == "Bautura") {
			Bautura* bautura = dynamic_cast<Bautura*>(produs);
			if (bautura->GetNume() == produs_vandut) {
				int cantitate;
				cout << "Introduceti cantitatea care o doriti sa o vindeti : ";
				cin >> cantitate;

				if (bautura->GetCantitate() >= cantitate) {
					bautura->SetCantitate(bautura->GetCantitate() - cantitate);

					cout << "Vanzare realizata ! " << endl; 
					cout << "Produs vandut : " << bautura->GetNume() << endl;
					cout << "Cantitate vanduta " << cantitate << endl;
					cout << "Pret total : " << (cantitate * bautura->GetPret()) / 100 << endl;
					cout << "Cantitate ramasa : " << bautura->GetCantitate() << endl;

					total_bauturi += 1;
					suma_totala += cantitate * bautura->GetPret() / 100;

					if (bautura->GetCantitate() == 0) {
						cout << "Ati ramas fara bautura respectiva ! ";
						delete* it;
						it = lista_produse.erase(it);
						if (lista_produse.empty()) {
							break;  // Ieșire din buclu dacă lista e goală
						}
					}
					else {
						++it;
					}
				}
			}
			
		}
		++it;
	}

}

void bilant_vanzari(list<Produs*>& lista_produse) {
	ofstream outFile("bilant_vanzari.txt");
	if (outFile.is_open()) {
		// Scrie numarul total de prajituri, bauturi, suma totala si numarul total de vanzari in fisier
		outFile << total_prajituri << "," << total_bauturi << "," << suma_totala << "," << endl;
		outFile.close();
		cout << "Bilantul vanzarilor a fost scris in fisierul bilant_vanzari.txt.\n";
	}
	else {
		cout << "Nu s-a putut deschide fisierul pentru scrierea bilantului vanzarilor.\n";
	}
}

int main()
{
	list<Produs*> lista_produse;
	int opt;

	while (true) {
		cout << "0.Iesire" << endl;
		cout << "1.Introduceti produs : " << endl;
		cout << "2.Afisare produse : " << endl;
		cout << "3.Cautare dupa nume : " << endl;
		cout << "4.Afisare prajituri care nu contin zahar : " << endl;
		cout << "5.Vanzare produs : ";
		cout << "Introduceti optiunea dvs : " << endl;
		cin >> opt;
		switch (opt) {
		case 0:
			exit(0);
		case 1:
			adaugare_produse(lista_produse);
			break;
		case 2:
			afisare_produse(lista_produse);
			break;
		case 3:
			cautare_produs_nume(lista_produse);
			break;
		case 4:
			afisare_prajituri_fara_zahar(lista_produse);
			break;
		case 5:
			vanzare_produs(lista_produse);
			break;
		case 6:
			bilant_vanzari(lista_produse);
			break;
		}
	}

	return 0;
}