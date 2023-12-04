#pragma once
#include "Produs.h"
#include<vector>
class Bautura : public Produs
{
private:
	int cantitate;
	string tip;
public:
	

	Bautura(string, int, int, string);

	void afisare();

	string GetTip() const override;

	int GetPret() const override;

	int GetCantitate();

	void SetCantitate(int);
};

