#pragma once
#include "Club.h"
#include "Message.h"

class Negociateur
{
	float montantDesire;
	Club* representantClub;
	
public:
	Negociateur(float montantDesire, Club* representantClub);

	float getMontantDesire() { return montantDesire; }
	void setMontantDesire(float montantDesire) { this->montantDesire = montantDesire; }
	Club* getRepresentant() { return representantClub; }

	virtual bool verifierOffre(float montant) = 0;
	virtual void calculerMontant(float tempsEcoule) = 0;
};