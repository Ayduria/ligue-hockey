#pragma once
#include "Club.h"
#include "Message.h"
#include <queue>

class Negociateur
{
	float montantDesire;
	int dureeNegociation;
	Club* representantClub;
	queue<Message> fileMessages;

public:
	float getMontantDesire() { return montantDesire; }
	int getDureeNegociation() { return dureeNegociation; }
	Club* getRepresentant() { return representantClub; }
	queue<Message> getFileMessages() { return fileMessages; }
};