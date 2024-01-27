#pragma once
#include "Dispozitiv.h"
class Telefon : public Dispozitiv
{
private:
	int diagonala_ecran;
public:
	Telefon();

	Telefon(string,int, string, int, string);

	void afisare();

	int getDiagonalaEcran();

	friend istream& operator>>(istream& input, Telefon& telefon);
	friend ostream& operator<<(ostream& output, const Telefon& telefon);
};

