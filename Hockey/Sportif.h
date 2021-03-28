#pragma once
#include <string>
using namespace std;

class Sportif
{
	string prenom;
	string nom;

public:
	Sportif() {}
	Sportif(string prenom, string nom);

	string getPrenom() { return prenom; }
	string getNom() { return nom; }
};