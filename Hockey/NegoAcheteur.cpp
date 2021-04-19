#include "NegoAcheteur.h"

NegoAcheteur::NegoAcheteur(float montantDesire, float montantMaximal, Club* representantClub) : Negociateur(montantDesire, representantClub) {
	this->montantMaximal = montantMaximal;
}

bool NegoAcheteur::verifierOffre(float montantOffre) {
	if (montantOffre > montantMaximal)
		return false;
	else
		return true;
}

void NegoAcheteur::calculerMontant(float tempsEcoule)
{
	if (getMontantDesire() + tempsEcoule > montantMaximal)
		setMontantDesire(montantMaximal);
	else
		setMontantDesire(getMontantDesire() + tempsEcoule);
}