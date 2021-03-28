#include "Rupture.h"

Rupture::Rupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, float penalite) {
	this->joueur = joueur;
	this->raisonsDepart = raisonsDepart;
	this->nouveauClub = nouveauClub;
	this->penalite = penalite;
}