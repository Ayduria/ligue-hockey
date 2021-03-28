#pragma once
#include <string>

using namespace std;

class Stade
{
private:
	int capacite;
	string qualiteTerrain;
	string nom;
	string adresse;

public:
	Stade() { this->capacite = 0; }
	Stade(int capacite, string qualiteTerrain, string nom, string adresse);
};