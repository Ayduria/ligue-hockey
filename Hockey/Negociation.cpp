#include "Negociation.h"
#include "Ecran.h"

Negociation::Negociation(NegoVendeur vendeur, NegoAcheteur acheteur, float dureeNegociation, chrono::steady_clock::time_point tempsDebut)
{
	this->dureeNegociation = dureeNegociation;
	this->tempsDebut = tempsDebut;
	this->termine = false;
	this->succes = false;
	this->threadActif = 0;

	thread tVendeur(&Negociation::Negocier, this, &vendeur);
	thread tAcheteur(&Negociation::Negocier, this, &acheteur);

	tVendeur.join();
	tAcheteur.join();
}

void Negociation::Negocier(Negociateur* negociateur)
{
	negoMutex.lock();
	threadActif++;
	negoMutex.unlock();
	while (threadActif != 2) {}
	while (!termine) {
		negoMutex.lock();
		chrono::steady_clock::time_point tempsCourant = chrono::steady_clock::now();
		chrono::milliseconds tempsEcoule = chrono::duration_cast<chrono::milliseconds>(tempsCourant - tempsDebut);
		termine = termine || tempsEcoule.count() >= dureeNegociation * 1000;

		if (!termine) {
			if (fileMessages.size() > 0) {
				Message offreActuelle = fileMessages.back();
				if (offreActuelle.getEmetteur() != negociateur->getRepresentant()->getNom()) {
					if (negociateur->verifierOffre(offreActuelle.getMontantTransfert())) {
						accepterOffre(negociateur->getRepresentant()->getNom(), offreActuelle.getMontantTransfert());
						termine = true;
						succes = true;
					}
					else
						rejeterOffre(negociateur->getRepresentant()->getNom(), offreActuelle.getMontantTransfert());
				}
			}
			if (!termine) {
				if (fileMessages.size() > 0)
					negociateur->calculerMontant(tempsEcoule.count());
				proposerOffre(negociateur->getRepresentant()->getNom(), negociateur->getMontantDesire());
			}
		}
		negoMutex.unlock();
		if (!termine)
			this_thread::sleep_for(chrono::milliseconds(500));
	}
}

void Negociation::proposerOffre(string emetteur, float montant) {
	Message message(emetteur, "Nouvelle offre", montant);
	fileMessages.push(message);
	Ecran::AfficherMessage(message);
}

void Negociation::accepterOffre(string emetteur, float montant) {
	Message message(emetteur, "Offre acceptée", montant);
	fileMessages.push(message);
	Ecran::AfficherMessage(message);
}

void Negociation::rejeterOffre(string emetteur, float montant) {
	Message message(emetteur, "Offre refusée", montant);
	fileMessages.push(message);
	Ecran::AfficherMessage(message);
}