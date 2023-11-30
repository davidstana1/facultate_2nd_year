#pragma once
#include "Electrocasnice.h"
class MasinaSpalat : public Electrocasnice
{
private:
	int nr_programe;
public:
	MasinaSpalat(string, int, int);

	void afisare();
	string tip() const override;
};

