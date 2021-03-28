#include "Rencontre.h"

Rencontre::Rencontre(Date dateRencontre, Club* clubLocal, Club* clubInvite) {
	this->dateRencontre = dateRencontre;
	this->clubLocal = clubLocal;
	this->clubInvite = clubInvite;
	this->match = nullptr;
}

Match* Rencontre::creerMatch(Equipe equipeLocale, Equipe equipeInvitee) {
	Match* match = new Match(equipeLocale, equipeInvitee);
	return match;
}