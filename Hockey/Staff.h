#pragma once
#include <string>
#include "Personne.h"
using namespace std;

class Staff : virtual public Personne
{
	int age;
	string role;

public:
	Staff() {}
	Staff(string prenom, string nom, int age, string role);

	int getAge() { return age; }
};