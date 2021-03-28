#include "Arbitre.h"

Arbitre::Arbitre(string prenom, string nom, string lieuDiplome, int experienceArbitrage) : Sportif(prenom, nom) {
	this->lieuDiplome = lieuDiplome;
	this->experienceArbitrage = experienceArbitrage;
}