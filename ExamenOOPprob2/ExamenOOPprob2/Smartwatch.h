#pragma once
#include "Dispozitiv.h"
class Smartwatch : public Dispozitiv
{
private:
	string compatibilitate_SO;
public:
	Smartwatch();

	Smartwatch(string, int, string, string, string);

	void afisare();

	friend istream& operator>>(istream& input, Smartwatch& smartwatch);
	friend ostream& operator<<(ostream& output, const Smartwatch& smartwatch);
};

