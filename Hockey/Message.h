#pragma once
#include <string>
using namespace std;

class Message
{
	string emetteur;
	string sujetMessage;
	float montantTransfert;

public:
	string getEmetteur() { return emetteur; }
	string getSujet() { return sujetMessage; }
	float getMontantTransfert() { return montantTransfert; }
};