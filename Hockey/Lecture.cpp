#include "Lecture.h"

void Lecture::lire() {
	lireClubs();
	lirePalmares();
	lireJoueurs();
	lireContrats();
	lireRuptures();
	lireEntraineur();
	lireTitres();
	lireRencontres();
	lireMatchs();
}
void Lecture::lireClubs() {
	string clubNom;
	string clubHistoire;
	string clubCouleur;
	string dateOrigine;
	string ville;
	string adresse;

	ifstream fichierClubs("../clubs.txt", ios::in);
	if (fichierClubs.is_open()){
		while (!fichierClubs.eof())
		{
			getline(fichierClubs, clubNom);
			getline(fichierClubs, clubHistoire);
			getline(fichierClubs, clubCouleur);
			getline(fichierClubs, dateOrigine);
			getline(fichierClubs, ville);
			getline(fichierClubs, adresse);

			if (fichierClubs.eof())
			{
				break;
			}

			pLigueHockey->ajouterClub(clubNom, clubHistoire, clubCouleur, dateOrigine, ville, adresse);
		}
		fichierClubs.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}
void Lecture::lirePalmares() {
	string clubNom;
	string titre;
	string date;

	ifstream fichierPalmares("../palmares.txt", ios::in);
	if (fichierPalmares.is_open()) {
		while (!fichierPalmares.eof())
		{
			getline(fichierPalmares, clubNom);
			getline(fichierPalmares, titre);
			getline(fichierPalmares, date);
			
			if (fichierPalmares.eof())
			{
				break;
			}

			pLigueHockey->chercherClub(clubNom)->ajouterPalmares(titre, date);
		}
		fichierPalmares.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}
void Lecture::lireJoueurs() {
	string clubNom;
	string prenom;
	string nom;
	string taille;
	string poids;
	string ville;
	string autonome;

	ifstream fichierJoueurs("../joueurs.txt", ios::in);
	if (fichierJoueurs.is_open()){
		while (!fichierJoueurs.eof())
		{
			getline(fichierJoueurs, clubNom);
			getline(fichierJoueurs, prenom);
			getline(fichierJoueurs, nom);
			getline(fichierJoueurs, taille);
			getline(fichierJoueurs, poids);
			getline(fichierJoueurs, ville);
			getline(fichierJoueurs, autonome);

			if (fichierJoueurs.eof())
			{
				break;
			}

			if (autonome == "yes")
			{
				pLigueHockey->chercherClub(clubNom)->ajouterJoueur<JoueurAutonome>(prenom, nom, stof(taille), stof(poids), ville);
			}
			else
			{
				pLigueHockey->chercherClub(clubNom)->ajouterJoueur<JoueurNonAutonome>(prenom, nom, stof(taille), stof(poids), ville);
			}
		}
		fichierJoueurs.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}

void Lecture::lireContrats() {
	ContratEngagement* contrat;
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

	ifstream fichierContrats("../contrats.txt", ios::in);
	if (fichierContrats.is_open()) {
		while (!fichierContrats.eof())
		{
			getline(fichierContrats, nomClubContractant);
			getline(fichierContrats, nomClubLibere);

			getline(fichierContrats, seuil);
			getline(fichierContrats, descriptionDroits);
			getline(fichierContrats, montantTransfert);
			getline(fichierContrats, montantAncienClub);

			getline(fichierContrats, jour1);
			getline(fichierContrats, mois1);
			getline(fichierContrats, annee1);
			getline(fichierContrats, jour2);
			getline(fichierContrats, mois2);
			getline(fichierContrats, annee2);

			getline(fichierContrats, prenomJoueur);
			getline(fichierContrats, nomJoueur);
			getline(fichierContrats, dureeContrat);

			if (fichierContrats.eof())
			{
				break;
			}

			reglement = pLigueHockey->getContrat()->creerReglement(stof(seuil), descriptionDroits, stof(montantTransfert), stof(montantAncienClub));
			date1 = pLigueHockey->getCalendrier()->creerDate(stoi(jour1), stoi(mois1), stoi(annee1));
			date2 = pLigueHockey->getCalendrier()->creerDate(stoi(jour2), stoi(mois2), stoi(annee2));
			contrat = pLigueHockey->creerContrat(pLigueHockey->chercherClub(nomClubContractant)->chercherJoueur(prenomJoueur, nomJoueur), pLigueHockey->chercherClub(nomClubContractant), pLigueHockey->chercherClub(nomClubLibere), stoi(dureeContrat), date1, reglement, date2);
			pLigueHockey->chercherClub(nomClubLibere)->ajouterContrat(contrat);
			pLigueHockey->chercherClub(nomClubContractant)->chercherJoueur(prenomJoueur, nomJoueur)->setContratActif(contrat);
		}
		fichierContrats.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}

void Lecture::lireRuptures() {
	string ancienClub;
	string nouveauClub;
	string prenomJoueur;
	string nomJoueur;
	string raison;
	string penalite;

	Rupture* rupture;

	ifstream fichierRuptures("../ruptures.txt", ios::in);
	if (fichierRuptures.is_open()) {
		while (!fichierRuptures.eof())
		{
			getline(fichierRuptures, ancienClub);
			getline(fichierRuptures, nouveauClub);
			getline(fichierRuptures, prenomJoueur);
			getline(fichierRuptures, nomJoueur);
			getline(fichierRuptures, raison);
			getline(fichierRuptures, penalite);

			if (fichierRuptures.eof())
			{
				break;
			}

			rupture = pLigueHockey->creerRupture(pLigueHockey->chercherClub(nouveauClub)->chercherJoueur(prenomJoueur, nomJoueur), raison, pLigueHockey->chercherClub(nouveauClub), pLigueHockey->chercherClub(ancienClub), stof(penalite));
			pLigueHockey->chercherClub(ancienClub)->ajouterRupture(rupture);
		}
		fichierRuptures.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}

void Lecture::lireEntraineur() {
	string prenom;
	string nom;
	string lieuGraduation;
	string ville;
	string age;

	ifstream fichierEntraineur("../entraineurs.txt", ios::in);
	if (fichierEntraineur.is_open()) {
		while (!fichierEntraineur.eof()) {
			getline(fichierEntraineur, prenom);
			getline(fichierEntraineur, nom);
			getline(fichierEntraineur, lieuGraduation);
			getline(fichierEntraineur, ville);
			getline(fichierEntraineur, age);

			if (fichierEntraineur.eof())
			{
				break;
			}

			pLigueHockey->ajouterCoach(prenom, nom, lieuGraduation, ville, stoi(age));
		}
		fichierEntraineur.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}
void Lecture::lireTitres() {
	string prenom;
	string nom;
	string description;
	string date;
	string club;

	ifstream fichierTitres("../titres.txt", ios::in);
	if (fichierTitres.is_open()) {
		while (!fichierTitres.eof()) {
			getline(fichierTitres, prenom);
			getline(fichierTitres, nom);
			getline(fichierTitres, description);
			getline(fichierTitres, date);
			getline(fichierTitres, club);

			if (fichierTitres.eof())
			{
				break;
			}

			pLigueHockey->getCoach(prenom, nom)->ajouterTitreGagne(description, date, pLigueHockey->chercherClub(club));
		}
		fichierTitres.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}

void Lecture::lireRencontres() {
	Date date;
	string jour;
	string mois;
	string annee;

	string clubLocal;
	string clubInvite;

	ifstream fichierRencontres("../rencontres.txt", ios::in);
	if (fichierRencontres.is_open()) {
		while (!fichierRencontres.eof()) {
			getline(fichierRencontres, jour);
			getline(fichierRencontres, mois);
			getline(fichierRencontres, annee);
			getline(fichierRencontres, clubLocal);
			getline(fichierRencontres, clubInvite);

			if (fichierRencontres.eof())
			{
				break;
			}

			date = pLigueHockey->getCalendrier()->creerDate(stoi(jour), stoi(mois), stoi(annee));
			pLigueHockey->getCalendrier()->AjouterRencontre(date, pLigueHockey->chercherClub(clubLocal), pLigueHockey->chercherClub(clubInvite));
		}
		fichierRencontres.close();
	}
	else { cout << "impossible d’ouvrir le fichier d'entrée" << endl; }
}

void Lecture::lireMatchs() {
	Rencontre* rencontre;
	string jour;
	string mois;
	string annee;

	Equipe equipe1;
	string clubLocal;
	Equipe equipe2;
	string clubInvite;
	
	string nbJoueurLocal;
	string nbGardienLocal;

	string nbJoueurInvite;
	string nbGardienInvite;

	string prenomCapLocal;
	string nomCapLocal;

	string prenomCapInvite;
	string nomCapInvite;

	string duree;
	string butLocal;
	string butInvite;

	string donePeriode;

	ifstream fichierMatchs("../matchs.txt", ios::in);
	if (fichierMatchs.is_open()) {
		while (!fichierMatchs.eof()) {
			getline(fichierMatchs, jour);
			getline(fichierMatchs, mois);
			getline(fichierMatchs, annee);

			getline(fichierMatchs, clubLocal);
			getline(fichierMatchs, clubInvite);

			getline(fichierMatchs, nbJoueurLocal);
			getline(fichierMatchs, nbGardienLocal);
			getline(fichierMatchs, nbJoueurInvite);
			getline(fichierMatchs, nbGardienInvite);

			getline(fichierMatchs, prenomCapLocal);
			getline(fichierMatchs, nomCapLocal);
			getline(fichierMatchs, prenomCapInvite);
			getline(fichierMatchs, nomCapInvite);

			if (fichierMatchs.eof())
			{
				break;
			}

			rencontre = pLigueHockey->getCalendrier()->getRencontreDate(stoi(jour), stoi(mois), stoi(annee));
			equipe1 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub(clubLocal), stoi(nbJoueurLocal), stoi(nbGardienLocal), pLigueHockey->chercherClub(clubLocal)->chercherJoueur(prenomCapLocal, nomCapLocal));
			equipe2 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub(clubInvite), stoi(nbJoueurInvite), stoi(nbGardienInvite), pLigueHockey->chercherClub(clubInvite)->chercherJoueur(prenomCapInvite, nomCapInvite));
			rencontre->setMatch(rencontre->creerMatch(equipe1, equipe2));

			getline(fichierMatchs, donePeriode);
			while (donePeriode != "%")
			{
				duree = donePeriode;
				getline(fichierMatchs, butLocal);
				getline(fichierMatchs, butInvite);
				getline(fichierMatchs, donePeriode);

				rencontre->getMatch()->ajouterPeriode(stoi(duree), stoi(butLocal), stoi(butInvite));
			}
			rencontre->getMatch()->setResultatFinal(rencontre->getMatch()->calculerResultat());
		}
	}
}