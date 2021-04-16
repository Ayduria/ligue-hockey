#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include "LigueHockey.h"
#include "Sportif.h"

class Écriture {
private:

	LigueHockey* pLigueHockey;

public:

	Écriture(LigueHockey* ligue) { pLigueHockey = ligue; }

	void enregistrer();
	void saveClubs();
};