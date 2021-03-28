#pragma once
#include "Club.h"
#include "Joueur.h"
#include "Date.h"
#include "Reglement.h"

class ContratEngagement
{
	Joueur* joueurContractant;
	Club* clubContractant;
	Club* clubLibere;
	int dureeContrat;
	Date dateEntree;
	Reglement reglement;
	Date dateContrat;

public:
	ContratEngagement() {}
	ContratEngagement(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat);

	Joueur* getJoueurContractant() { return joueurContractant; }
	Club* getClubContractant() { return clubContractant; }
	Club* getClubLibere() { return clubLibere; }
	int getDureeContrat() { return dureeContrat; }
	Date getDateEntree() { return dateEntree; }
	Reglement getReglement() { return reglement; }
	Date getDateContrat() { return dateContrat; }

	Reglement creerReglement(float seuil, string descriptionDroits, float montantTransfert, float montantAncienClub);
};