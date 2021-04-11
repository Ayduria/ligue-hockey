#include "Club.h"
#include "ContratEngagement.h"
#include "Rupture.h"

Club::Club(string nom, string histoire, string couleur, string date, string ville, string adresse) {
	this->clubNom = nom;
	this->clubHistoire = histoire;
	this->clubCouleur = couleur;
	this->dateOrigine = date;
	this->ville = ville;
	this->adresse = adresse;
}

void Club::ajouterJoueurAutonome(string prenom, string nom, float taille, float poids, string ville) {
	JoueurAutonome* joueur = new JoueurAutonome(prenom, nom, taille, poids, ville);
	effectif.push_back(joueur);
}

void Club::ajouterJoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville, int anciennete) {
	JoueurNonAutonome* joueur = new JoueurNonAutonome(prenom, nom, taille, poids, ville, anciennete);
	effectif.push_back(joueur);
}

void Club::ajouterPalmares(string nom, string date) {
	Palmares palmares(nom, date);
	clubPalmares.insert(clubPalmares.begin(), palmares);
}

void Club::setStade(int capacite, string qualiteTerrain, string nom, string adresse) {
	Stade stade(capacite, qualiteTerrain, nom, adresse);
	this->stade = stade;
}

void Club::ajouterPersonne(string prenom, string nom, int age, string role) {
	Staff staff(prenom, nom, age, role);
	staffTechnique.insert(staffTechnique.begin(), staff);
}

Joueur* Club::chercherJoueur(string prenom, string nom) {
	Joueur* pJoueur = nullptr;
	for (size_t i = 0; i < effectif.size(); i++)
	{
		if ((effectif.at(i)->getPrenom() == prenom) && (effectif.at(i)->getNom() == nom))
			pJoueur = effectif.at(i);
	}

	return pJoueur;
}

void Club::ajouterContrat(ContratEngagement* contrat) {
	listeContrats.push_back(contrat);
}

void Club::ajouterRupture(Rupture* rupture) {
	listeRuptures.push_back(rupture);
}

void Club::ajouterJoueurTransfert(Joueur* joueur) {
	effectif.push_back(joueur);
}

void Club::retirerJoueur(int joueur) {
	effectif.erase(effectif.begin() + joueur);
}