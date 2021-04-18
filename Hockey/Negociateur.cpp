#include "Negociateur.h"

Negociateur::Negociateur(float montantDesire, int dureeNegociation, Club* representantClub) {
	this->montantDesire = montantDesire;
	this->dureeNegociation = dureeNegociation;
	this->representantClub = representantClub;
}