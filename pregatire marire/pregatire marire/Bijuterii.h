#pragma once
#include <string>
using namespace std;
class Bijuterii
{
private:
	int pret;
	int cod_bijuterie;
	int lungime;
	string material;
public:
	Bijuterii(int, int, int, string);

	virtual void afisare() ;

	string getMaterial();

	int getCod();

	int getPret();

	void setPret(int x);
};

