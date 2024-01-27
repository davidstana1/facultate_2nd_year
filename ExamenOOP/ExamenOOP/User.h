#pragma once
#include "Utilizatori.h"
class User : public Utilizatori
{
private:
	int varsta;
	string adresa;
public:
	User();

	User(string, string, string, string, int, string);

	void afisare();

	friend istream& operator>>(istream& input,User& user);
	friend ostream& operator<<(ostream& os,const User& user);
};

