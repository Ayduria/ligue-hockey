#include "Calendrier.h"
#include "Date.h"

Calendrier::Calendrier(void) {}

Date Calendrier::creerDate(int jour, int mois, int annee) {
	Date date(jour, mois, annee);
	return date;
}

void Calendrier::AjouterRencontre(Date dateRencontre, Club* clubLocal, Club* clubInvite) {
	Rencontre rencontre(dateRencontre, clubLocal, clubInvite);
	listeRencontres.push_back(rencontre);
}

vector<Rencontre> Calendrier::TrouverRencontresClub(Club* club) {
	Club* clubLocal;
	Club* clubInvite;
	vector<Rencontre> listeRencontresClub;

	for (size_t i = 0; i < listeRencontres.size(); i++) {
		clubLocal = listeRencontres.at(i).getClubLocal();
		clubInvite = listeRencontres.at(i).getClubInvite();

		if ((club == clubLocal) || (club == clubInvite)) {
			listeRencontresClub.push_back(listeRencontres.at(i));
		}
	}

	return listeRencontresClub;
}

Rencontre* Calendrier::getRencontreDate(int jour, int mois, int annee) {
	for (int i = 0; i < listeRencontres.size(); i++) {
		if (listeRencontres.at(i).getDate().getJour() == jour && listeRencontres.at(i).getDate().getMois() == mois && listeRencontres.at(i).getDate().getAnnee() == annee)
		{
			return &listeRencontres[i];
		}
	}
}