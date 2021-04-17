#pragma once
#include <string>

using namespace std;

class Palmares
{
private:
	string titre;
	string date;

public:
	Palmares() {}
	Palmares(string titre, string date);

	string getTitre() { return titre; }
	string getDate() { return date; }
};