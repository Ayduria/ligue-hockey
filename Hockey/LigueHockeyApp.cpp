#include "Ecran.h"
#include "�criture.h"

LigueHockey* pLigueHockey = new LigueHockey();
Ecran ecran(pLigueHockey);
�criture ecriture(pLigueHockey);

int main()
{
    setlocale(LC_CTYPE, "fr-FR");
    ecran.initHardcode();
    ecriture.enregistrer();
    ecran.MenuPrincipal();

    return 0;
}