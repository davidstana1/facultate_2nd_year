#pragma once
#include<iostream>
using namespace std;
class Electrocasnice
{
private:
	string producator;
	int pret;

public:
	Electrocasnice(string, int);

	virtual void afisare();
	virtual string tip() const;
};

