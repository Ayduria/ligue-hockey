#include "NegoAcheteur.h"

NegoAcheteur::NegoAcheteur(float montantDesire, float montantMaximal, int dureeNegociation, Club* representantClub) : Negociateur(montantDesire, dureeNegociation, representantClub) {
	this->montantMaximal = montantMaximal;
}