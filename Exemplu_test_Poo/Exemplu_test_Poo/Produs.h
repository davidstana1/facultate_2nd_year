#pragma once
#include<iostream>
#include<string>
using namespace std;
class Produs
{
private:
	string nume;
protected:
	int pret;
public:
	Produs(string, int);

	virtual void afisare();

	virtual string GetTip() const;

	string GetNume() const;

	virtual int GetPret() const;
};

