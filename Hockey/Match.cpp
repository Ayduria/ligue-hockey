#include "Match.h"

Match::Match(Equipe equipeLocale, Equipe equipeInvitee) {
	this->equipeLocale = equipeLocale;
	this->equipeInvitee = equipeInvitee;
}

Equipe Match::creerEquipe(Club* club, int nbJoueursTerrain, int nbGardiens, Joueur* capitaine) {
	Equipe equipe(club, nbJoueursTerrain, nbGardiens, capitaine);
	return equipe;
}

void Match::ajouterPeriode(int dureePeriode, int nbButsLocale, int nbButsAdverse) {
	Periode periode(dureePeriode, nbButsLocale, nbButsAdverse);
	listePeriodes.push_back(periode);
}

Resultat Match::calculerResultat() {
	int resultatLocal = 0;
	int resultatAdverse = 0;

	for (size_t i = 0; i < listePeriodes.size(); i++) {
		resultatLocal = resultatLocal + listePeriodes.at(i).getNbButsLocale();
		resultatAdverse = resultatAdverse + listePeriodes.at(i).getNbButsAdverse();
	}

	Resultat resultat(resultatLocal, resultatAdverse);
	return resultat;
}