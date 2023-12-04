#pragma once
#include "Abonamente.h"
class Premium : public Abonamente
{
private:
	int ore_aerobic;
public:
	Premium(string, string, int, int,int);

	void afisare();

	string GetTipAbonament() const override;

	void contorizare();

	int GetPret();
};

