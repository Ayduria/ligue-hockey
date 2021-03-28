#include "Ecran.h"
#include <iostream>
#include <vector>

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
	vector<Joueur> listeJoueur;

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
	string nomClub;
	string continuer = "o";

	system("cls");
	ListeClubs();
	cout << endl << "Entrez le nom du club dans lequel vous d�sirez ajouter des joueurs: ";
	getline(cin, nomClub);

	Club* club = pLigueHockey->chercherClub(nomClub);

	if (club != NULL)
	{
		cout << endl << "==================== Ajout de joueurs dans le club " + nomClub + " ====================" << endl;

		while (continuer == "o") {
			AjouterJoueur(nomClub);
			cout << endl << "Voulez-vous ajouter un autre joueur ? (o/n) ";
			getline(cin, continuer);
		}
	}
	else
		cout << endl << "Le club " + nomClub + " n'existe pas." << endl << endl;

	system("cls");
}

void Ecran::ListeClubs() {
	int nbClubs = pLigueHockey->getNbClubs();

	cout << "---------- Liste des clubs ----------" << endl << endl;

	for (int i = 0; i < nbClubs; i++)
	{
		cout << pLigueHockey->getClub(i)->getNom() << endl;
	}
}

void Ecran::AjouterJoueur(string nomClub) {
	string prenom;
	string nom;
	float taille;
	float poids;
	string ville;
	Parcours parcours;
	string autonome;
	int anciennete;

	cout << endl << "Pr�nom du joueur: ";
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
	cout << endl << "----- Parcours du joueur -----" << endl;
	parcours = AjouterParcours();
	cout << endl << "Le joueur est-il autonome (o/n) ? ";
	cin >> autonome;
	if(autonome == "n") {
		cout << endl << "Ann�es accumul�es par le joueur: ";
		cin >> anciennete;
		pLigueHockey->chercherClub(nomClub)->ajouterJoueurNonAutonome(prenom, nom, taille, poids, ville, parcours, anciennete);
	} else
		pLigueHockey->chercherClub(nomClub)->ajouterJoueurAutonome(prenom, nom, taille, poids, ville, parcours);

}

Parcours Ecran::AjouterParcours() {
	string club;
	string date;
	string ajouterParcours = "o";
	Parcours parcours;

	while (ajouterParcours == "o")
	{
		cout << endl << "Club auquel le joueur a particip�: ";
		getline(cin, club);
		cout << "Date de passage dans le club: ";
		getline(cin, date);
		parcours.AjouterClubDate(club, date);

		cout << endl << "Voulez-vous ajouter un autre titre au parcours ? (o/n) ? ";
		getline(cin, ajouterParcours);
	}
	return parcours;
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
	cin >> capacite;
	cin.ignore();
	cout << "Qualit� du terrain (Gazon ou Tartan): ";
	getline(cin, qualite);
	cout << "Adresse du stade: ";
	getline(cin, adresse);

	pLigueHockey->chercherClub(nomClub)->setStade(capacite, qualite, nom, adresse);
}

void Ecran::AjouterStaff(string nomClub) {
	string nom;
	int age;
	string role;

	cout << endl << "Nom de l'employ�: ";
	getline(cin, nom);
	cout << "�ge de l'employ�: ";
	cin >> age;
	cin.ignore();
	cout << "R�le de l'employ�: ";
	getline(cin, role);

	pLigueHockey->chercherClub(nomClub)->ajouterPersonne(nom, age, role);
}

void Ecran::SupprimerClub() {
	string nom;
	bool trouver;

	system("cls");
	cout << "==================== Suppression de club ====================" << endl << endl;
	ListeClubs();
	cout << endl << "Entrez le nom du club que vous souhaitez supprimer: ";
	getline(cin, nom);

	trouver = pLigueHockey->retirerClub(nom);

	if (trouver)
		cout << endl << "Le club " + nom + " a �t� supprim�.";
	else
		cout << endl << "Le club " + nom + " n'existe pas.";

	cout << endl << endl;

	system("pause");
	system("cls");

}

void Ecran::AfficherClub() {
	string nom;

	system("cls");
	ListeClubs();
	cout << endl << "Entrez le nom du club dont vous souhaitez afficher les joueurs: ";
	getline(cin, nom);

	Club* club = pLigueHockey->chercherClub(nom);

	if (club != NULL)
	{
		cout << endl << "=================== Liste de joueurs du club " + nom + " ===================" << endl;

		vector<Joueur*> listeJoueur = club->getEffectif();

		if (listeJoueur.size() == 0)
			cout << endl << "Il n'y a pas de joueurs dans ce club.";
		else {
			for (size_t i = 0; i < listeJoueur.size(); i++) {
				cout << endl << listeJoueur.at(i)->getPrenom() + " " + listeJoueur.at(i)->getNom();
			}
		}
	}
	else
		cout << endl << "Le club " + nom + " n'existe pas.";

	cout << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::AjouterEntraineur() {
	string nom;
	string prenom;
	string grade;
	vector<TitreGagne> titreGagne;

	system("cls");
	cout << "=================== Ajout d'entra�neur ===================" << endl;
	cout << endl << "Pr�nom de l'entra�neur: ";
	getline(cin, prenom);
	cout << "Nom de l'entra�neur: ";
	getline(cin, nom);
	cout << "Lieu d'obtention de son grade: ";
	getline(cin, grade);

	cout << endl << "---------- Titres gagn�s ----------" << endl;
	titreGagne = AjouterTitreGagne();

	pLigueHockey->ajouterCoach(nom, prenom, grade, titreGagne);
	system("cls");
}

vector<TitreGagne> Ecran::AjouterTitreGagne() {
	string continuer = "o";
	string nom;
	string date;
	string nomClub;
	vector<TitreGagne> titreGagnes;
	Club* club;

	while (continuer == "o") {

		cout << endl << "Nom du titre: ";
		getline(cin, nom);
		cout << "Date � laquelle le club de l'entra�neur a gagn� ce titre: ";
		getline(cin, date);
		cout << "Nom du club avec lequel l'entra�neur a gagn� ce titre: ";
		getline(cin, nomClub);

		club = pLigueHockey->chercherClub(nomClub);
		titreGagnes = pLigueHockey->ajouterTitreGagne(nom, date, club, titreGagnes);
		
		cout << endl << "Ajouter un autre titre gagn� ? (o/n) ";
		getline(cin, continuer);
	}
	return titreGagnes;
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
	cin >> jour;
	cout << "Mois: ";
	cin >> mois;
	cout << "Ann�e: ";
	cin >> annee;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le num�ro du club local: ";
	cin >> clubLocal;
	clubLocal--;
	cout << "Entrez le num�ro du club invit�: ";
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

	cout << endl << endl << "Entrez le num�ro du club pour lequel vous d�sirez afficher les rencontres: ";
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
		cin >> choix;
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
	cin >> nbJoueursTerrain;
	cout << "Nombre de gardiens: ";
	cin >> nbGardiens;
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
	cin >> dureePeriode;
	cout << "Nombre de buts marqu�s par l'�quipe locale: ";
	cin >> nbButsLocale;
	cout << "Nombre de buts marqu�s par l'�quipe adverse: ";
	cin >> nbButsAdverse;

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
		cin >> choix;
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
	bool joueurAutonome;

	system("cls");

	cout << "==================== Ajout de transaction de transfert de joueur ====================" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le num�ro du club du joueur que vous d�sirez transf�rer: ";
	cin >> choixAncienClub;
	choixAncienClub--;

	Club* ancienClub = pLigueHockey->getClub(choixAncienClub);

	vector<Joueur*> listeJoueurs = ancienClub->getEffectif();
	int nbJoueurs = ancienClub->getNbJoueurs();

	for (int i = 0; i < nbJoueurs; i++)
		cout << endl << i + 1 << ") " << listeJoueurs.at(i)->getPrenom() << " " << listeJoueurs.at(i)->getNom();

	cout << endl << endl << "Entrez le num�ro du joueur que vous d�sirez transf�rer: ";
	cin >> choixJoueur;
	choixJoueur--;

	Joueur* joueur = ancienClub->getJoueur(choixJoueur);

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl;

	cout << "Entrez le num�ro du Nouveau club du joueur: ";
	cin >> choixNouveauClub;
	choixNouveauClub--;

	Club* nouveauClub = pLigueHockey->getClub(choixNouveauClub);

	joueurAutonome = joueur->transfert();

	if (joueurAutonome) {
		int choix;
		cout << endl;
		cout << "1) Ajouter un contrat d'engagement" << endl;
		cout << "2) Rompre un contrat" << endl;
		cout << endl << "Entrez le num�ro de l'option d�sir�e: ";
		cin >> choix;

		if (choix == 1)
			creerContrat(joueur, ancienClub, nouveauClub);
		else {
			string raisonsDepart;
			float penalite;
			cout << endl << "==================== Rupture de contrat ====================" << endl << endl;
			cout << "Raisons du d�part: ";
			cin.ignore();
			getline(cin, raisonsDepart);
			cout << "P�nalit�: ";
			cin >> penalite;

			Rupture* rupture = pLigueHockey->creerRupture(joueur, raisonsDepart, nouveauClub, penalite);
			ancienClub->ajouterRupture(rupture);
		}
	} else
		creerContrat(joueur, ancienClub, nouveauClub);

	system("cls");
}

void Ecran::creerContrat(Joueur* joueur, Club* ancienClub, Club* nouveauClub) {
	int dureeContrat;
	int JourE, MoisE, AnneeE;
	int JourC, MoisC, AnneeC;
	float seuil, montantTransfert, montantEncaisseClub;
	string descriptionDroits;

	cout << endl << "==================== Contrat d'engagement ====================" << endl << endl;

	cout << "Dur�e du contrat: ";
	cin >> dureeContrat;

	cout << endl << "------------ Date d'entr�e en fonction ------------" << endl << endl;
	cout << "Jour: "; cin >> JourE;
	cout << "Mois: "; cin >> MoisE;
	cout << "Jour: "; cin >> AnneeE;

	cout << endl << "------------ Ajout du r�glement ------------" << endl << endl;
	cout << "Seuil en vigueur: ";
	cin >> seuil;
	cout << "Description des droits du joueur: ";
	cin.ignore();
	getline(cin, descriptionDroits);
	cout << "Montant du transfert: ";
	cin >> montantTransfert;
	cout << "Montant encaiss� par son ancien club: ";
	cin >> montantEncaisseClub;

	cout << endl << "------------ Date du contrat ------------" << endl << endl;
	cout << "Jour: "; cin >> JourC;
	cout << "Mois: "; cin >> MoisC;
	cout << "Jour: "; cin >> AnneeC;

	Date dateEntree = pLigueHockey->getCalendrier()->creerDate(JourE, MoisE, AnneeE);
	Reglement reglement = pLigueHockey->getContrat()->creerReglement(seuil, descriptionDroits, montantTransfert, montantEncaisseClub);
	Date dateContrat = pLigueHockey->getCalendrier()->creerDate(JourC, MoisC, AnneeC);
	ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, nouveauClub, ancienClub, dureeContrat, dateEntree, reglement, dateContrat);

	ancienClub->ajouterContrat(contrat);
}

void Ecran::AfficherMontantTransferts() {
	int nbClubs = pLigueHockey->getNbClubs();
	int choixClub;
	int choixDate;

	system("cls");

	cout << "==================== Montant de transfert ====================" << endl;

	for (int i = 0; i < nbClubs; i++)
		cout << endl << i + 1 << ") " << pLigueHockey->getClub(i)->getNom();

	cout << endl << endl << "Entrez le num�ro du club pour lequel vous d�sirer voir les dates de contrats: ";
	cin >> choixClub;
	choixClub--;

	Club* club = pLigueHockey->getClub(choixClub);

	int nbContrats = club->getNbContrats();

	for (int i = 0; i < nbContrats; i++)
		cout << endl << i + 1 << ") " << club->getContrat(i)->getDateContrat().getJour() << "/" << club->getContrat(i)->getDateContrat().getMois() << "/" << club->getContrat(i)->getDateContrat().getAnnee();

	cout << endl << endl << "Entrez le num�ro de la date pour laquelle vous souhaitez voir le montant de transfert encaiss� par le club: ";
	cin >> choixDate;
	choixDate--;

	cout << endl << "Le montant de transfert encaiss� par le club � cette date est de " << club->getContrat(choixDate)->getReglement().getMontantAncienClub() << "$." << endl << endl;

	system("pause");
	system("cls");
}

void Ecran::initHardcode() {
	Parcours parcours;
	parcours.AjouterClubDate("club", "2000");
	vector<TitreGagne> titreGagnes1;
	vector<TitreGagne> titreGagnes2;

	pLigueHockey->ajouterClub("Pingouins", "Histoire du club", "Blanc", "2000", "Saguenay", "UQAC");
	pLigueHockey->ajouterClub("Tigres", "Histoire du club", "Orange", "1999", "Montr�al", "UQAM");
	pLigueHockey->ajouterClub("Requins", "Histoire du club", "Bleu", "2002", "Laval", "ULAVAL");

	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurAutonome("Jean", "Tremblay", 180, 200, "Saguenay", parcours);
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurAutonome("Simon", "Girard", 150, 180, "Alma", parcours);
	pLigueHockey->chercherClub("Pingouins")->ajouterJoueurNonAutonome("Jeanne", "B�dard", 160, 140, "Chicoutimi", parcours, 2);
	pLigueHockey->chercherClub("Tigres")->ajouterJoueurNonAutonome("Laurie", "Potvin", 150, 130, "Saguenay", parcours, 4);
	pLigueHockey->chercherClub("Tigres")->ajouterJoueurNonAutonome("Peter", "St-Gelais", 200, 210, "Montr�al", parcours, 3);
	pLigueHockey->chercherClub("Requins")->ajouterJoueurAutonome("Robert", "Girard", 150, 175, "Alma", parcours);
	pLigueHockey->chercherClub("Requins")->ajouterJoueurAutonome("Julie", "Simard", 125, 150, "Chicoutimi", parcours);

	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Coupe junior", "2 juin 2002");
	pLigueHockey->chercherClub("Tigres")->ajouterPalmares("Championnat provincial", "5 septembre 2005");
	pLigueHockey->chercherClub("Pingouins")->ajouterPalmares("Championnat r�gional", "1er Mai 2000");

	titreGagnes1 = pLigueHockey->ajouterTitreGagne("Meilleur coach", "2 janvier 2000", pLigueHockey->chercherClub("Pingouins"), titreGagnes1);
	titreGagnes1 = pLigueHockey->ajouterTitreGagne("Coach le plus efficace", "3 d�cembre 2005", pLigueHockey->chercherClub("Pingouins"), titreGagnes1);
	titreGagnes2 = pLigueHockey->ajouterTitreGagne("Coach le plus appr�ci�", "8 f�vrier 2008", pLigueHockey->chercherClub("Tigres"), titreGagnes2);
	pLigueHockey->ajouterCoach("Simon", "Kant", "�cole de la vie", titreGagnes2);
	pLigueHockey->ajouterCoach("Marc-Antoine", "Larouche", "Nicolet", titreGagnes1);

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
	ContratEngagement* contrat = pLigueHockey->creerContrat(joueur, pLigueHockey->chercherClub("Requins"), pLigueHockey->chercherClub("Tigres"), 5, date1, reglement, date2);
	pLigueHockey->chercherClub("Requins")->ajouterContrat(contrat);
}