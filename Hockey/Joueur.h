#pragma once
#include "Parcours.h"
#include "Sportif.h"
#include<string>

using namespace std;

class Joueur : public Sportif
{
private:
	float taille;
	float poids;
	string villeNaissance;
	Parcours parcours;

public:
	Joueur () {}
	Joueur(string prenom, string nom, float taille, float poids, string ville, Parcours parcours);

	virtual bool transfert() { return true; }
};