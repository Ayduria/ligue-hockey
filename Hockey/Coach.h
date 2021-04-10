#pragma once
#include "TitreGagne.h"
#include "Sportif.h"
#include <string>

using namespace std;

class Coach : public Sportif
{
private:
	string lieuGraduation;
	vector<TitreGagne> titreGagnes;

public:
	Coach(string prenom, string nom, string lieuGraduation);

	vector<TitreGagne> getTitreGagne() { return titreGagnes; }

	void ajouterTitreGagne(string nom, string date, Club* club);
};