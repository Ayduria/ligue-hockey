#include "JoueurNonAutonome.h"

JoueurNonAutonome::JoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville, int anciennete) : Joueur(prenom, nom, taille, poids, ville), Personne(prenom, nom) {
	this->anciennete = anciennete;
}