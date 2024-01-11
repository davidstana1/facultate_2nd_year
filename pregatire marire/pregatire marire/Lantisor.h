#pragma once
#include "Bijuterii.h"
class Lantisor : public Bijuterii
{
private:
	string tip_piatra;
	static int perleVandute;
public:
	Lantisor(int, int, int, string, string);

	void afisare();

	static void incrementarePerle();

	static int getNumarPerleVandute();

	string getTipPiatra();
};

