#pragma once
#include "Produs.h"
#include<vector>
class Prajitura : public Produs
{
private:
	int gramaj;
	
public:
	vector<string> ingrediente;
	Prajitura(string, int, int, vector<string>);

	void afisare();
    string GetTip() const override;

	int GetGramaj();
	void SetGramaj(int);

	int GetPret() const override;
};

