#include "Equipe.h"

Equipe::Equipe(Club* clubEquipe, int nbJoueursTerrain, int nbGardiens, Joueur* capitaine) {
	this->clubEquipe = clubEquipe;
	this->nbJoueursTerrain = nbJoueursTerrain;
	this->nbGardiens = nbGardiens;
	this->capitaine = capitaine;
}