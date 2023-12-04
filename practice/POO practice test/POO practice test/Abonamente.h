#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Abonamente
{
private:
	string data_creare;
	string nume;
	int CNP;
protected:
	int pret;
public:
	Abonamente(string, string, int, int);

	virtual void afisare();

	virtual string GetTipAbonament() const;

	virtual string GetNume() const;
};

