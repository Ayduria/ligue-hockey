#pragma once
#include "Negociateur.h"

class NegoAcheteur : public Negociateur
{
	float montantMaximal;

public:
	NegoAcheteur(float montantDesire, float montantMaximal, int dureeNegociation, Club* representantClub);

	float getMontantMaximal() { return montantMaximal; }
};