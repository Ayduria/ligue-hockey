#pragma once
#include "Club.h"
#include "Coach.h"
#include "Joueur.h"
#include "Calendrier.h"
#include "ContratEngagement.h"
#include "Rupture.h"
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
	Club* getClub(int i) { return &listeClubs[i]; }
	Calendrier* getCalendrier() { return &calendrierRencontres; }
	ContratEngagement* getContrat() { return &contrat; }

	void ajouterClub(string nom, string histoire, string couleur, string date, string ville, string adresse);
	void ajouterCoach(string nom, string prenom, string lieuGraduation, vector<TitreGagne> titreGagne);
	vector<TitreGagne> ajouterTitreGagne(string nom, string date, Club* club, vector<TitreGagne> titreGagnes);
	string chercherClubTitre();
	string chercherCoachTitre();
	Club* chercherClub(string nom);
	void retirerClub(int choixClub);

	ContratEngagement* creerContrat(Joueur* joueur, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);
	Rupture* creerRupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, float penalite);
};