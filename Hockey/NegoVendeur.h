#pragma once
#include "Negociateur.h"

class NegoVendeur : public Negociateur
{
	float montantMinimal;
	
public:
	float getMontantMinimal() { return montantMinimal; }
};