#pragma once
#include "Coach.h"
#include "Joueur.h"
#include "Calendrier.h"
#include "ContratEngagement.h"
#include "Rupture.h"
#include "Negociation.h"
#include <vector>

using namespace std;

class Club;

class LigueHockey
{
private:
	vector<Club> listeClubs;
	vector<Coach> listeCoach;
	Calendrier calendrierRencontres;
	ContratEngagement contrat;

public:
	LigueHockey();

	vector<Club>* getListeClubs() { return &listeClubs; }
	vector<Coach>* getListeCoach() { return &listeCoach; }
	int getNbClubs(void) { return listeClubs.size(); }
	Club* getClub(int i) { 
		try {
			listeClubs.at(i);
			return &listeClubs[i];
		}
		catch (const exception& e) {
			return nullptr;
		}
	}
	Calendrier* getCalendrier() { return &calendrierRencontres; }
	ContratEngagement* getContrat() { return &contrat; }

	void ajouterClub(string nom, string histoire, string couleur, string date, string ville, string adresse);
	void ajouterCoach(string prenom, string nom, string lieuGraduation, string villeNaissance, int age);
	Coach* getCoach(string prenom, string nom);
	string chercherClubTitre();
	string chercherCoachTitre();
	Club* chercherClub(string nom);
	void retirerClub(int choixClub);

	Negociation* creerNegociation(Club* clubAcheteur, Club* clubVendeur, float montantDesireVendeur, float montantDesireAcheteur, float montantMinimal, float montantMaximal, float dureeNegociation);

	ContratEngagement* creerContrat(Joueur* joueur, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);
	Rupture* creerRupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, Club* ancienClub, float penalite);
};