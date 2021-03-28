#include "Parcours.h"

void Parcours::AjouterClubDate(string club, string date) {

	string newClub = club + "|" + date;
	listeClubs.insert(listeClubs.begin(), newClub);

}