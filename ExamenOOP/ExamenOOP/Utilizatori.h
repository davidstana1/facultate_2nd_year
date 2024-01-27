#pragma once
#include <string>
using namespace std;
class Utilizatori
{
protected:
	string email;
	string parola;
	string nume;
	string prenume;
public:
	Utilizatori(string, string,string,string);

	virtual void afisare();

	string getNume();

	void setParola(string parola_modificata);

	string getEmail();

	bool operator==(const Utilizatori& other) const;

	virtual istream& citire(istream&) ;
	virtual ostream& afisare(ostream&) const ;

	friend istream& operator>>(istream& is, Utilizatori& utilizator);
	friend ostream& operator<<(std::ostream& os, const Utilizatori& utilizator);
};

