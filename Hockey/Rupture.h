#pragma once
#include "Joueur.h"
#include "Club.h"

class Rupture
{
	Joueur* joueur;
	string raisonsDepart;
	Club* nouveauClub;
	float penalite;

public:
	Rupture() {}
	Rupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, float penalite);

	Joueur* getJoueur() { return joueur; }
	string getRaisonsDepart() { return raisonsDepart; }
	Club* getNouveauClub() { return nouveauClub; }
	float getPenalite() { return penalite; }
};