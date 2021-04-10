#include "Joueur.h"

Joueur::Joueur(string prenom, string nom, float taille, float poids, string ville) : Sportif(prenom, nom) {
	this->taille = taille;
	this->poids = poids;
	this->villeNaissance = ville;
	this->contratActif = nullptr;
}

void Joueur::ajouterParcours(string club, string date) {
	Parcours parcours(club, date);
	listeParcours.push_back(parcours);
}