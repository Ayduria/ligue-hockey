#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>

#include "LigueHockey.h"
#include "Sportif.h"

class �criture {
private:

	LigueHockey* pLigueHockey;

public:

	�criture(LigueHockey* ligue) { pLigueHockey = ligue; }

	void enregistrer();
	void saveClubs();
};