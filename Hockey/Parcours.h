#pragma once
#include <string>
#include <vector>

using namespace std;

class Parcours
{
private:
	vector<string> listeClubs;

public:
	vector<string>* GetListeClubs() { return &listeClubs; }

	void AjouterClubDate(string club, string date);
};