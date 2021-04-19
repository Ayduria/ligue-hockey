#pragma once
#include "Negociateur.h"

class NegoVendeur : public Negociateur
{
	float montantMinimal;
	
public:
	NegoVendeur(float montantDesire, float montantMinimal, Club* representantClub);

	float getMontantMinimal() { return montantMinimal; }

	bool verifierOffre(float montantOffre);
	void calculerMontant(float tempsEcoule);
};