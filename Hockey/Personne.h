#pragma once
#include <string>

using namespace std;

class Personne
{
	string prenom;
	string nom;

public:
	Personne () {}
	Personne(string prenom, string nom);

	string getPrenom() { return prenom; }
	string getNom() { return nom; }
};