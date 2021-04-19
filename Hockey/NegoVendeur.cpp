#include "NegoVendeur.h"

NegoVendeur::NegoVendeur(float montantDesire, float montantMinimal, Club* representantClub) : Negociateur(montantDesire, representantClub) {
	this->montantMinimal = montantMinimal;
}

bool NegoVendeur::verifierOffre(float montantOffre) {
	if (montantOffre < montantMinimal)
		return false;
	else
		return true;
}

void NegoVendeur::calculerMontant(float tempsEcoule)
{
	if (getMontantDesire() - tempsEcoule < montantMinimal)
		setMontantDesire(montantMinimal);
	else
		setMontantDesire(getMontantDesire() - tempsEcoule);
}