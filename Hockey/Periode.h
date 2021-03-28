#pragma once
class Periode
{
	int dureePeriode;
	int nbButsLocale;
	int nbButsAdverse;

public:
	Periode() {}
	Periode(int dureePeriode, int nbButsLocale, int nbButsAdverse);

	int getDureePeriode() { return dureePeriode; }
	int getNbButsLocale() { return nbButsLocale; }
	int getNbButsAdverse() { return nbButsAdverse; }
};