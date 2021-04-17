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
	void savePalmares();
	void saveJoueurs();
	void saveContrats();
	void saveRuptures();
	void saveEntraineur();
	void saveTitres();
	void saveRencontres();
	void saveMatchs();
};