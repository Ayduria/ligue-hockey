#include "Ecran.h"
#include <iostream>
#include <vector>
#include <ctime>

void Ecran::Menu() {
		cout << "============== Bienvenue dans la ligue de hockey ! ==============" << endl;
		cout << endl;
		cout << "1) Ajouter un club" << endl;
		cout << "2) Ajouter des joueurs à un club" << endl;
		cout << "3) Afficher les joueurs d'un club" << endl;
		cout << "4) Supprimer un club" << endl;
		cout << "5) Ajouter un entraîneur" << endl;
		cout << "6) Palmarès" << endl;
		cout << endl;
		cout << "7) Ajouter une rencontre au calendrier" << endl;
		cout << "8) Afficher le calendrier des rencontres d'un club" << endl;
		cout << "9) Ajouter les résultats d'un match" << endl;
		cout << "10) Afficher les résultats d'un match" << endl;
		cout << "11) Ajouter une nouvelle transaction de transfert d'un joueur" << endl;
		cout << "12) Afficher les montants de transfert encaissés par un club à une date donnée" << endl;
		cout << endl << "13) Quitter" << endl;
		cout << endl;
		cout << endl << "Entrez le numéro de l'option désirée: ";
}

void Ecran::MenuPrincipal() {
	int choix;
	Menu();
	cin >> choix;
	cin.ignore();
	while (choix != 0)
	{
		switch (choix)
		{
		case 1:
			AjouterClub();
			break;
		case 2:
			AjouterJoueurClub();
			break;
		case 3:
			AfficherClub();
			break;
		case 4:
			SupprimerClub();
			break;
		case 5:
			AjouterEntraineur();
			break;
		case 6:
			AfficherPlusTitre();
			break;
		case 7:
			AjouterRencontre();
			break;
		case 8:
			AfficherCalendrierClub();
			break;
		case 9:
			AjouterMatch();
			break;
		case 10:
			AfficherResultatMatch();
			break;
		case 11:
			AjouterTransfertJoueur();
			break;
		case 12:
			AfficherMontantTransferts();
			break;
		case 13:
			exit(EXIT_SUCCESS);
			break;
		default:
			cout << endl << "Choix invalide." << endl;
			break;
		}
		Menu();
		cin >> choix;
		cin.ignore();
	}
}

void Ecran::AjouterClub() {
	string nom;
	string histoire;
	string couleur;
	string date;
	string ville;
	string adresse;
	string continuer = "o";

	system("cls");
	cout << "============== Ajout d'un club ==============" << endl;
	cout << endl << "Nom du club: ";
	getline(cin, nom);
	cout << "Histoire du club: ";
	getline(cin, histoire);
	cout << "Couleur du club: ";
	getline(cin, couleur);
	cout << "Date de création du club: ";
	getline(cin, date);
	cout << "Ville du club: ";
	getline(cin, ville);
	cout << "Adresse du club: ";
	getline(cin, adresse);

	pLigueHockey->ajouterClub(nom, histoire, couleur, date, ville, adresse);

	cout << endl << "---------- Ajout de joueurs ----------" << endl;
	cout << endl << "Voulez-vous ajouter un joueur ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterJoueur(nom);
		cout << endl << "Voulez-vous ajouter un autre joueur ? (o/n) ";
		getline(cin, continuer);
	}
	continuer = "o";

	cout << endl << "---------- Ajout de titres au palmarès ----------" << endl;
	cout << endl << "Voulez-vous ajouter un titre au palmarès ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterPalmares(nom);
		cout << endl << "Voulez vous ajouter un autre titre au Palmarès ? (o/n) ";
		getline(cin, continuer);
	}
	continuer = "o";

	cout << endl << "---------- Ajout du stade ----------" << endl;
	AjouterStade(nom);

	cout << endl << "---------- Ajout de staff ----------" << endl;
	cout << endl << "Voulez-vous ajouter un membre du staff ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterStaff(nom);
		cout << endl << "Voulez-vous ajouter un autre membre du staff ? (o/n) ";
		getline(cin, continuer);
	}
	continuer = "o";

	system("cls");
}

void Ecran::AjouterJoueurClub() {
	int choixClub;
	string continuer = "o";
	string nomClub;

	system("cls");
	ListeClubs();
	cout << endl << endl << "Entrez le numéro du club dans lequel vous désirez ajouter des joueurs: ";
	cin >> choixClub;
	choixClub--;
	cin.ignore();

	nomClub = pLigueHockey->getClub(choixClub)->getNom();

	cout << endl << "==================== Ajout de joueurs dans le club " + nomClub + " ====================" << endl;

	while (continuer == "o") {
		AjouterJoueur(nomClub);
		cout << endl << "Voulez-vous ajouter un autre joueur ? (o/n) ";
		getline(cin, continuer);
	}

	system("cls");
}

void Ecran::ListeClubs() {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixClub;

	cout << "---------- Liste des clubs ----------" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();
}

void Ecran::AjouterJoueur(string nomClub) {
	string prenom;
	string nom;
	float taille;
	float poids;
	string ville;
	string autonome;
	string ajouterParcours = "o";

	cout << endl << "Prénom du joueur: ";
	getline(cin, prenom);
	cout << "Nom du joueur: ";
	getline(cin, nom);
	cout << "Taille du joueur (float): ";
	cin >> taille;
	cout << "Poids du joueur (float): ";
	cin >> poids;
	cin.ignore();
	cout << "Ville de naissance du joueur: ";
	getline(cin, ville);
	cout << endl << "Le joueur est-il autonome (o/n) ? ";
	cin >> autonome;

	if(autonome == "n") {
		int anciennete;
		cout << endl << "Nombre d'années d'ancienneté du joueur: ";
		cin >> anciennete;
		pLigueHockey->chercherClub(nomClub)->ajouterJoueurNonAutonome(prenom, nom, taille, poids, ville, anciennete);
	} else
		pLigueHockey->chercherClub(nomClub)->ajouterJoueurAutonome(prenom, nom, taille, poids, ville);

	cout << endl << "----- Parcours du joueur -----" << endl;
	while (ajouterParcours == "o") {
		AjouterParcours(prenom, nom, nomClub);

		cout << endl << "Voulez-vous ajouter un autre titre au parcours ? (o/n) ? ";
		getline(cin, ajouterParcours);
	}
}

void Ecran::AjouterParcours(string prenom, string nom, string nomClub) {
	string club;
	string date;

	cout << endl << "Club auquel le joueur a participé: ";
	cin.ignore();
	getline(cin, club);
	cout << "Date de passage dans le club: ";
	getline(cin, date);

	pLigueHockey->chercherClub(nomClub)->chercherJoueur(prenom, nom)->ajouterParcours(club, date);
}

void Ecran::AjouterPalmares(string nomClub) {
	string nom;
	string date;

	cout << endl << "Nom du titre: ";
	getline(cin, nom);
	cout << "Date à laquelle le club a gagné le titre: ";
	getline(cin, date);

	pLigueHockey->chercherClub(nomClub)->ajouterPalmares(nom, date);
}

void Ecran::AjouterStade(string nomClub) {
	int capacite;
	string qualite;
	string nom;
	string adresse;
	Stade stade;

	cout << endl << "Nom du stade: ";
	getline(cin, nom);
	cout << "Capacité du stade: ";
	cin >> capacite;
	cin.ignore();
	cout << "Qualité du terrain (Gazon ou Tartan): ";
	getline(cin, qualite);
	cout << "Adresse du stade: ";
	getline(cin, adresse);

	pLigueHockey->chercherClub(nomClub)->setStade(capacite, qualite, nom, adresse);
}

void Ecran::AjouterStaff(string nomClub) {
	string prenom;
	string nom;
	int age;
	string role;

	cout << endl << "Prénom de l'employé: ";
	getline(cin, prenom);
	cout << endl << "Nom de l'employé: ";
	getline(cin, nom);
	cout << "Âge de l'employé: ";
	cin >> age;
	cin.ignore();
	cout << "Rôle de l'employé: ";
	getline(cin, role);

	pLigueHockey->chercherClub(nomClub)->ajouterPersonne(prenom, nom, age, role);
}

void Ecran::SupprimerClub() {
	string nomClub;
	bool trouver;
	int choixClub;

	system("cls");
	cout << "==================== Suppression de club ====================" << endl << endl;
	ListeClubs();
	cout << endl << endl << "Entrez le numéro du club que vous souhaitez supprimer: ";
	cin >> choixClub;
	choixClub--;

	nomClub = pLigueHockey->getClub(choixClub)->getNom();
	pLigueHockey->retirerClub(choixClub);

	cout << endl << "Le club " + nomClub + " a été supprimé.";

	cout << endl << endl;

	system("pause");
	system("cls");

}

void Ecran::AfficherClub() {
	string nom;
	int choixClub;

	system("cls");
	ListeClubs();
	cout << endl << endl << "Entrez le numéro du club dont vous souhaitez afficher les joueurs: ";
	cin >> choixClub;
	choixClub--;

	Club* club = pLigueHockey->getClub(choixClub);
	nom = pLigueHockey->getClub(choixClub)->getNom();

	cout << endl << "=================== Liste de joueurs du club " + nom + " ===================" << endl;

	vector<Joueur*> listeJoueur = club->getEffectif();

	if (listeJoueur.size() == 0)
		cout << endl << "Il n'y a pas de joueurs dans ce club.";
	else {
		for (size_t i = 0; i < listeJoueur.size(); i++) {
			cout << endl << listeJoueur.at(i)->getPrenom() + " " + listeJoueur.at(i)->getNom();
		}
	}

	cout << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::AjouterEntraineur() {
	string prenom;
	string nom;
	string villeNaissance;
	string grade;
	int age;
	string role;
	string continuer = "o";

	system("cls");
	cout << "=================== Ajout d'entraîneur ===================" << endl;
	cout << endl << "Prénom de l'entraîneur: ";
	getline(cin, prenom);
	cout << "Nom de l'entraîneur: ";
	getline(cin, nom);
	cout << "Lieu d'obtention de son grade: ";
	getline(cin, grade);
	cout << "Ville de naissance: ";
	getline(cin, villeNaissance);
	cout << "Âge: ";
	cin >> age;
	cin.ignore();

	pLigueHockey->ajouterCoach(prenom, nom, grade, villeNaissance, age);

	cout << endl << "---------- Titres gagnés ----------" << endl;
	cout << endl << "Voulez-vous ajouter un titre gagné ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterTitreGagne(prenom, nom);
		cout << endl << "Voulez vous ajouter un autre titre gagné (o/n) ";
		getline(cin, continuer);
	}
	continuer = "o";

	system("cls");
}

void Ecran::AjouterTitreGagne(string prenom, string nom) {
	string continuer = "o";
	string nomTitre;
	string date;
	string nomClub;
	Club* club;

	cout << endl << "Nom du titre: ";
	getline(cin, nomTitre);
	cout << "Date à laquelle le club de l'entraîneur a gagné ce titre: ";
	getline(cin, date);
	cout << "Nom du club avec lequel l'entraîneur a gagné ce titre: ";
	getline(cin, nomClub);

	club = pLigueHockey->chercherClub(nomClub);
	pLigueHockey->getCoach(prenom, nom)->ajouterTitreGagne(nomTitre, date, club);
}

void Ecran::AfficherPlusTitre() {
	string club;
	string coach;

	club = pLigueHockey->chercherClubTitre();
	coach = pLigueHockey->chercherCoachTitre();

	system("cls");
	cout << "==================== Palmarès ====================" << endl;
	cout << endl << "Club le plus titré: " << club;
	cout << endl << "Entraîneur le plus titré: Mr/Mrs. " + coach;
	cout << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::AjouterRencontre() {
	int jour;
	int mois;
	int annee;
	int clubLocal;
	int clubInvite;
	int nbClubs = pLigueHockey->getNbClubs();

	system("cls");
	cout << "==================== Ajout de rencontre au calendrier ====================" << endl;

	cout << endl << "Jour: ";
	cin >> jour;
	cout << "Mois: ";
	cin >> mois;
	cout << "Année: ";
	cin >> annee;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le numéro du club local: ";
	cin >> clubLocal;
	clubLocal--;
	cout << "Entrez le numéro du club invité: ";
	cin >> clubInvite;
	clubInvite--;

	Date date = pLigueHockey->getCalendrier()->creerDate(jour, mois, annee);

	pLigueHockey->getCalendrier()->AjouterRencontre(date, pLigueHockey->getClub(clubLocal), pLigueHockey->getClub(clubInvite));

	system("cls");
}

void Ecran::AfficherCalendrierClub() {
	Club* club;
	vector<Rencontre> listeRencontresClub;
	Club* clubLocal;
	Club* clubInvite;
	int nbClubs = pLigueHockey->getNbClubs();
	int choix;

	system("cls");

	cout << "----- Liste des clubs -----" << endl;
	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le numéro du club pour lequel vous désirez afficher les rencontres: ";
	cin >> choix;
	choix--;

	club = pLigueHockey->getClub(choix);

	if (club != NULL)
	{
		cout << endl << "=================== Liste de rencontres du club " + pLigueHockey->getClub(choix)->getNom() + " ===================" << endl;

		listeRencontresClub = pLigueHockey->getCalendrier()->TrouverRencontresClub(club);

		if (listeRencontresClub.size() == 0)
			cout << endl << "Il n'y a pas de rencontres au calendrier pour ce club." << endl;
		else {
			for (size_t i = 0; i < listeRencontresClub.size(); i++) {
				cout << endl << listeRencontresClub.at(i).getDate().getJour() << "/" << listeRencontresClub.at(i).getDate().getMois() << "/" << listeRencontresClub.at(i).getDate().getAnnee() << endl;
				cout << listeRencontresClub.at(i).getClubLocal()->getNom() << " (club local) VS " << listeRencontresClub.at(i).getClubInvite()->getNom() << " (club invité)" << endl;
				if (listeRencontresClub.at(i).getMatch() != nullptr) {
					Resultat resultatFinal = listeRencontresClub.at(i).getMatch()->getResultatFinal();
					cout << "Le match a eu lieu avec un résultat final de " << resultatFinal.getButsLocale() << " à " << resultatFinal.getButsAdverse() << ". " << endl;
				}
				else
					cout << "Le match n'a pas encore eu lieu." << endl;
			}
		}
	}
	else
		cout << endl << "Le club " + pLigueHockey->getClub(choix)->getNom() + " n'existe pas.";

	cout << endl;

	system("pause");
	system("cls");
}

void Ecran::AjouterMatch() {
	vector<Rencontre>* listeRencontres = pLigueHockey->getCalendrier()->getListeRencontres();
	int nbRencontres = pLigueHockey->getCalendrier()->getNbRencontres();
	int cpt = 0;

	system("cls");

	cout << "----- Rencontres n'ayant pas encore de résultats de match -----" << endl << endl;

	for (int i = 0; i < nbRencontres; i++)
	{
		if (listeRencontres->at(i).getMatch() == nullptr) {
			cout << i + 1 << ") " << listeRencontres->at(i).getDate().getJour() << "/" << listeRencontres->at(i).getDate().getMois() << "/" << listeRencontres->at(i).getDate().getAnnee();
			cout << " - " << listeRencontres->at(i).getClubLocal()->getNom() << " VS " << listeRencontres->at(i).getClubInvite()->getNom() << endl;
			cpt++;
		}
	}

	if (cpt > 0) {
		int choix;
		cout << endl << "Entrez le numéro de la rencontre pour laquelle vous souhaitez entrer le résultat : ";
		cin >> choix;
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);
		Club* clubLocal = listeRencontres->at(choix).getClubLocal();
		Club* clubInvite = listeRencontres->at(choix).getClubInvite();
		string continuer = "o";

		cout << endl << "==================== Ajout de résultats d'un match ====================" << endl;

		cout << endl << "------------- Équipe locale (Club " << clubLocal->getNom() << ") -------------" << endl << endl;

		Equipe equipeLocale = CreerEquipe(clubLocal, choix);

		cout << endl << "------------- Équipe invitée (Club " << clubInvite->getNom() << ") -------------" << endl << endl;

		Equipe equipeInvitee = CreerEquipe(clubInvite, choix);

		rencontre->setMatch(rencontre->creerMatch(equipeLocale, equipeInvitee));

		cout << endl << "--------- Ajout de périodes ---------" << endl << endl;
		AjouterPeriode(choix);
		cout << endl << "Voulez-vous ajouter une autre période ? (o/n) ";
		cin.ignore();
		getline(cin, continuer);

		while (continuer == "o") {
			AjouterPeriode(choix);
			cout << endl << "Voulez-vous ajouter une autre période ? (o/n) ";
			cin.ignore();
			getline(cin, continuer);
		}
		continuer = "o";

		rencontre->getMatch()->setResultatFinal(rencontre->getMatch()->calculerResultat());
	}
	else {
		cout << "Tous les match du calendrier ont déjà eu lieu." << endl << endl;
		system("pause");
	}
		
	system("cls");
}

Equipe Ecran::CreerEquipe(Club* club, int noRencontre) {
	int nbJoueursTerrain;
	int nbGardiens;
	string prenomCapitaine;
	string nomCapitaine;

	cout << "Nombre de joueurs pouvant être présents sur le terrain: ";
	cin >> nbJoueursTerrain;
	cout << "Nombre de gardiens: ";
	cin >> nbGardiens;
	cout << "Prénom du capitaine de l'équipe: ";
	cin >> prenomCapitaine;
	cout << "Nom du capitaine de l'équipe: ";
	cin >> nomCapitaine;

	Joueur* capitaine = pLigueHockey->chercherClub(club->getNom())->chercherJoueur(prenomCapitaine, nomCapitaine);
	Equipe equipe = pLigueHockey->getCalendrier()->getRencontre(noRencontre)->getMatch()->creerEquipe(club, nbJoueursTerrain, nbGardiens, capitaine);

	return equipe;
}

void Ecran::AjouterPeriode(int noRencontre) {
	int dureePeriode;
	int nbButsLocale;
	int nbButsAdverse;

	cout << "Durée de la période: ";
	cin >> dureePeriode;
	cout << "Nombre de buts marqués par l'équipe locale: ";
	cin >> nbButsLocale;
	cout << "Nombre de buts marqués par l'équipe adverse: ";
	cin >> nbButsAdverse;

	pLigueHockey->getCalendrier()->getRencontre(noRencontre)->getMatch()->ajouterPeriode(dureePeriode, nbButsLocale, nbButsAdverse);
}

void Ecran::AfficherResultatMatch() {
	vector<Rencontre>* listeRencontres = pLigueHockey->getCalendrier()->getListeRencontres();
	int nbRencontres = pLigueHockey->getCalendrier()->getNbRencontres();
	int choix;
	int cpt = 0;

	system("cls");

	cout << "----- Rencontres ayant leurs résultats de match -----" << endl << endl;

	for (int i = 0; i < nbRencontres; i++)
	{
		if (listeRencontres->at(i).getMatch() != nullptr) {
			cout << i + 1 << ") " << listeRencontres->at(i).getDate().getJour() << "/" << listeRencontres->at(i).getDate().getMois() << "/" << listeRencontres->at(i).getDate().getAnnee();
			cout << " - " << listeRencontres->at(i).getClubLocal()->getNom() << " VS " << listeRencontres->at(i).getClubInvite()->getNom() << endl;
			cpt++;
		}
	}

	if (cpt > 0) {
		cout << endl << "Entrez le numéro de la rencontre pour laquelle vous souhaitez afficher le résultat : ";
		cin >> choix;
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);

		cout << endl << "==================== Affichage de résultats d'un match ====================" << endl << endl;

		if (rencontre->getMatch() == nullptr)
			cout << "Cette rencontre n'a pas encore eu lieu." << endl;
		else {
			Resultat resultatFinal = rencontre->getMatch()->getResultatFinal();
			cout << "Le résultat final est de " << resultatFinal.getButsLocale() << " à " << resultatFinal.getButsAdverse() << ". ";
			if (resultatFinal.getButsLocale() > resultatFinal.getButsAdverse())
				cout << "L'équipe du club " << rencontre->getMatch()->getEquipeLocale().getClubEquipe()->getNom() << " a gagné.";
			else if (resultatFinal.getButsAdverse() > resultatFinal.getButsLocale())
				cout << "L'équipe du club " << rencontre->getMatch()->getEquipeInvitee().getClubEquipe()->getNom() << " a gagné.";
			else
				cout << "Les deux équipes sont à égalité.";
		}
	}
	else
		cout << "Aucun match du calendrier n'a encore eu lieu.";

	cout << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::AjouterTransfertJoueur() {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixAncienClub, choixNouveauClub, choixJoueur;
	int jourActuel, moisActuel, anneeActuelle;
	bool joueurAutonome;
	bool rupture = false;

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime,&now);

	system("cls");

	jourActuel = newtime.tm_mday;
	moisActuel = newtime.tm_mon + 1;
	anneeActuelle = newtime.tm_year + 1900;

	Date dateActuelle = pLigueHockey->getCalendrier()->creerDate(jourActuel, moisActuel, anneeActuelle);

	cout << "==================== Ajout de transaction de transfert de joueur ====================" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le numéro du club du joueur que vous désirez transférer: ";
	cin >> choixAncienClub;
	choixAncienClub--;

	Club* ancienClub = pLigueHockey->getClub(choixAncienClub);

	vector<Joueur*> listeJoueurs = ancienClub->getEffectif();
	int nbJoueurs = ancienClub->getNbJoueurs();

	for (int i = 0; i < nbJoueurs; i++)
		cout << endl << i + 1 << ") " << listeJoueurs.at(i)->getPrenom() << " " << listeJoueurs.at(i)->getNom();

	cout << endl << endl << "Entrez le numéro du joueur que vous désirez transférer: ";
	cin >> choixJoueur;
	choixJoueur--;

	Joueur* joueur = ancienClub->getJoueur(choixJoueur);
	ContratEngagement* contratActifJoueur = joueur->getContratActif();

	if (contratActifJoueur == nullptr)
		creerContrat(choixJoueur, joueur, ancienClub, dateActuelle, rupture);
	else {
		bool contratFini = true;
		joueurAutonome = joueur->transfert();
		int anneeEcheance = contratActifJoueur->getDateEntree().getAnnee() + contratActifJoueur->getDureeContrat();
		int moisEcheance = contratActifJoueur->getDateEntree().getMois();
		int jourEcheance = contratActifJoueur->getDateEntree().getJour();

		if ((anneeActuelle < anneeEcheance) || (anneeActuelle == anneeEcheance && moisActuel < moisEcheance) || (anneeActuelle == anneeEcheance && moisActuel == moisEcheance && jourActuel < jourEcheance))
			contratFini = false;

		if (contratFini)
			creerContrat(choixJoueur, joueur, ancienClub, dateActuelle, rupture);
		else {
			if (!joueurAutonome) {
				cout << endl << "Le joueur est non-autonome et n'a pas terminé son contrat actuel. Il ne peut pas être transféré." << endl << endl;
				system("pause");
			}
			else {
				rupture = true;
				creerContrat(choixJoueur, joueur, ancienClub, dateActuelle, rupture);
			}
		}
	}

	system("cls");
}

void Ecran::creerContrat(int noJoueur, Joueur* joueur, Club* ancienClub, Date date, bool ruptureContrat) {
	int nbClubs = pLigueHockey->getNbClubs();
	int dureeContrat;
	int choixNouveauClub;
	int jour, mois, annee;
	float seuil, montantTransfert, montantEncaisseClub;
	string descriptionDroits;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le numéro du nouveau club du joueur: ";
	cin >> choixNouveauClub;
	choixNouveauClub--;

	Club* nouveauClub = pLigueHockey->getClub(choixNouveauClub);

	ancienClub->retirerJoueur(noJoueur);
	nouveauClub->ajouterJoueurTransfert(joueur);

	if (ruptureContrat) {
		string raisonsDepart;
		float penalite;
		cout << endl << "==================== Rupture de contrat ====================" << endl << endl;
		cout << "Raisons du départ: ";
		cin.ignore();
		getline(cin, raisonsDepart);
		cout << "Pénalité: ";
		cin >> penalite;

		Rupture* rupture = pLigueHockey->creerRupture(joueur, raisonsDepart, nouveauClub, penalite);
		ancienClub->ajouterRupture(rupture);
	}

	cout << endl << "==================== Contrat d'engagement ====================" << endl << endl;

	cout << "Durée du contrat (nombre d'années): ";
	cin >> dureeContrat;

	cout << endl << "------------ Ajout du règlement ------------" << endl << endl;
	cout << "Seuil en vigueur: ";
	cin >> seuil;
	cout << "Description des droits du joueur: ";
	cin.ignore();
	getline(cin, descriptionDroits);
	cout << "Montant du transfert: ";
	cin >> montantTransfert;
	cout << "Montant encaissé par son ancien club: ";
	cin >> montantEncaisseClub;

	cout << endl << "------------ Date du contrat ------------" << endl << endl;
	cout << "Jour: "; cin >> jour;
	cout << "Mois: "; cin >> mois;
	cout << "Jour: "; cin >> annee;

	Date dateContrat = pLigueHockey->getCalendrier()->creerDate(jour, mois, annee);
	Reglement reglement = pLigueHockey->getContrat()->creerReglement(seuil, descriptionDroits, montantTransfert, montantEncaisseClub);
	ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, nouveauClub, ancienClub, dureeContrat, date, reglement, dateContrat);
	
	joueur->setContratActif(contrat);
	ancienClub->ajouterContrat(contrat);
	nouveauClub->ajouterContrat(contrat);
}

void Ecran::AfficherMontantTransferts() {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixClub;
	int choixDate;
	int cpt = 0;

	system("cls");

	cout << "==================== Montant de transfert ====================" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le numéro du club pour lequel vous désirer voir les dates de contrats: ";
	cin >> choixClub;
	choixClub--;

	Club* club = pLigueHockey->getClub(choixClub);

	int nbContrats = club->getNbContrats();

	for (int i = 0; i < nbContrats; i++)
		if (club->getNom() == club->getContrat(i)->getClubLibere()->getNom()) {
			cout << endl << i + 1 << ") " << club->getContrat(i)->getDateContrat().getJour() << "/" << club->getContrat(i)->getDateContrat().getMois() << "/" << club->getContrat(i)->getDateContrat().getAnnee();
			cpt++;
		}

	if (cpt > 0) {
		cout << endl << endl << "Entrez le numéro de la date pour laquelle vous souhaitez voir le montant de transfert encaissé par le club: ";
		cin >> choixDate;
		choixDate--;

		cout << endl << "Le montant de transfert encaissé par le club à cette date est de " << club->getContrat(choixDate)->getReglement().getMontantAncienClub() << "$." << endl << endl;
	}
	else
		cout << endl << "Ce club n'a aucun contrat dans lequel il a encaissé un montant à son actif." << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::initHardcode() {
	pLigueHockey->ajouterClub("Pingouins", "Histoire du club", "Blanc", "2000", "Saguenay", "UQAC");
	pLigueHockey->ajouterClub("Tigres", "Histoire du club", "Orange", "1999", "Montréal", "UQAM");
	pLigueHockey->ajouterClub("Requins", "Histoire du club", "Bleu", "2002", "Laval", "ULAVAL");

	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurAutonome("Jean", "Tremblay", 180, 200, "Saguenay");
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurAutonome("Simon", "Girard", 150, 180, "Alma");
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurNonAutonome("Jeanne", "Bédard", 160, 140, "Chicoutimi", 4);
	pLigueHockey->chercherClub("Tigres")->ajouterJoueurNonAutonome("Laurie", "Potvin", 150, 130, "Saguenay", 5);
	pLigueHockey->chercherClub("Tigres")->ajouterJoueurNonAutonome("Peter", "St-Gelais", 200, 210, "Montréal", 1);
	pLigueHockey->chercherClub("Requins")->ajouterJoueurAutonome("Robert", "Girard", 150, 175, "Alma");
	pLigueHockey->chercherClub("Requins")->ajouterJoueurAutonome("Julie", "Simard", 125, 150, "Chicoutimi");

	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Coupe junior", "2 juin 2002");
	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Championnat provincial", "5 septembre 2005");
	pLigueHockey->chercherClub("Pingouins")->ajouterPalmares("Championnat régional", "1er Mai 2000");

	pLigueHockey->ajouterCoach("Simon", "Kant", "École de la vie", "Saguenay", 25);
	pLigueHockey->ajouterCoach("Marc-Antoine", "Larouche", "Nicolet", "Montréal", 28);
	pLigueHockey->getCoach("Simon", "Kant")->ajouterTitreGagne("Meilleur coach", "2 janvier 2000", pLigueHockey->chercherClub("Pingouins"));
	pLigueHockey->getCoach("Marc-Antoine", "Larouche")->ajouterTitreGagne("Coach le plus efficace", "3 décembre 2005", pLigueHockey->chercherClub("Pingouins"));
	pLigueHockey->getCoach("Marc-Antoine", "Larouche")->ajouterTitreGagne("Coach le plus apprécié", "8 février 2008", pLigueHockey->chercherClub("Tigres"));

	Date date1 = pLigueHockey->getCalendrier()->creerDate(15, 2, 2021);
	Date date2 = pLigueHockey->getCalendrier()->creerDate(6, 4, 2021);
	Date date3 = pLigueHockey->getCalendrier()->creerDate(24, 24, 2021);
	Date date4 = pLigueHockey->getCalendrier()->creerDate(15, 5, 2021);
	pLigueHockey->getCalendrier()->AjouterRencontre(date1, pLigueHockey->chercherClub("Tigres"), pLigueHockey->chercherClub("Requins"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date2, pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Requins"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date3, pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Tigres"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date4, pLigueHockey->chercherClub("Requins"), pLigueHockey->chercherClub("Tigres"));

	Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(0);
	Joueur* joueur = pLigueHockey->chercherClub("Tigres")->chercherJoueur("Laurie", "Potvin");
	Equipe equipe1 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub("Tigres"), 12, 2, joueur);
	Equipe equipe2 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub("Requins"), 10, 3, joueur);
	rencontre->setMatch(rencontre->creerMatch(equipe1, equipe2));
	rencontre->getMatch()->ajouterPeriode(12, 2, 3);
	rencontre->getMatch()->ajouterPeriode(10, 5, 2);
	rencontre->getMatch()->setResultatFinal(rencontre->getMatch()->calculerResultat());

	Reglement reglement = pLigueHockey->getContrat()->creerReglement(2000, "Droits", 1500, 700);
	Date date5 = pLigueHockey->getCalendrier()->creerDate(4, 10, 2018);
	ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, pLigueHockey->chercherClub("Tigres"), pLigueHockey->chercherClub("Requins"), 2, date5, reglement, date2);
	pLigueHockey->chercherClub("Requins")->ajouterContrat(contrat);
	pLigueHockey->chercherClub("Tigres")->ajouterContrat(contrat);
	joueur->setContratActif(contrat);
}