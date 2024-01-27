#pragma once
#include <string>
using namespace std;

class Dispozitiv
{
private:
	string nume_proprietar;
	int data_service;
	string complexitate_reparare;
	string problema;
public:
	Dispozitiv(string, int, string, string);

	virtual void afisare();

	string getNumeProprietar() const;

	void setProblema(string problema);

	virtual istream& citire(istream&);
	virtual ostream& afisaresmek(ostream&) const;

	friend istream& operator>>(istream& is, Dispozitiv& dispozitiv);
	friend ostream& operator<<(ostream& os,const Dispozitiv& dispozitiv);
};

