#pragma once
#include "Joueur.h"
#include "JoueurAutonome.h"
#include "JoueurNonAutonome.h"
#include "Palmares.h"
#include "Personne.h"
#include "Stade.h"
#include <Vector>
#include <string>

using namespace std;

class ContratEngagement;
class Rupture;

class Club
{
private:
	string clubNom;
	string clubHistoire;
	string clubCouleur;
	string dateOrigine;
	vector<Joueur*> effectif;
	vector<Palmares> clubPalmares;
	Stade stade;
	string ville;
	string adresse;
	vector<Personne> staffTechnique;
	vector<ContratEngagement*> listeContrats;
	vector<Rupture*> listeRuptures;

public:
	Club() {}
	Club(string nom, string histoire, string couleur, string date, string ville, string adresse);

	string getNom() { return clubNom; }
	vector<Joueur*> getEffectif() { return effectif; }
	Joueur* getJoueur(int i) { return effectif[i]; }
	vector<Palmares> getPalmares() { return clubPalmares; }
	vector<Personne>* getStaff() { return &staffTechnique; }
	vector<ContratEngagement*> getListeContrats() { return listeContrats; }
	vector<Rupture*> getListeRuptures() { return listeRuptures; }

	void setStade(int capacite, string qualiteTerrain, string nom, string adresse);
	void ajouterPalmares(string nom, string date);
	void ajouterPersonne(string nom, int age, string role);
	Joueur* chercherJoueur(string prenom, string nom);
	int getNbJoueurs() { return effectif.size(); }

	void ajouterJoueurAutonome(string prenom, string nom, float taille, float poids, string ville, Parcours parcours);
	void ajouterJoueurNonAutonome(string prenom, string nom, float taille, float poids, string ville, Parcours parcours, int anciennete);
	void ajouterContrat(ContratEngagement* contrat);
	void ajouterRupture(Rupture* rupture);
	int getNbContrats() { return listeContrats.size(); }
	ContratEngagement* getContrat(int i) { return listeContrats[i]; }

};