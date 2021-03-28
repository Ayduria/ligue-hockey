#pragma once
#include "Equipe.h"
#include "Periode.h"
#include "Resultat.h"
#include <vector>

class Match
{
	Equipe equipeLocale;
	Equipe equipeInvitee;
	vector<Periode> listePeriodes;
	Resultat resultatFinal;

public:
	Match () {}
	Match(Equipe equipeLocale, Equipe equipeInvitee);

	Equipe getEquipeLocale() { return equipeLocale; }
	Equipe getEquipeInvitee() { return equipeInvitee; }
	vector<Periode>* getListePeriodes() { return &listePeriodes; }
	Resultat getResultatFinal() { return resultatFinal; }

	void setResultatFinal(Resultat resultatFinal) { this->resultatFinal = resultatFinal; }

	Equipe creerEquipe(Club* club, int nbJoueursTerrain, int nbGardiens, Joueur* capitaine);
	void ajouterPeriode(int dureePeriode, int nbButsLocale, int nbButsAdverse);
	Resultat calculerResultat();
};