#pragma once
#include "Sportif.h"

class Arbitre : public Sportif
{
	string lieuDiplome;
	int experienceArbitrage;

public:
	Arbitre() {}
	Arbitre(string prenom, string nom, string lieuDiplome, int experienceArbitrage);

	string getLieuDiplome() { return lieuDiplome; }
	int getExperienceArbitrage() { return experienceArbitrage; }
};