#pragma once
#include "Club.h"
#include "Joueur.h"

class Equipe
{
	Club* clubEquipe;
	int nbJoueursTerrain;
	int nbGardiens;
	Joueur* capitaine;

public:
	Equipe() {}
	Equipe(Club* clubEquipe, int nbJoueursTerrain, int nbGardiens, Joueur* capitaine);

	Club* getClubEquipe() { return clubEquipe; }
	int getNbJoueursTerrain() { return nbJoueursTerrain; }
	int getNbGuardiens() { return nbGardiens; }
	Joueur* getCapitaine() { return capitaine; }
};