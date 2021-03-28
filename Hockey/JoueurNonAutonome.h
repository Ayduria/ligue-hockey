#pragma once
#include "Joueur.h"

class JoueurNonAutonome : public Joueur
{
	int anciennete;

public:
	JoueurNonAutonome() {}
	JoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville, Parcours parcours, int anciennete);

	bool transfert() { return false; }
};