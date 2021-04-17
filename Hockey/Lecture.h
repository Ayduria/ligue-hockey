#pragma once
#include <iostream>
#include <fstream>

#include <vector>

#include "LigueHockey.h"

class Lecture {
private:

	LigueHockey* pLigueHockey;

public:

	Lecture(LigueHockey* ligue) { pLigueHockey = ligue; }

	void lire();
	void lireClubs();
	void lirePalmares();
	void lireJoueurs();
	void lireContrats();
	void lireRuptures();
	void lireEntraineur();
	void lireTitres();
	void lireRencontres();
	void lireMatchs();
};