#pragma once

class Date
{
	int jour;
	int mois;
	int annee;

public:
	Date() {}
	Date(int jour, int mois, int annee);

	int getJour() { return jour; }
	int getMois() { return mois; }
	int getAnnee() { return annee; }
};