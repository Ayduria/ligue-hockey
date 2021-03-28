#pragma once
#include "Date.h"
#include "Club.h"
#include "Match.h"

class Rencontre
{
	Date dateRencontre;
	Club* clubLocal;
	Club* clubInvite;
	Match* match;

public:
	Rencontre(Date dateRencontre, Club* clubLocal, Club* clubInvite);

	Date getDate() { return dateRencontre; }
	Club* getClubLocal() { return clubLocal; }
	Club* getClubInvite() { return clubInvite; }
	Match* getMatch() { return match; }

	Match* creerMatch(Equipe equipeLocale, Equipe equipeInvitee);
	void setMatch(Match* match) { this->match = match; }
};