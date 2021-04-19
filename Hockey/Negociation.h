#pragma once
#include "NegoVendeur.h"
#include "NegoAcheteur.h"
#include <mutex>
#include <chrono>
#include <thread>
#include <queue>

class Negociation
{
	float dureeNegociation;
	chrono::steady_clock::time_point tempsDebut;
	mutex negoMutex;
	bool termine;
	bool succes;
	queue<Message> fileMessages;
	int threadActif;

public:
	Negociation(NegoVendeur vendeur, NegoAcheteur acheteur, float dureeNegociation, chrono::steady_clock::time_point tempsDebut);

	float getDureeNegociation() { return dureeNegociation; }
	chrono::steady_clock::time_point getTempsDebut() { return tempsDebut; }
	queue<Message> getFileMessages() { return fileMessages; }
	bool getSucces() { return succes; }

	void Negocier(Negociateur* negociateur);
	void proposerOffre(string emetteur, float montant);
	void accepterOffre(string emetteur, float montant);
	void rejeterOffre(string emetteur, float montant);
};