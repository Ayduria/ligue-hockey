#pragma once
#include <string>
using namespace std;

class Negociateur;

class Message
{
	string emetteur;
	string sujetMessage;
	float montantTransfert;

public:
	Message(string emetteur, string sujetMessage, float montantTransfert);

	string getEmetteur() { return emetteur; }
	string getSujet() { return sujetMessage; }
	float getMontantTransfert() { return montantTransfert; }
};