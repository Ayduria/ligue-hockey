#include "�criture.h"

//formatage-conversion-en chaine de caract�re
inline string IntToString(const double& val)
{
	stringstream unflux;
	unflux << val;
	return unflux.str();
}
void �criture::enregistrer() {

}
void �criture::saveClubs() {
	string clubNom;
	string clubHistoire;
	string clubCouleur;
	string dateOrigine;
	vector<Joueur*> effectif;
	vector<Palmares> clubPalmares;
	Stade stade;
	string ville;
	string adresse;
	vector<Staff> staffTechnique;
	vector<ContratEngagement*> listeContrats;
	vector<Rupture*> listeRuptures;

	vector<Club> listeClub = *pLigueHockey->getListeClubs();
	vector<Club>::iterator it;

	ofstream fichierClubs("../clubs.txt", ios::out);

	for (it = listeClub.begin(); it != listeClub.end(); it++) {
		clubNom = it->getNom();
		clubHistoire = it->
	}
}