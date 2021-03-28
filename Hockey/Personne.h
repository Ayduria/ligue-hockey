#pragma once
#include <string>

using namespace std;

class Personne
{
private:
	string nom;
	int age;
	string role;

public:
	Personne(string nom, int age, string role);
};