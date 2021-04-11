#include "Arbitre.h"

Arbitre::Arbitre(string prenom, string nom, string lieuDiplome, int experienceArbitrage, string villeNaissance, int age) : Sportif(prenom, nom, villeNaissance), Staff(prenom, nom, age, "Arbitre"), Personne(prenom, nom) {
	this->lieuDiplome = lieuDiplome;
	this->experienceArbitrage = experienceArbitrage;
}