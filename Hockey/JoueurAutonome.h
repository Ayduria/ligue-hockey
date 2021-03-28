#pragma once
#include "Joueur.h"

class JoueurAutonome : public Joueur
{
public:
	JoueurAutonome() {}
	JoueurAutonome(string prenom, string nom, float taille, float poids, string ville, Parcours parcours);

	bool transfert() { return true; }
};