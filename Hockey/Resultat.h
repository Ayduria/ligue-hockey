#pragma once
class Resultat
{
	int nbTotalButsLocale;
	int nbTotalButsAdverse;

public:
	Resultat() {}
	Resultat(int nbTotalButsLocale, int nbTotalButsAdverse);

	int getButsLocale() { return nbTotalButsLocale; }
	int getButsAdverse() { return nbTotalButsAdverse; }
};

