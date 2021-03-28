#include "LigueHockey.h"

LigueHockey::LigueHockey(void) {}

void LigueHockey::ajouterClub(std::string nom, std::string histoire, std::string couleur, std::string date, std::string ville, std::string adresse) {
	Club club(nom, histoire, couleur, date, ville, adresse);
	listeClubs.insert(listeClubs.begin(), club);
}

void LigueHockey::ajouterCoach(string nom, string prenom, string lieuGraduation, vector<TitreGagne> titreGagne) {
	Coach coach(nom, prenom, lieuGraduation, titreGagne);
	listeCoach.insert(listeCoach.begin(), coach);
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

bool LigueHockey::retirerClub(string nomClub) {
	bool trouver = false;
	for (size_t i = 0; i < listeClubs.size(); i++)
	{
		if (listeClubs.at(i).getNom() == nomClub)
		{
			listeClubs.erase(listeClubs.begin()+i);
			trouver = true;
		}
	}
	return trouver;
}

vector<TitreGagne> LigueHockey::ajouterTitreGagne(string nom, string date, Club* club, vector<TitreGagne> titreGagnes) {

	Palmares palmares(nom, date);
	TitreGagne titreGagne(palmares, club);
	titreGagnes.insert(titreGagnes.begin(), titreGagne);

	return titreGagnes;
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

Rupture* LigueHockey::creerRupture(Joueur* joueur, string raisonsDepart, Club* nouveauClub, float penalite) {
	Rupture* rupture = new Rupture(joueur, raisonsDepart, nouveauClub, penalite);
	return rupture;
}