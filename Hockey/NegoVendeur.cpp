#include "NegoVendeur.h"

NegoVendeur::NegoVendeur(float montantDesire, float montantMinimal, int dureeNegociation, Club* representantClub) : Negociateur(montantDesire, dureeNegociation, representantClub) {
	this->montantMinimal = montantMinimal;
}