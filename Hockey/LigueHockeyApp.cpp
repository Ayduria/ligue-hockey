#include "Ecran.h"

LigueHockey* pLigueHockey = new LigueHockey();
Ecran ecran(pLigueHockey);

int main()
{
    setlocale(LC_CTYPE, "fr-FR");
    ecran.initHardcode();
    ecran.MenuPrincipal();

    return 0;
}