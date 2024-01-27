#pragma once
#include "Utilizatori.h"
class Manager : public Utilizatori
{
private:
	string domeniu_actiune;
	int vechime;
public:
	Manager();

	Manager(string, string, string, string, string, int);

	void afisare();

	friend istream& operator>>(istream& input,Manager& manager);
	friend ostream& operator<<(ostream& os,const Manager& manager) ;
};

