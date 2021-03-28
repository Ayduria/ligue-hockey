#pragma once
#include "LigueHockey.h"
#include <locale>

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
	Parcours AjouterParcours();
	void AjouterPalmares(string nom);
	void AjouterStade(string nom);
	void AjouterStaff(string nom);
	void AjouterEntraineur();
	vector<TitreGagne> AjouterTitreGagne();

	void AjouterRencontre();
	void AfficherCalendrierClub();
	void AjouterMatch();
	void AfficherResultatMatch();
	void AjouterTransfertJoueur();
	void AfficherMontantTransferts();
	Equipe CreerEquipe(Club* club, int noRencontre);
	void AjouterPeriode(int noRencontre);
	void creerContrat(Joueur* joueur, Club* ancienClub, Club* nouveauClub);

	void initHardcode();
};