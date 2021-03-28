#include "Coach.h"

Coach::Coach(string prenom, string nom, string lieuGraduation, vector<TitreGagne> titreGagne) : Sportif(prenom, nom) {
	this->lieuGraduation = lieuGraduation;
	this->titreGagne = titreGagne;
}