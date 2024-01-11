#pragma once
#include "Bijuterii.h"
class Cercei : public Bijuterii
{
private:
	string tip_inchizatoare;
public:
	Cercei(int, int, int, string, string);

	void afisare() ;

	string getTipInchizatoare();
};

