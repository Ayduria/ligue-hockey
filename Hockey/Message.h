#pragma once
#include <string>
using namespace std;

class Negociateur;

class Message
{
	Negociateur* emetteur;
	string sujetMessage;
	float montantTransfert;

public:
	Message(Negociateur* emetteur, string sujetMessage, float montantTransfert);

	Negociateur* getEmetteur() { return emetteur; }
	string getSujet() { return sujetMessage; }
	float getMontantTransfert() { return montantTransfert; }
};