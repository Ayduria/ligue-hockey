#include "Ecran.h"
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
		cout << endl;
		cout << "11) Transférer un joueur" << endl;
		cout << "12) Afficher les montants de transfert encaissés par un club à une date donnée" << endl;
		cout << endl << "13) Enregistrer et quitter" << endl;
		cout << endl;
		cout << endl << "Entrez le numéro de l'option désirée: ";
}

void Ecran::MenuPrincipal() {
	int choix;
	Menu();
	choix = ValiderNombre<int>();
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
			cout << endl << "Choix invalide." << endl << endl;
			break;
		}
		Menu();
		choix = ValiderNombre<int>();
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
	choixClub = choixClubListe();
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

	cout << endl << "Prénom du joueur: ";
	getline(cin, prenom);
	cout << "Nom du joueur: ";
	getline(cin, nom);
	cout << "Taille du joueur (float): ";
	taille = ValiderNombre<float>();
	cout << "Poids du joueur (float): ";
	poids = ValiderNombre<float>();
	cin.ignore();
	cout << "Ville de naissance du joueur: ";
	getline(cin, ville);
	cout << endl << "Le joueur est-il autonome (o/n) ? ";
	cin >> autonome;
	while (autonome != "n" && autonome != "o")
	{
		cout << endl << "Entrée invalide: Veuillez entrer une option valide.";
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
	capacite = ValiderNombre<int>();
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
	age = ValiderNombre<int>();
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
	choixClub = choixClubListe();

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
	choixClub = choixClubListe();

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
	age = ValiderNombre<int>();;
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
	jour = ValiderNombre<int>();
	cout << "Mois: ";
	mois = ValiderNombre<int>();
	cout << "Année: ";
	annee = ValiderNombre<int>();

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le numéro du club local: ";
	clubLocal = ValiderNombre<int>();;
	clubLocal--;
	cout << "Entrez le numéro du club invité: ";
	clubInvite = ValiderNombre<int>();;
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
	choix = ValiderNombre<int>();;
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
		choix = ValiderNombre<int>();
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);

		while (rencontre == nullptr) {
			cout << "Aucune rencontre ne correspond à ce nombre, veuillez réessayer: ";
			choix = ValiderNombre<int>();
			choix--;
			rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);
		}

		if (rencontre->getMatch() == nullptr) {
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
			cout << endl << "Ce match a déjà eu lieu." << endl << endl;
			system("pause");
		}
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
	nbJoueursTerrain = ValiderNombre<int>();
	cout << "Nombre de gardiens: ";
	nbGardiens = ValiderNombre<int>();
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
	dureePeriode = ValiderNombre<int>();
	cout << "Nombre de buts marqués par l'équipe locale: ";
	nbButsLocale = ValiderNombre<int>();
	cout << "Nombre de buts marqués par l'équipe adverse: ";
	nbButsAdverse = ValiderNombre<int>();

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
		choix = ValiderNombre<int>();
		choix--;

		Rencontre* rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);

		while (rencontre == nullptr) {
			cout << "Aucune rencontre ne correspond à ce nombre, veuillez réessayer: ";
			choix = ValiderNombre<int>();
			choix--;
			rencontre = pLigueHockey->getCalendrier()->getRencontre(choix);
		}

		cout << endl << "==================== Affichage de résultats d'un match ====================" << endl << endl;

		if (rencontre->getMatch() == nullptr)
			cout << "Cette rencontre n'a pas encore eu lieu.";
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
	int choixAncienClub, choixJoueur;
	int jourActuel, moisActuel, anneeActuelle;
	bool joueurAutonome;
	bool rupture = false;
	bool conclusionNego = true;

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
	choixAncienClub = choixClubListe();

	Club* ancienClub = pLigueHockey->getClub(choixAncienClub);

	vector<Joueur*> listeJoueurs = ancienClub->getEffectif();
	int nbJoueurs = ancienClub->getNbJoueurs();

	for (int i = 0; i < nbJoueurs; i++)
		cout << endl << i + 1 << ") " << listeJoueurs.at(i)->getPrenom() << " " << listeJoueurs.at(i)->getNom();

	cout << endl << endl << "Entrez le numéro du joueur que vous désirez transférer: ";
	choixJoueur = ValiderNombre<int>();
	choixJoueur--;

	Joueur* joueur = ancienClub->getJoueur(choixJoueur);

	while (joueur == nullptr) {
		cout << "Aucun joueur ne correspond à ce nombre, veuillez réessayer: ";
		choixJoueur = ValiderNombre<int>();
		choixJoueur--;
		joueur = ancienClub->getJoueur(choixJoueur);
	}

	ContratEngagement* contratActifJoueur = joueur->getContratActif();

	if (contratActifJoueur == nullptr)
		NegoTransfert(ancienClub, choixJoueur, joueur, dateActuelle, rupture);
	else {
		bool contratFini = true;
		joueurAutonome = joueur->transfert();
		int anneeEcheance = contratActifJoueur->getDateEntree().getAnnee() + contratActifJoueur->getDureeContrat();
		int moisEcheance = contratActifJoueur->getDateEntree().getMois();
		int jourEcheance = contratActifJoueur->getDateEntree().getJour();

		if ((anneeActuelle < anneeEcheance) || (anneeActuelle == anneeEcheance && moisActuel < moisEcheance) || (anneeActuelle == anneeEcheance && moisActuel == moisEcheance && jourActuel < jourEcheance))
			contratFini = false;

		if (contratFini) {
			NegoTransfert(ancienClub, choixJoueur, joueur, dateActuelle, rupture);
		}
		else {
			if (!joueurAutonome) {
				cout << endl << "Le joueur est non-autonome et n'a pas terminé son contrat actuel. Il ne peut pas être transféré." << endl << endl;
				system("pause");
			}
			else {
				rupture = true;
				NegoTransfert(ancienClub, choixJoueur, joueur, dateActuelle, rupture);
			}
		}
	}

	system("cls");
}

void Ecran::NegoTransfert(Club* clubVendeur, int noJoueur, Joueur* joueur, Date date, bool rupture) {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixNouveauClub;
	float montantDesireVendeur, montantDesireAcheteur;
	float montantMinimal, montantMaximal;
	float dureeNegociation;
	bool succes;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	bool valide;
	do {
		cout << "Entrez le numéro du nouveau club du joueur: ";
		choixNouveauClub = choixClubListe();
		Club* nouveauClub = pLigueHockey->getClub(choixNouveauClub);
		valide = nouveauClub != clubVendeur;
		if (!valide)
			cout << "Le joueur ne peut pas être transféré dans son propre club." << endl;
	} while (!valide);

	Club* clubAcheteur = pLigueHockey->getClub(choixNouveauClub);

	cout << endl << "==================== Négociation ====================" << endl;

	cout << endl << "Vendeur: " << clubVendeur->getNom();
	cout << endl << "Acheteur: " << clubAcheteur->getNom();
	cout << endl;

	cout << endl << "Montant désiré par le vendeur: ";
	montantDesireVendeur = ValiderNombre<float>();

	bool valideMin;
	do {
		cout << "Montant minimal accepté par le vendeur: ";
		montantMinimal = ValiderNombre<float>();
		valideMin = montantMinimal <= montantDesireVendeur;
		if (!valideMin)
			cout << "Le montant minimal du vendeur doit être inférieur ou égal à son montant désiré." << endl;
	} while (!valideMin);


	cout << "Montant désiré par l'acheteur: ";
	montantDesireAcheteur = ValiderNombre<float>();

	bool valideMax;
	do {
		cout << "Montant maximal accepté par l'acheteur: ";
		montantMaximal = ValiderNombre<float>();
		valideMax = montantMaximal >= montantDesireAcheteur;
		if (!valideMax)
			cout << "Le montant maximal de l'acheteur doit être supérieur ou égal à son montant désiré." << endl;
	} while (!valideMax);

	if (montantMaximal < montantMinimal) {
		cout << endl <<  "Les montants maximal et minimal ne permettent pas d'arriver à une entente. Le joueur ne peut pas être transféré." << endl << endl;
		system("pause");
		return;
	}
	
	cout << "Durée de la négociation (en jours): ";
	dureeNegociation = ValiderNombre<float>();

	cout << endl;

	Negociation* negociation = pLigueHockey->creerNegociation(clubAcheteur, clubVendeur, montantDesireVendeur, montantDesireAcheteur, montantMinimal, montantMaximal, dureeNegociation);
	succes = negociation->getSucces();

	if (succes) {
		int dureeContrat;
		int jour, mois, annee;
		float montantTransfert, montantEncaisseClub;
		string descriptionDroits;

		Message dernierMessage = negociation->getFileMessages().back();
		montantTransfert = dernierMessage.getMontantTransfert();

		cout << "La négociation a réussie avec un montant final de " << montantTransfert << "$. Le joueur peut être transféré." << endl << endl;

		clubVendeur->retirerJoueur(noJoueur);
		clubAcheteur->ajouterJoueurTransfert(joueur);

		if (rupture) {
			string raisonsDepart;
			float penalite;
			cout << endl << "==================== Rupture de contrat ====================" << endl << endl;
			cout << "Raisons du départ: ";
			cin.ignore();
			getline(cin, raisonsDepart);
			cout << "Pénalité: ";
			penalite = ValiderNombre<int>();

			Rupture* rupture = pLigueHockey->creerRupture(joueur, raisonsDepart, clubAcheteur, clubVendeur, penalite);
			clubVendeur->ajouterRupture(rupture);
		}

		cout << endl << "==================== Contrat d'engagement ====================" << endl << endl;

		cout << "Durée du contrat (en années): ";
		dureeContrat = ValiderNombre<int>();

		cout << endl << "------------ Ajout du règlement ------------" << endl << endl;
		cout << "Description des droits du joueur: ";
		cin.ignore();
		getline(cin, descriptionDroits);
		bool valide = false;
		do {
			cout << "Montant encaissé par son ancien club: ";
			montantEncaisseClub = ValiderNombre<float>();
			valide = montantEncaisseClub <= montantTransfert;
			if (!valide)
				cout << "Le montant encaissé par le club doit être inférieur ou égal au montant du transfert." << endl;
		} while (!valide);
		
		cout << endl << "------------ Date d'entrée en fonction du joueur ------------" << endl << endl;
		cout << "Jour: "; jour = ValiderNombre<int>();
		cout << "Mois: "; mois = ValiderNombre<int>();
		cout << "Année: "; annee = ValiderNombre<int>();

		Date dateEntree = pLigueHockey->getCalendrier()->creerDate(jour, mois, annee);
		Reglement reglement = pLigueHockey->getContrat()->creerReglement(montantMaximal, descriptionDroits, montantTransfert, montantEncaisseClub);
		ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, clubAcheteur, clubVendeur, dureeContrat, dateEntree, reglement, date);

		joueur->setContratActif(contrat);
		clubVendeur->ajouterContrat(contrat);
	}
	else {
		cout << "Les clubs ne sont pas arrivés à une entente dans le temps alloué. Le joueur ne peut pas être transféré." << endl << endl;
		system("pause");
	}

	delete negociation;
}

void Ecran::AfficherMontantTransferts() {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixClub;
	int choixDate;
	ContratEngagement* contrat;
	int cpt = 0;

	system("cls");

	cout << "==================== Montant de transfert ====================" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le numéro du club pour lequel vous désirer voir les contrats: ";
	choixClub = choixClubListe();

	Club* club = pLigueHockey->getClub(choixClub);

	int nbContrats = club->getNbContrats();

	for (int i = 0; i < nbContrats; i++)
		if (club->getNom() == club->getContrat(i)->getClubLibere()->getNom()) {
			cout << endl << i + 1 << ") " << club->getContrat(i)->getDateContrat().getJour() << "/" << club->getContrat(i)->getDateContrat().getMois() << "/" << club->getContrat(i)->getDateContrat().getAnnee();
			cpt++;
		}

	if (cpt > 0) {
		cout << endl << endl << "Entrez le numéro de la date pour laquelle vous souhaitez voir le montant de transfert encaissé par le club: ";
		choixDate = ValiderNombre<int>();
		choixDate--;

		contrat = club->getContrat(choixDate);

		while (contrat == nullptr) {
			cout << "Aucun contrat ne correspond à ce nombre, veuillez réessayer: ";
			choixDate = ValiderNombre<int>();
			choixDate--;
			contrat = club->getContrat(choixDate);
		}

		cout << endl << "Le montant de transfert encaissé par le club à cette date est de " << club->getContrat(choixDate)->getReglement().getMontantAncienClub() << "$." << endl << endl;
	}
	else
		cout << endl << "Ce club n'a aucun contrat dans lequel il a encaissé un montant à son actif." << endl << endl;

	system("pause");
	system("cls");
}

int Ecran::choixClubListe() {
	Club* club;

	int choix;
	choix = ValiderNombre<int>();
	choix--;
	cin.ignore();

	club = pLigueHockey->getClub(choix);

	while (club == nullptr) {
		cout << "Aucun club ne correspond à ce nombre, veuillez réessayer: ";
		choix = ValiderNombre<int>();
		choix--;
		club = pLigueHockey->getClub(choix);
	}

	return choix;
}