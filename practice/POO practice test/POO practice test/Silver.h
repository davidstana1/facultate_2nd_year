#pragma once
#include "Abonamente.h"
#include<vector>
class Silver : public Abonamente
{
	public:
		string interval_orar;
public:
	Silver(string, string, int, int, string );

	void afisare();

	string GetTipAbonament() const override;

	int GetPret();
};

