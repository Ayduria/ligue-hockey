#pragma once
#include "Rencontre.h"
#include <vector>
using namespace std;

class Calendrier
{
	vector<Rencontre> listeRencontres;

public:
	Calendrier();
	
	vector<Rencontre>* getListeRencontres() { return &listeRencontres; }
	int getNbRencontres(void) { return listeRencontres.size(); }
	Rencontre* getRencontre(int i) {  
		try {
			listeRencontres.at(i);
			return &listeRencontres[i];
		}
		catch (const std::exception& e) {
			return nullptr;
		}
	}
	Rencontre* getRencontreDate(int jour, int mois, int annee);

	Date creerDate(int jour, int mois, int annee);
	void AjouterRencontre(Date dateRencontre, Club* clubLocal, Club* clubInvite);
	vector<Rencontre> TrouverRencontresClub(Club* club);
};