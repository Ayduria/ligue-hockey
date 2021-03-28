#include "ContratEngagement.h"

ContratEngagement::ContratEngagement(Joueur* joueurContractant, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat) {
	this->joueurContractant = joueurContractant;
	this->clubContractant = clubContractant;
	this->clubLibere = clubLibere;
	this->dureeContrat = dureeContrat;
	this->dateEntree = dateEntree;
	this->reglement = reglement;
	this->dateContrat = dateContrat;
}

Reglement ContratEngagement::creerReglement(float seuil, string descriptionDroits, float montantTransfert, float montantAncienClub) {
	int montantRestant = montantTransfert - montantAncienClub;
	Reglement reglement(seuil, descriptionDroits, montantTransfert, montantAncienClub, montantRestant);
	return reglement;
}