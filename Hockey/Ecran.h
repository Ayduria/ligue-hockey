#pragma once
#include "LigueHockey.h"
#include <locale>
#include <iostream>

using namespace std;

class Ecran
{
private:

	LigueHockey* pLigueHockey;

public:

	Ecran(LigueHockey* ligue) { pLigueHockey = ligue; }

	void Menu();
	void MenuPrincipal();
	void AfficherClub();
	void AjouterClub();
	void AjouterJoueurClub();
	void ListeClubs();
	void SupprimerClub();
	void AfficherPlusTitre();
	void AjouterJoueur(string nom);
	void AjouterParcours(string prenom, string nom, string nomClub);
	void AjouterPalmares(string nom);
	void AjouterStade(string nom);
	void AjouterStaff(string nom);
	void AjouterEntraineur();
	void AjouterTitreGagne(string prenom, string nom);

	void AjouterRencontre();
	void AfficherCalendrierClub();
	void AjouterMatch();
	void AfficherResultatMatch();
	void AjouterTransfertJoueur();
	void AfficherMontantTransferts();
	Equipe CreerEquipe(Club* club, int noRencontre);
	void AjouterPeriode(int noRencontre);
	void NegoTransfert(Club* clubVendeur, Club* clubAcheteur, int noJoueur, Joueur* joueur, Date date, bool rupture);

	template<typename T>
	T ValiderNombre();

	int choixClubListe();

	static void AfficherMessage(Message message) {
		cout <<
			"Club de l'émetteur : " << message.getEmetteur() << endl <<
			"Sujet : " << message.getSujet() << endl <<
			"Montant : " << message.getMontantTransfert() << "$" << endl <<
			endl;
	}
};

template<typename T>
T Ecran::ValiderNombre() {
	T nombre;

	while (!(cin >> nombre)) {
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Entrée invalide, veuillez entrer un nombre: ";
	}
	return nombre;
}