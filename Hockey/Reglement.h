#pragma once
#include <string>
using namespace std;

class Reglement
{
	float seuil;
	string descriptionDroits;
	float montantTransfert;
	float montantAncienClub;
	float montantRestant;

public:
	Reglement() {}
	Reglement(float seuil, string descriptionDroits, float montantTransfert, float montantAncienClub, float montantRestant);

	float getSueil() { return seuil; }
	string getDescriptionDroits() { return descriptionDroits; }
	float getMontantTransfert() { return montantTransfert; }
	float getMontantAncienClub() { return montantAncienClub; }
	float getMontantRestant() { return montantRestant; }
};

