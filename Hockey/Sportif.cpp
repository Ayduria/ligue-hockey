#include "Sportif.h"

Sportif::Sportif(string prenom, string nom, string villeNaissance) : Personne(prenom, nom) {
	this->villeNaissance = villeNaissance;
}