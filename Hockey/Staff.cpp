#include "Staff.h"

Staff::Staff(string prenom, string nom, int age, string role) : Personne(prenom, nom) {
	this->age = age;
	this->role = role;
}