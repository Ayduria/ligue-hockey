#pragma once
#include <string>
#include "Personne.h"
using namespace std;

class Sportif : virtual public Personne
{
	string villeNaissance;

public:
	Sportif() {}
	Sportif(string prenom, string nom, string villeNaissance);

	string getVilleNaissance() { return villeNaissance; }
};