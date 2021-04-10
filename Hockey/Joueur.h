#pragma once
#include "Parcours.h"
#include "Sportif.h"
#include<string>

using namespace std;

class ContratEngagement;

class Joueur : public Sportif
{
private:
	float taille;
	float poids;
	string villeNaissance;
	vector<Parcours> listeParcours;
	ContratEngagement* contratActif;

public:
	Joueur () {}
	Joueur(string prenom, string nom, float taille, float poids, string ville);

	ContratEngagement* getContratActif() { return contratActif; };
	void setContratActif(ContratEngagement* contrat) { this->contratActif = contrat; }

	void ajouterParcours(string club, string date);
	virtual bool transfert() { return true; }
};