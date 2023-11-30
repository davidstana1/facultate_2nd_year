#pragma once
#include "Electrocasnice.h"
class Aragaz : public Electrocasnice
{
public:
	string tip_aragaz;
	Aragaz(string, int, string);

	void afisare();

	string tip() const override;
};

