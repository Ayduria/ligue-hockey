#include "Ecran.h"
#include "Écriture.h"

LigueHockey* pLigueHockey = new LigueHockey();
Ecran ecran(pLigueHockey);
Écriture ecriture(pLigueHockey);

int main()
{
    setlocale(LC_CTYPE, "fr-FR");
    ecran.initHardcode();
    ecriture.enregistrer();
    ecran.MenuPrincipal();

    return 0;
}