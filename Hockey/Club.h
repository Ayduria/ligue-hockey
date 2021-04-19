#pragma once
#include "Joueur.h"
#include "JoueurAutonome.h"
#include "JoueurNonAutonome.h"
#include "Palmares.h"
#include "Staff.h"
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
	vector<Staff> staffTechnique;
	vector<ContratEngagement*> listeContrats;
	vector<Rupture*> listeRuptures;

public:
	Club() {}
	Club(string nom, string histoire, string couleur, string date, string ville, string adresse);

	string getNom() { return clubNom; }
	string getHistoire() { return clubHistoire; }
	string getCouleur() { return clubCouleur; }
	string getDate() { return dateOrigine; }
	string getVille() { return ville; }
	string getAdresse() { return adresse; }
	vector<Joueur*> getEffectif() { return effectif; }
	Joueur* getJoueur(int i) { 
		try {
			effectif.at(i);
			return effectif[i];
		}
		catch (const exception& e) {
			return nullptr;
		}
	}
	vector<Palmares> getPalmares() { return clubPalmares; }
	vector<Staff>* getStaff() { return &staffTechnique; }
	vector<ContratEngagement*> getListeContrats() { return listeContrats; }
	vector<Rupture*> getListeRuptures() { return listeRuptures; }

	void setStade(int capacite, string qualiteTerrain, string nom, string adresse);
	void ajouterPalmares(string nom, string date);
	void ajouterPersonne(string prenom, string nom, int age, string role);
	Joueur* chercherJoueur(string prenom, string nom);
	int getNbJoueurs() { return effectif.size(); }

	template<typename T>
	void ajouterJoueur(string prenom, string nom, float taille, float poids, string ville);
	void ajouterJoueurTransfert(Joueur* joueur);
	void retirerJoueur(int joueur);
	void ajouterContrat(ContratEngagement* contrat);
	void ajouterRupture(Rupture* rupture);
	int getNbContrats() { return listeContrats.size(); }
	ContratEngagement* getContrat(int i) { 
		try {
			listeContrats.at(i);
			return listeContrats[i];
		}
		catch (const exception& e) {
			return nullptr;
		}
	}
};

template<typename T>
void Club::ajouterJoueur(string prenom, string nom, float taille, float poids, string ville) {
	T* joueur = new T(prenom, nom, taille, poids, ville);
	effectif.push_back(joueur);
}