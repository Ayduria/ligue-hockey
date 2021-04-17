#pragma once
#include "TitreGagne.h"
#include "Sportif.h"
#include "Staff.h"
#include <string>

using namespace std;

class Coach : public Sportif, public Staff
{
private:
	string lieuGraduation;
	vector<TitreGagne> titreGagnes;

public:
	Coach(string prenom, string nom, string lieuGraduation, string villeNaissance, int age);

	string getLieu() { return lieuGraduation; }

	vector<TitreGagne> getTitreGagne() { return titreGagnes; }

	void ajouterTitreGagne(string nom, string date, Club* club);
};