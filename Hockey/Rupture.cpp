#include "Rupture.h"

Rupture::Rupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, Club* ancienClub, float penalite) {
	this->joueur = joueur;
	this->raisonsDepart = raisonsDepart;
	this->nouveauClub = nouveauClub;
	this->ancienClub = ancienClub;
	this->penalite = penalite;
}