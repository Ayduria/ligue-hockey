#pragma once
#include "Negociateur.h"

class NegoAcheteur : public Negociateur
{
	float montantMaximal;

public:
	float getMontantMaximal() { return montantMaximal; }
};