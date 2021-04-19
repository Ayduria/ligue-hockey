#pragma once
#include "Negociateur.h"

class NegoAcheteur : public Negociateur
{
	float montantMaximal;

public:
	NegoAcheteur(float montantDesire, float montantMaximal, Club* representantClub);

	float getMontantMaximal() { return montantMaximal; }

	bool verifierOffre(float montantOffre);
	void calculerMontant(float tempsEcoule);
};