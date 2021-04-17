#include "Écriture.h"

void Écriture::enregistrer() {
	saveClubs();
	savePalmares();
	saveJoueurs();
	saveContrats();
	saveRuptures();
	saveEntraineur();
	saveTitres();
	saveRencontres();
	saveMatchs();
}
void Écriture::saveClubs() {
	string clubNom;
	string clubHistoire;
	string clubCouleur;
	string dateOrigine;
	string ville;
	string adresse;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;

	ofstream fichierClubs("../clubs.txt", ios::out);
	if (fichierClubs.is_open()) {
		for (it = listeClub.begin(); it != listeClub.end(); it++) {
			clubNom = it->getNom();
			clubHistoire = it->getHistoire();
			clubCouleur = it->getCouleur();
			dateOrigine = it->getDate();
			ville = it->getVille();
			adresse = it->getAdresse();

			fichierClubs << clubNom  << "\n";
			fichierClubs << clubHistoire << "\n";
			fichierClubs << clubCouleur << "\n";
			fichierClubs << dateOrigine << "\n";
			fichierClubs << ville << "\n";
			fichierClubs << adresse << "\n";
		}
		fichierClubs.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::savePalmares() {
	string clubNom;
	string titre;
	string date;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;

	vector<Palmares> listePalmares;

	ofstream fichierPalmares("../palmares.txt", ios::out);

	if (fichierPalmares.is_open()) {
		for (it = listeClub.begin(); it != listeClub.end(); it++) {
			clubNom = it->getNom();
			listePalmares = it->getPalmares();
			for (int i = 0; i < listePalmares.size(); i++) {
				titre = listePalmares.at(i).getTitre();
				date = listePalmares.at(i).getDate();

				fichierPalmares << clubNom << "\n";
				fichierPalmares << titre << "\n";
				fichierPalmares << date << "\n";
			}
		}
		fichierPalmares.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveJoueurs() {
	string clubNom;
	string prenom;
	string nom;
	string taille;
	string poids;
	string ville;
	string autonome;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;

	vector<Joueur*> effectif;

	ofstream fichierJoueurs("../joueurs.txt", ios::out);

	if (fichierJoueurs.is_open()) {
		for (it = listeClub.begin(); it != listeClub.end(); it++) {
			clubNom = it->getNom();
			effectif = it->getEffectif();
			for (int i = 0; i < effectif.size(); i++) {
				prenom = effectif.at(i)->getPrenom();
				nom = effectif.at(i)->getNom();
				taille = to_string(effectif.at(i)->getTaille());
				poids = to_string(effectif.at(i)->getPoids());
				ville = effectif.at(i)->getVille();
				if (effectif.at(i)->transfert())
				{
					autonome = "yes";
				}
				else
				{
					autonome = "no";
				}

				fichierJoueurs << clubNom << "\n";
				fichierJoueurs << prenom << "\n";
				fichierJoueurs << nom << "\n";
				fichierJoueurs << taille << "\n";
				fichierJoueurs << poids << "\n";
				fichierJoueurs << ville << "\n";
				fichierJoueurs << autonome << "\n";
			}
		}
		fichierJoueurs.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveContrats() {	
	string nomClubContractant;
	string nomClubLibere;
	
	Reglement reglement;
	string seuil;
	string descriptionDroits;
	string montantTransfert;
	string montantAncienClub;

	Date date1;
	string jour1;
	string mois1;
	string annee1;
	Date date2;
	string jour2;
	string mois2;
	string annee2;

	string prenomJoueur;
	string nomJoueur;
	string dureeContrat;

	vector<ContratEngagement*> listeContrat;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;
	
	ofstream fichierContrats("../contrats.txt", ios::out);
	if (fichierContrats.is_open()) {
		for (it = listeClub.begin(); it != listeClub.end(); it++) {
			listeContrat = it->getListeContrats();
			nomClubLibere = it->getNom();
			for (int i = 0; i < listeContrat.size(); i++) {
				nomClubContractant = listeContrat.at(i)->getClubContractant()->getNom();
				
				reglement = listeContrat.at(i)->getReglement();
				seuil = to_string(reglement.getSueil());
				descriptionDroits = reglement.getDescriptionDroits();
				montantTransfert = to_string(reglement.getMontantTransfert());
				montantAncienClub = to_string(reglement.getMontantAncienClub());

				date1 = listeContrat.at(i)->getDateEntree();
				date2 = listeContrat.at(i)->getDateContrat();
				jour1 = to_string(date1.getJour());
				mois1 = to_string(date1.getMois());
				annee1 = to_string(date1.getAnnee());
				jour2 = to_string(date2.getJour());
				mois2 = to_string(date2.getMois());
				annee2 = to_string(date2.getAnnee());

				prenomJoueur = listeContrat.at(i)->getJoueurContractant()->getPrenom();
				nomJoueur = listeContrat.at(i)->getJoueurContractant()-> getNom();
				dureeContrat = to_string(listeContrat.at(i)->getDureeContrat());

				fichierContrats << nomClubContractant << "\n";
				fichierContrats << nomClubLibere << "\n";

				fichierContrats << seuil << "\n";
				fichierContrats << descriptionDroits << "\n";
				fichierContrats << montantTransfert << "\n";
				fichierContrats << montantAncienClub << "\n";

				fichierContrats << jour1 << "\n";
				fichierContrats << mois1 << "\n";
				fichierContrats << annee1 << "\n";
				fichierContrats << jour2 << "\n";
				fichierContrats << mois2 << "\n";
				fichierContrats << annee2 << "\n";

				fichierContrats << prenomJoueur << "\n";
				fichierContrats << nomJoueur << "\n";
				fichierContrats << dureeContrat << "\n";
			}
		}
		fichierContrats.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveRuptures() {
	string ancienClub;
	string nouveauClub;
	string prenomJoueur;
	string nomJoueur;
	string raison;
	string penalite;

	vector<Rupture*> listeRupture;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;

	ofstream fichierRupture("../ruptures.txt", ios::out);
	if (fichierRupture.is_open()) {
		for (it = listeClub.begin(); it != listeClub.end(); it++) {
			listeRupture = it->getListeRuptures();
			ancienClub = it->getNom();
			for (int i = 0; i < listeRupture.size(); i++) {
				nouveauClub = listeRupture.at(i)->getNouveauClub()->getNom();
				prenomJoueur = listeRupture.at(i)->getJoueur()->getPrenom();
				nomJoueur = listeRupture.at(i)->getJoueur()->getNom();
				raison = listeRupture.at(i)->getRaisonsDepart();
				penalite = to_string(listeRupture.at(i)->getPenalite());

				fichierRupture << ancienClub << "\n";
				fichierRupture << nouveauClub << "\n";
				fichierRupture << prenomJoueur << "\n";
				fichierRupture << nomJoueur << "\n";
				fichierRupture << raison << "\n";
				fichierRupture << penalite << "\n";
			}
		}
		fichierRupture.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveEntraineur() {
	string prenom;
	string nom;
	string lieuGraduation;
	string ville;
	string age;

	vector<Coach> listeCoach = *pLigueHockey->getListeCoach();
	vector<Coach>::iterator it;

	ofstream fichierCoach("../entraineurs.txt", ios::out);
	if (fichierCoach.is_open()) {
		for (it = listeCoach.begin(); it != listeCoach.end(); it++) {
			prenom = it->getPrenom();
			nom = it->getNom();
			lieuGraduation = it->getLieu();
			ville = it->getVilleNaissance();
			age = to_string(it->getAge());

			fichierCoach << prenom << "\n";
			fichierCoach << nom << "\n";
			fichierCoach << lieuGraduation << "\n";
			fichierCoach << ville << "\n";
			fichierCoach << age << "\n";
		}
		fichierCoach.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveTitres() {
	vector<TitreGagne> listeTitres;
	string prenom;
	string nom;
	string description;
	string date;
	string club;
	
	vector<Coach> listeCoach = *pLigueHockey->getListeCoach();
	vector<Coach>::iterator it;

	ofstream fichierTitres("../titres.txt", ios::out);
	if (fichierTitres.is_open()) {
		for (it = listeCoach.begin(); it != listeCoach.end(); it++) {
			listeTitres = it->getTitreGagne();
			prenom = it->getPrenom();
			nom = it->getNom();
			for (int i = 0; i < listeTitres.size(); i++) {
				description = listeTitres.at(i).getPalmaresTitre().getTitre();
				date = listeTitres.at(i).getPalmaresTitre().getDate();
				club = listeTitres.at(i).getClub()->getNom();

				fichierTitres << prenom << "\n";
				fichierTitres << nom << "\n";
				fichierTitres << description << "\n";
				fichierTitres << date << "\n";
				fichierTitres << club << "\n";
			}
		}
		fichierTitres.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveRencontres() {
	string jour;
	string mois;
	string annee;
	
	string clubLocal;
	string clubInvite;

	vector<Rencontre> listeRencontre = *pLigueHockey->getCalendrier()->getListeRencontres();
	vector<Rencontre>::iterator it;

	ofstream fichierRencontre("../rencontres.txt", ios::out);
	if (fichierRencontre.is_open()) {
		for (it = listeRencontre.begin(); it != listeRencontre.end(); it++) {
			jour = to_string(it->getDate().getJour());
			mois = to_string(it->getDate().getMois());
			annee = to_string(it->getDate().getAnnee());

			clubLocal = it->getClubLocal()->getNom();
			clubInvite = it->getClubInvite()->getNom();

			fichierRencontre << jour << "\n";
			fichierRencontre << mois << "\n";
			fichierRencontre << annee << "\n";
			fichierRencontre << clubLocal << "\n";
			fichierRencontre << clubInvite << "\n";
		}
		fichierRencontre.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
void Écriture::saveMatchs() {
	string jour;
	string mois;
	string annee;

	string clubLocal;
	string nbJoueurLocal;
	string nbGardienLocal;

	string clubInvite;
	string nbJoueurInvite;
	string nbGardienInvite;

	string prenomCapLocal;
	string nomCapLocal;

	string prenomCapInvite;
	string nomCapInvite;

	string duree;
	string butLocal;
	string butInvite;

	vector<Rencontre> listeRencontre = *pLigueHockey->getCalendrier()->getListeRencontres();
	vector<Rencontre>::iterator it;

	ofstream fichierMatchs("../matchs.txt", ios::out);
	if (fichierMatchs.is_open()) {
		for (it = listeRencontre.begin(); it != listeRencontre.end(); it++) {
			jour = to_string(it->getDate().getJour());
			mois = to_string(it->getDate().getMois());
			annee = to_string(it->getDate().getAnnee());

			clubLocal = it->getClubLocal()->getNom();
			clubInvite = it->getClubInvite()->getNom();

			if (it->getMatch() != nullptr){
				nbJoueurLocal = to_string(it->getMatch()->getEquipeLocale().getNbJoueursTerrain());
				nbGardienLocal = to_string(it->getMatch()->getEquipeLocale().getNbGuardiens());
				nbJoueurInvite = to_string(it->getMatch()->getEquipeInvitee().getNbJoueursTerrain());
				nbGardienInvite = to_string(it->getMatch()->getEquipeInvitee().getNbGuardiens());

				prenomCapLocal = it->getMatch()->getEquipeLocale().getCapitaine()->getPrenom();
				nomCapLocal = it->getMatch()->getEquipeLocale().getCapitaine()->getNom();

				prenomCapInvite = it->getMatch()->getEquipeInvitee().getCapitaine()->getPrenom();
				nomCapInvite = it->getMatch()->getEquipeInvitee().getCapitaine()->getNom();

				fichierMatchs << jour << "\n";
				fichierMatchs << mois << "\n";
				fichierMatchs << annee << "\n";
				fichierMatchs << clubLocal << "\n";
				fichierMatchs << clubInvite << "\n";
				fichierMatchs << nbJoueurLocal << "\n";
				fichierMatchs << nbGardienLocal << "\n";
				fichierMatchs << nbJoueurInvite << "\n";
				fichierMatchs << nbGardienInvite << "\n";
				fichierMatchs << prenomCapLocal << "\n";
				fichierMatchs << nomCapLocal << "\n";
				fichierMatchs << prenomCapInvite << "\n";
				fichierMatchs << nomCapInvite << "\n";

				for (int i = 0; i<it->getMatch()->getListePeriodes()->size();i++){
					duree = to_string(it->getMatch()->getListePeriodes()->at(i).getDureePeriode());
					butLocal = to_string(it->getMatch()->getListePeriodes()->at(i).getNbButsLocale());
					butInvite = to_string(it->getMatch()->getListePeriodes()->at(i).getNbButsAdverse());

					fichierMatchs << duree << "\n";
					fichierMatchs << butLocal << "\n";
					fichierMatchs << butInvite << "\n";
				}
				fichierMatchs << "%" << "\n";
			}
		}fichierMatchs.close();
	}
	else { cout << "impossible d’ouvrir le fichier de sortie" << endl; }
}
