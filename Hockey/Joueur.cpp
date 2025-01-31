#include "Joueur.h"

Joueur::Joueur(string prenom, string nom, float taille, float poids, string ville) : Sportif(prenom, nom, ville), Personne(prenom, nom) {
	this->taille = taille;
	this->poids = poids;
	this->contratActif = nullptr;
	this->ville = ville;
}

void Joueur::ajouterParcours(string club, string date) {
	Parcours parcours(club, date);
	listeParcours.push_back(parcours);
}