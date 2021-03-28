#pragma once
#include "TitreGagne.h"
#include "Sportif.h"
#include <string>

using namespace std;

class Coach : public Sportif
{
private:
	string lieuGraduation;
	vector<TitreGagne> titreGagne;

public:
	Coach(string prenom, string nom, string lieuGraduation, vector<TitreGagne> titreGagne);

	vector<TitreGagne> getTitreGagne() { return titreGagne; }
};