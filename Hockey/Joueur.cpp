#include "Joueur.h"

Joueur::Joueur(string prenom, string nom, float taille, float poids, string ville, Parcours parcours) : Sportif(prenom, nom) {
	this->taille = taille;
	this->poids = poids;
	this->villeNaissance = ville;
	this->parcours = parcours;
}