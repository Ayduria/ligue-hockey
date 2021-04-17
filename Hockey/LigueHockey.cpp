#include "LigueHockey.h"

LigueHockey::LigueHockey(void) {}

void LigueHockey::ajouterClub(std::string nom, std::string histoire, std::string couleur, std::string date, std::string ville, std::string adresse) {
	Club club(nom, histoire, couleur, date, ville, adresse);
	listeClubs.insert(listeClubs.begin(), club);
}

void LigueHockey::ajouterCoach(string prenom, string nom, string lieuGraduation, string villeNaissance, int age) {
	Coach coach(prenom, nom, lieuGraduation, villeNaissance, age);
	listeCoach.insert(listeCoach.begin(), coach);
}

Coach* LigueHockey::getCoach(string prenom, string nom) {
	Coach* pCoach = nullptr;
	for (size_t i = 0; i < listeCoach.size(); i++)
	{
		if ((listeCoach.at(i).getPrenom() == prenom) && (listeCoach.at(i).getNom() == nom))
			pCoach = &listeCoach.at(i);
	}

	return pCoach;
}

Club* LigueHockey::chercherClub(string nom) {
	Club* pClub = nullptr;
	for (size_t i = 0; i < listeClubs.size(); i++)
	{
		if (listeClubs.at(i).getNom() == nom)
		{
			pClub = &listeClubs.at(i);
		}
	}
	if (pClub == nullptr) {
		pClub = 0;
	}

	return pClub;
}

void LigueHockey::retirerClub(int choixClub) {
	listeClubs.erase(listeClubs.begin()+choixClub);
}

string LigueHockey::chercherClubTitre() {
	int posTitre = 0;
	int plusTitre = 0;
	for (int i = 0; i < listeClubs.size(); i++) {
		if (listeClubs.at(i).getPalmares().size() > plusTitre) {
			plusTitre = listeClubs.at(i).getPalmares().size();
			posTitre = i;
		}
	}
	return listeClubs.at(posTitre).getNom();
}

string LigueHockey::chercherCoachTitre() {
	int posTitre = 0;
	int plusTitre = 0;
	for (int i = 0; i < listeCoach.size(); i++) {
		if (listeCoach.at(i).getTitreGagne().size() > plusTitre) {
			plusTitre = listeCoach.at(i).getTitreGagne().size();
			posTitre = i;
		}
	}
	return listeCoach.at(posTitre).getNom();
}

ContratEngagement* LigueHockey::creerContrat(Joueur* joueur, Club* clubContractant, Club* clubLibere, int dureeContrat, Date dateEntree, Reglement reglement, Date dateContrat) {
	ContratEngagement* contrat = new ContratEngagement(joueur, clubContractant, clubLibere, dureeContrat, dateEntree, reglement, dateContrat);
	return contrat;
}

Rupture* LigueHockey::creerRupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, Club* ancienClub, float penalite) {
	Rupture* rupture = new Rupture(joueur, raisonsDepart, nouveauClub, ancienClub, penalite);
	return rupture;
}