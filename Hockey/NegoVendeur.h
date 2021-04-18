#pragma once
#include "Negociateur.h"

class NegoVendeur : public Negociateur
{
	float montantMinimal;
	
public:
	NegoVendeur(float montantDesire, float montantMinimal, int dureeNegociation, Club* representantClub);

	float getMontantMinimal() { return montantMinimal; }
};