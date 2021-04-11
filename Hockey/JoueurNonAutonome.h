#pragma once
#include "Joueur.h"

class JoueurNonAutonome : public Joueur
{
public:
	JoueurNonAutonome() {}
	JoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville);

	bool transfert() { return false; }
};