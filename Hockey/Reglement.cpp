#include "Reglement.h"

Reglement::Reglement(float seuil, string descriptionDroits, float montantTransfert, float montantAncienClub, float montantRestant) {
	this->seuil = seuil;
	this->descriptionDroits = descriptionDroits;
	this->montantTransfert = montantTransfert;
	this->montantAncienClub = montantAncienClub;
	this->montantRestant = montantRestant;
}