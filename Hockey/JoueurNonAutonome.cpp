#include "JoueurNonAutonome.h"

JoueurNonAutonome::JoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville, Parcours parcours, int anciennete) : Joueur(prenom, nom, taille, poids, ville, parcours) {
	this->anciennete = anciennete;
}