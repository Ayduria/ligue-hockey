#include "Ecran.h"
#include "Écriture.h"
#include "Lecture.h"

LigueHockey* pLigueHockey = new LigueHockey();
Ecran ecran(pLigueHockey);
Écriture ecriture(pLigueHockey);
Lecture lecture(pLigueHockey);

int main()
{
    setlocale(LC_CTYPE, "fr-FR");
    lecture.lire();
    ecran.MenuPrincipal();
    ecriture.enregistrer();
    return 0;
}