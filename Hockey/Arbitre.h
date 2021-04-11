#pragma once
#include "Sportif.h"
#include "Staff.h"

class Arbitre : public Sportif, public Staff
{
	string lieuDiplome;
	int experienceArbitrage;

public:
	Arbitre() {}
	Arbitre(string prenom, string nom, string lieuDiplome, int experienceArbitrage, string villeNaissance, int age);

	string getLieuDiplome() { return lieuDiplome; }
	int getExperienceArbitrage() { return experienceArbitrage; }
};