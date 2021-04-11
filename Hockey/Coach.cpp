#include "Coach.h"

Coach::Coach(string prenom, string nom, string lieuGraduation, string villeNaissance, int age) : Sportif(prenom, nom, villeNaissance), Staff(prenom, nom, age, "Entraîneur"), Personne(prenom, nom) {
	this->lieuGraduation = lieuGraduation;
}

void Coach::ajouterTitreGagne(string nom, string date, Club* club) {
	Palmares palmares(nom, date);
	TitreGagne titreGagne(palmares, club);
	titreGagnes.push_back(titreGagne);
}