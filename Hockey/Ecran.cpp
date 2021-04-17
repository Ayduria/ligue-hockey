#include "Ecran.h"
#include <iostream>
#include <vector>
#include <ctime>

void Ecran::Menu() {
		cout << "============== Bienvenue dans la ligue de hockey ! ==============" << endl;
		cout << endl;
		cout << "1) Ajouter un club" << endl;
		cout << "2) Ajouter des joueurs � un club" << endl;
		cout << "3) Afficher les joueurs d'un club" << endl;
		cout << "4) Supprimer un club" << endl;
		cout << "5) Ajouter un entra�neur" << endl;
		cout << "6) Palmar�s" << endl;
		cout << endl;
		cout << "7) Ajouter une rencontre au calendrier" << endl;
		cout << "8) Afficher le calendrier des rencontres d'un club" << endl;
		cout << "9) Ajouter les r�sultats d'un match" << endl;
		cout << "10) Afficher les r�sultats d'un match" << endl;
		cout << "11) Ajouter une nouvelle transaction de transfert d'un joueur" << endl;
		cout << "12) Afficher les montants de transfert encaiss�s par un club � une date donn�e" << endl;
		cout << endl << "13) Quitter" << endl;
		cout << endl;
		cout << endl << "Entrez le num�ro de l'option d�sir�e: ";
}

void Ecran::MenuPrincipal() {
	int choix;
	Menu();
	choix = EntrerInt();
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
			return;
			break;
		default:
			cout << endl << "Choix invalide." << endl;
			break;
		}
		Menu();
		choix = EntrerInt();
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
	cout << "Date de cr�ation du club: ";
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

	cout << endl << "---------- Ajout de titres au palmar�s ----------" << endl;
	cout << endl << "Voulez-vous ajouter un titre au palmar�s ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterPalmares(nom);
		cout << endl << "Voulez vous ajouter un autre titre au Palmar�s ? (o/n) ";
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
	cout << endl << endl << "Entrez le num�ro du club dans lequel vous d�sirez ajouter des joueurs: ";
	choixClub = EntrerInt();
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

	cout << endl << "Pr�nom du joueur: ";
	getline(cin, prenom);
	cout << "Nom du joueur: ";
	getline(cin, nom);
	cout << "Taille du joueur (float): ";
	taille = EntrerFloat();
	cout << "Poids du joueur (float): ";
	poids = EntrerFloat();
	cin.ignore();
	cout << "Ville de naissance du joueur: ";
	getline(cin, ville);
	cout << endl << "Le joueur est-il autonome (o/n) ? ";
	cin >> autonome;
	while (autonome != "n" && autonome != "o")
	{
		cout << endl << "Entr�e invalide: Veuillez entrer une option valide.";
		cout << endl << "Le joueur est-il autonome (o/n) ? ";
		cin >> autonome;
	}

	if(autonome == "n")
		pLigueHockey->chercherClub(nomClub)->ajouterJoueur<JoueurNonAutonome>(prenom, nom, taille, poids, ville);
	else
		pLigueHockey->chercherClub(nomClub)->ajouterJoueur<JoueurAutonome>(prenom, nom, taille, poids, ville);

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

	cout << endl << "Club auquel le joueur a particip�: ";
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
	cout << "Date � laquelle le club a gagn� le titre: ";
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
	cout << "Capacit� du stade: ";
	capacite = EntrerInt();
	cin.ignore();
	cout << "Qualit� du terrain (Gazon ou Tartan): ";
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

	cout << endl << "Pr�nom de l'employ�: ";
	getline(cin, prenom);
	cout << endl << "Nom de l'employ�: ";
	getline(cin, nom);
	cout << "�ge de l'employ�: ";
	age = EntrerInt();
	cin.ignore();
	cout << "R�le de l'employ�: ";
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
	cout << endl << endl << "Entrez le num�ro du club que vous souhaitez supprimer: ";
	choixClub = EntrerInt();
	choixClub--;

	nomClub = pLigueHockey->getClub(choixClub)->getNom();
	pLigueHockey->retirerClub(choixClub);

	cout << endl << "Le club " + nomClub + " a �t� supprim�.";

	cout << endl << endl;

	system("pause");
	system("cls");

}

void Ecran::AfficherClub() {
	string nom;
	int choixClub;

	system("cls");
	ListeClubs();
	cout << endl << endl << "Entrez le num�ro du club dont vous souhaitez afficher les joueurs: ";
	choixClub = EntrerInt();
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
	cout << "=================== Ajout d'entra�neur ===================" << endl;
	cout << endl << "Pr�nom de l'entra�neur: ";
	getline(cin, prenom);
	cout << "Nom de l'entra�neur: ";
	getline(cin, nom);
	cout << "Lieu d'obtention de son grade: ";
	getline(cin, grade);
	cout << "Ville de naissance: ";
	getline(cin, villeNaissance);
	cout << "�ge: ";
	age = EntrerInt();;
	cin.ignore();

	pLigueHockey->ajouterCoach(prenom, nom, grade, villeNaissance, age);

	cout << endl << "---------- Titres gagn�s ----------" << endl;
	cout << endl << "Voulez-vous ajouter un titre gagn� ? (o/n) ";
	getline(cin, continuer);

	while (continuer == "o") {
		AjouterTitreGagne(prenom, nom);
		cout << endl << "Voulez vous ajouter un autre titre gagn� (o/n) ";
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
	cout << "Date � laquelle le club de l'entra�neur a gagn� ce titre: ";
	getline(cin, date);
	cout << "Nom du club avec lequel l'entra�neur a gagn� ce titre: ";
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
	cout << "==================== Palmar�s ====================" << endl;
	cout << endl << "Club le plus titr�: " << club;
	cout << endl << "Entra�neur le plus titr�: Mr/Mrs. " + coach;
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
	jour = EntrerInt();
	cout << "Mois: ";
	mois = EntrerInt();
	cout << "Ann�e: ";
	annee = EntrerInt();

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le num�ro du club local: ";
	clubLocal = EntrerInt();;
	clubLocal--;
	cout << "Entrez le num�ro du club invit�: ";
	clubInvite = EntrerInt();;
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

	cout << endl << endl << "Entrez le num�ro du club pour lequel vous d�sirez afficher les rencontres: ";
	choix = EntrerInt();;
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
				cout << listeRencontresClub.at(i).getClubLocal()->getNom() << " (club local) VS " << listeRencontresClub.at(i).getClubInvite()->getNom() << " (club invit�)" << endl;
				if (listeRencontresClub.at(i).getMatch() != nullptr) {
					Resultat resultatFinal = listeRencontresClub.at(i).getMatch()->getResultatFinal();
					cout << "Le match a eu lieu avec un r�sultat final de " << resultatFinal.getButsLocale() << " � " << resultatFinal.getButsAdverse() << ". " << endl;
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

	cout << "----- Rencontres n'ayant pas encore de r�sultats de match -----" << endl << endl;

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
		cout << endl << "Entrez le num�ro de la rencontre pour laquelle vous souhaitez entrer le r�sultat : ";
		choix = EntrerInt();
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);
		Club* clubLocal = listeRencontres->at(choix).getClubLocal();
		Club* clubInvite = listeRencontres->at(choix).getClubInvite();
		string continuer = "o";

		cout << endl << "==================== Ajout de r�sultats d'un match ====================" << endl;

		cout << endl << "------------- �quipe locale (Club " << clubLocal->getNom() << ") -------------" << endl << endl;

		Equipe equipeLocale = CreerEquipe(clubLocal, choix);

		cout << endl << "------------- �quipe invit�e (Club " << clubInvite->getNom() << ") -------------" << endl << endl;

		Equipe equipeInvitee = CreerEquipe(clubInvite, choix);

		rencontre->setMatch(rencontre->creerMatch(equipeLocale, equipeInvitee));

		cout << endl << "--------- Ajout de p�riodes ---------" << endl << endl;
		AjouterPeriode(choix);
		cout << endl << "Voulez-vous ajouter une autre p�riode ? (o/n) ";
		cin.ignore();
		getline(cin, continuer);

		while (continuer == "o") {
			AjouterPeriode(choix);
			cout << endl << "Voulez-vous ajouter une autre p�riode ? (o/n) ";
			cin.ignore();
			getline(cin, continuer);
		}
		continuer = "o";

		rencontre->getMatch()->setResultatFinal(rencontre->getMatch()->calculerResultat());
	}
	else {
		cout << "Tous les match du calendrier ont d�j� eu lieu." << endl << endl;
		system("pause");
	}
		
	system("cls");
}

Equipe Ecran::CreerEquipe(Club* club, int noRencontre) {
	int nbJoueursTerrain;
	int nbGardiens;
	string prenomCapitaine;
	string nomCapitaine;

	cout << "Nombre de joueurs pouvant �tre pr�sents sur le terrain: ";
	nbJoueursTerrain = EntrerInt();
	cout << "Nombre de gardiens: ";
	nbGardiens = EntrerInt();
	cout << "Pr�nom du capitaine de l'�quipe: ";
	cin >> prenomCapitaine;
	cout << "Nom du capitaine de l'�quipe: ";
	cin >> nomCapitaine;

	Joueur* capitaine = pLigueHockey->chercherClub(club->getNom())->chercherJoueur(prenomCapitaine, nomCapitaine);
	Equipe equipe = pLigueHockey->getCalendrier()->getRencontre(noRencontre)->getMatch()->creerEquipe(club, nbJoueursTerrain, nbGardiens, capitaine);

	return equipe;
}

void Ecran::AjouterPeriode(int noRencontre) {
	int dureePeriode;
	int nbButsLocale;
	int nbButsAdverse;

	cout << "Dur�e de la p�riode: ";
	dureePeriode = EntrerInt();
	cout << "Nombre de buts marqu�s par l'�quipe locale: ";
	nbButsLocale = EntrerInt();
	cout << "Nombre de buts marqu�s par l'�quipe adverse: ";
	nbButsAdverse = EntrerInt();

	pLigueHockey->getCalendrier()->getRencontre(noRencontre)->getMatch()->ajouterPeriode(dureePeriode, nbButsLocale, nbButsAdverse);
}

void Ecran::AfficherResultatMatch() {
	vector<Rencontre>* listeRencontres = pLigueHockey->getCalendrier()->getListeRencontres();
	int nbRencontres = pLigueHockey->getCalendrier()->getNbRencontres();
	int choix;
	int cpt = 0;

	system("cls");

	cout << "----- Rencontres ayant leurs r�sultats de match -----" << endl << endl;

	for (int i = 0; i < nbRencontres; i++)
	{
		if (listeRencontres->at(i).getMatch() != nullptr) {
			cout << i + 1 << ") " << listeRencontres->at(i).getDate().getJour() << "/" << listeRencontres->at(i).getDate().getMois() << "/" << listeRencontres->at(i).getDate().getAnnee();
			cout << " - " << listeRencontres->at(i).getClubLocal()->getNom() << " VS " << listeRencontres->at(i).getClubInvite()->getNom() << endl;
			cpt++;
		}
	}

	if (cpt > 0) {
		cout << endl << "Entrez le num�ro de la rencontre pour laquelle vous souhaitez afficher le r�sultat : ";
		choix = EntrerInt();
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);

		cout << endl << "==================== Affichage de r�sultats d'un match ====================" << endl << endl;

		if (rencontre->getMatch() == nullptr)
			cout << "Cette rencontre n'a pas encore eu lieu." << endl;
		else {
			Resultat resultatFinal = rencontre->getMatch()->getResultatFinal();
			cout << "Le r�sultat final est de " << resultatFinal.getButsLocale() << " � " << resultatFinal.getButsAdverse() << ". ";
			if (resultatFinal.getButsLocale() > resultatFinal.getButsAdverse())
				cout << "L'�quipe du club " << rencontre->getMatch()->getEquipeLocale().getClubEquipe()->getNom() << " a gagn�.";
			else if (resultatFinal.getButsAdverse() > resultatFinal.getButsLocale())
				cout << "L'�quipe du club " << rencontre->getMatch()->getEquipeInvitee().getClubEquipe()->getNom() << " a gagn�.";
			else
				cout << "Les deux �quipes sont � �galit�.";
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

	cout << endl << endl << "Entrez le num�ro du club du joueur que vous d�sirez transf�rer: ";
	choixAncienClub = EntrerInt();
	choixAncienClub--;

	Club* ancienClub = pLigueHockey->getClub(choixAncienClub);

	vector<Joueur*> listeJoueurs = ancienClub->getEffectif();
	int nbJoueurs = ancienClub->getNbJoueurs();

	for (int i = 0; i < nbJoueurs; i++)
		cout << endl << i + 1 << ") " << listeJoueurs.at(i)->getPrenom() << " " << listeJoueurs.at(i)->getNom();

	cout << endl << endl << "Entrez le num�ro du joueur que vous d�sirez transf�rer: ";
	choixJoueur = EntrerInt();
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
				cout << endl << "Le joueur est non-autonome et n'a pas termin� son contrat actuel. Il ne peut pas �tre transf�r�." << endl << endl;
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

	cout << "Entrez le num�ro du nouveau club du joueur: ";
	choixNouveauClub = EntrerInt();
	choixNouveauClub--;

	Club* nouveauClub = pLigueHockey->getClub(choixNouveauClub);

	ancienClub->retirerJoueur(noJoueur);
	nouveauClub->ajouterJoueurTransfert(joueur);

	if (ruptureContrat) {
		string raisonsDepart;
		float penalite;
		cout << endl << "==================== Rupture de contrat ====================" << endl << endl;
		cout << "Raisons du d�part: ";
		cin.ignore();
		getline(cin, raisonsDepart);
		cout << "P�nalit�: ";
		penalite = EntrerInt();

		Rupture* rupture = pLigueHockey->creerRupture(joueur, raisonsDepart, nouveauClub, ancienClub, penalite);
		ancienClub->ajouterRupture(rupture);
	}

	cout << endl << "==================== Contrat d'engagement ====================" << endl << endl;

	cout << "Dur�e du contrat (nombre d'ann�es): ";
	dureeContrat = EntrerInt();

	cout << endl << "------------ Ajout du r�glement ------------" << endl << endl;
	cout << "Seuil en vigueur: ";
	seuil = EntrerFloat();
	cout << "Description des droits du joueur: ";
	cin.ignore();
	getline(cin, descriptionDroits);
	cout << "Montant du transfert: ";
	montantTransfert = EntrerFloat();
	cout << "Montant encaiss� par son ancien club: ";
	montantEncaisseClub = EntrerFloat();

	cout << endl << "------------ Date du contrat ------------" << endl << endl;
	cout << "Jour: "; jour = EntrerInt();
	cout << "Mois: "; mois = EntrerInt();
	cout << "Jour: "; annee = EntrerInt();

	Date dateContrat = pLigueHockey->getCalendrier()->creerDate(jour, mois, annee);
	Reglement reglement = pLigueHockey->getContrat()->creerReglement(seuil, descriptionDroits, montantTransfert, montantEncaisseClub);
	ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, nouveauClub, ancienClub, dureeContrat, date, reglement, dateContrat);
	
	joueur->setContratActif(contrat);
	ancienClub->ajouterContrat(contrat);
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

	cout << endl << endl << "Entrez le num�ro du club pour lequel vous d�sirer voir les contrats lui ayant rapport� de l'argent: ";
	choixClub = EntrerInt();
	choixClub--;

	Club* club = pLigueHockey->getClub(choixClub);

	int nbContrats = club->getNbContrats();

	for (int i = 0; i < nbContrats; i++)
		if (club->getNom() == club->getContrat(i)->getClubLibere()->getNom()) {
			cout << endl << i + 1 << ") " << club->getContrat(i)->getDateContrat().getJour() << "/" << club->getContrat(i)->getDateContrat().getMois() << "/" << club->getContrat(i)->getDateContrat().getAnnee();
			cpt++;
		}

	if (cpt > 0) {
		cout << endl << endl << "Entrez le num�ro de la date pour laquelle vous souhaitez voir le montant de transfert encaiss� par le club: ";
		choixDate = EntrerInt();
		choixDate--;

		cout << endl << "Le montant de transfert encaiss� par le club � cette date est de " << club->getContrat(choixDate)->getReglement().getMontantAncienClub() << "$." << endl << endl;
	}
	else
		cout << endl << "Ce club n'a aucun contrat dans lequel il a encaiss� un montant � son actif." << endl << endl;

	system("pause");
	system("cls");
}

float Ecran::EntrerFloat() {
	float num;
	while (!(cin >> num)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Entr�e invalide; Veuillez entrer un float: " ;
	}
	return num;
}

int Ecran::EntrerInt() {
	int num;
	while (!(cin >> num)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Entr�e invalide; Veuillez entrer un int: ";
	}
	return num;
}

void Ecran::initHardcode() {
	// Clubs
	pLigueHockey->ajouterClub("Pingouins", "Histoire du club", "Blanc", "2000", "Saguenay", "UQAC");
	pLigueHockey->ajouterClub("Tigres", "Histoire du club", "Orange", "1999", "Montr�al", "UQAM");
	pLigueHockey->ajouterClub("Requins", "Histoire du club", "Bleu", "2002", "Laval", "ULAVAL");

	// Palmares clubs
	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Coupe junior", "2 juin 2002");
	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Championnat provincial", "5 septembre 2005");
	pLigueHockey->chercherClub("Pingouins")->ajouterPalmares("Championnat r�gional", "1er Mai 2000");

	// Joueurs
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueur<JoueurAutonome>("Jean", "Tremblay", 180, 200, "Saguenay");
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueur<JoueurAutonome>("Simon", "Girard", 150, 180, "Alma");
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueur<JoueurNonAutonome>("Jeanne", "B�dard", 160, 140, "Chicoutimi");
	pLigueHockey->chercherClub("Tigres")->ajouterJoueur<JoueurNonAutonome>("Laurie", "Potvin", 150, 130, "Saguenay");
	pLigueHockey->chercherClub("Tigres")->ajouterJoueur<JoueurNonAutonome>("Peter", "St-Gelais", 200, 210, "Montr�al");
	pLigueHockey->chercherClub("Requins")->ajouterJoueur<JoueurAutonome>("Robert", "Girard", 150, 175, "Alma");
	pLigueHockey->chercherClub("Requins")->ajouterJoueur<JoueurAutonome>("Julie", "Simard", 125, 150, "Chicoutimi");

	// Contrats
	Reglement reglementC1 = pLigueHockey->getContrat()->creerReglement(3000, "Droits", 2000, 500);
	Date dateC1 = pLigueHockey->getCalendrier()->creerDate(5, 4, 2017);
	ContratEngagement* contratC1 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Jean", "Tremblay"), pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Requins"), 3, dateC1, reglementC1, dateC1);
	pLigueHockey->chercherClub("Requins")->ajouterContrat(contratC1);
	pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Jean", "Tremblay")->setContratActif(contratC1);

	Reglement reglementC2 = pLigueHockey->getContrat()->creerReglement(4000, "Droits", 2000, 1500);
	Date dateC2 = pLigueHockey->getCalendrier()->creerDate(10, 7, 2018);
	ContratEngagement* contratC2 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Simon", "Girard"), pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Tigres"), 5, dateC2, reglementC2, dateC2);
	pLigueHockey->chercherClub("Tigres")->ajouterContrat(contratC2);
	pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Simon", "Girard")->setContratActif(contratC2);

	Reglement reglementC3 = pLigueHockey->getContrat()->creerReglement(2500, "Droits", 1900, 600);
	Date dateC3 = pLigueHockey->getCalendrier()->creerDate(2, 4, 2020);
	ContratEngagement* contratC3 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Jeanne", "B�dard"), pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Tigres"), 4, dateC3, reglementC3, dateC3);
	pLigueHockey->chercherClub("Tigres")->ajouterContrat(contratC3);
	pLigueHockey->chercherClub("Pingouins")->chercherJoueur("Jeanne", "B�dard")->setContratActif(contratC3);

	Reglement reglementC4 = pLigueHockey->getContrat()->creerReglement(2000, "Droits", 1500, 700);
	Date dateC4 = pLigueHockey->getCalendrier()->creerDate(4, 10, 2018);
	ContratEngagement* contratC4 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Tigres")->chercherJoueur("Laurie", "Potvin"), pLigueHockey->chercherClub("Tigres"), pLigueHockey->chercherClub("Requins"), 2, dateC4, reglementC4, dateC4);
	pLigueHockey->chercherClub("Requins")->ajouterContrat(contratC4);
	pLigueHockey->chercherClub("Tigres")->chercherJoueur("Laurie", "Potvin")->setContratActif(contratC4);

	Reglement reglementC5 = pLigueHockey->getContrat()->creerReglement(5000, "Droits", 3000, 1800);
	Date dateC5 = pLigueHockey->getCalendrier()->creerDate(26, 11, 2015);
	ContratEngagement* contratC5 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Tigres")->chercherJoueur("Peter", "St-Gelais"), pLigueHockey->chercherClub("Tigres"), pLigueHockey->chercherClub("Pingouins"), 10, dateC5, reglementC5, dateC5);
	pLigueHockey->chercherClub("Pingouins")->ajouterContrat(contratC5);
	pLigueHockey->chercherClub("Tigres")->chercherJoueur("Peter", "St-Gelais")->setContratActif(contratC5);

	Reglement reglementC6 = pLigueHockey->getContrat()->creerReglement(4500, "Droits", 3000, 1500);
	Date dateC6 = pLigueHockey->getCalendrier()->creerDate(15, 6, 2021);
	ContratEngagement* contratC6 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Requins")->chercherJoueur("Robert", "Girard"), pLigueHockey->chercherClub("Requins"), pLigueHockey->chercherClub("Pingouins"), 2, dateC6, reglementC6, dateC6);
	pLigueHockey->chercherClub("Pingouins")->ajouterContrat(contratC6);
	pLigueHockey->chercherClub("Requins")->chercherJoueur("Robert", "Girard")->setContratActif(contratC6);

	Reglement reglementC7 = pLigueHockey->getContrat()->creerReglement(2000, "Droits", 1000, 1000);
	Date dateC7 = pLigueHockey->getCalendrier()->creerDate(18, 9, 2014);
	ContratEngagement* contratC7 = pLigueHockey->creerContrat(pLigueHockey->chercherClub("Requins")->chercherJoueur("Julie", "Simard"), pLigueHockey->chercherClub("Requins"), pLigueHockey->chercherClub("Pingouins"), 6, dateC7, reglementC7, dateC7);
	pLigueHockey->chercherClub("Pingouins")->ajouterContrat(contratC7);
	pLigueHockey->chercherClub("Requins")->chercherJoueur("Julie", "Simard")->setContratActif(contratC7);

	// Rupture
	Rupture* rupture = pLigueHockey->creerRupture(pLigueHockey->chercherClub("Requins")->chercherJoueur("Julie", "Simard"), "J'tai tann�", pLigueHockey->chercherClub("Requins"),pLigueHockey->chercherClub("Tigres"), 10);
	pLigueHockey->chercherClub("Tigres")->ajouterRupture(rupture);

	// Entra�neurs
	pLigueHockey->ajouterCoach("Simon", "Kant", "�cole de la vie", "Saguenay", 25);
	pLigueHockey->ajouterCoach("Marc-Antoine", "Larouche", "Nicolet", "Montr�al", 28);

	// Titres gagn�s entra�neurs
	pLigueHockey->getCoach("Simon", "Kant")->ajouterTitreGagne("Meilleur coach", "2 janvier 2000", pLigueHockey->chercherClub("Pingouins"));
	pLigueHockey->getCoach("Marc-Antoine", "Larouche")->ajouterTitreGagne("Coach le plus efficace", "3 d�cembre 2005", pLigueHockey->chercherClub("Pingouins"));
	pLigueHockey->getCoach("Marc-Antoine", "Larouche")->ajouterTitreGagne("Coach le plus appr�ci�", "8 f�vrier 2008", pLigueHockey->chercherClub("Tigres"));

	// Rencontres
	Date date1 = pLigueHockey->getCalendrier()->creerDate(15, 2, 2021);
	Date date2 = pLigueHockey->getCalendrier()->creerDate(6, 4, 2021);
	Date date3 = pLigueHockey->getCalendrier()->creerDate(24, 24, 2021);
	Date date4 = pLigueHockey->getCalendrier()->creerDate(15, 5, 2021);
	pLigueHockey->getCalendrier()->AjouterRencontre(date1, pLigueHockey->chercherClub("Tigres"), pLigueHockey->chercherClub("Requins"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date2, pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Requins"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date3, pLigueHockey->chercherClub("Pingouins"), pLigueHockey->chercherClub("Tigres"));
	pLigueHockey->getCalendrier()->AjouterRencontre(date4, pLigueHockey->chercherClub("Requins"), pLigueHockey->chercherClub("Tigres"));

	// Match
	Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(0);
	Equipe equipe1 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub("Tigres"), 12, 2, pLigueHockey->chercherClub("Tigres")->chercherJoueur("Laurie", "Potvin"));
	Equipe equipe2 = rencontre->getMatch()->creerEquipe(pLigueHockey->chercherClub("Requins"), 10, 3, pLigueHockey->chercherClub("Requins")->chercherJoueur("Robert", "Girard"));
	rencontre->setMatch(rencontre->creerMatch(equipe1, equipe2));
	rencontre->getMatch()->ajouterPeriode(12, 2, 3);
	rencontre->getMatch()->ajouterPeriode(10, 5, 2);
	rencontre->getMatch()->setResultatFinal(rencontre->getMatch()->calculerResultat());
}