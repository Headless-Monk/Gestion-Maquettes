#include <iostream>

#include "maquette.h"
#include "afficheur_txt.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"

void test_afficheur()
{
    maquette m{"Licence Informatique", "MIAGE", 3, 5};

    UEseule u1{10, 8, 4, "13g1de", "u1", 3, 1};

    ecue e1{"15frfr6", "ecue1", 12, 6, 15};
    ecue e2{"15er664", "ecue2", 2, 4, 59};
    UEcomposee u2{"15ef661", "ue2", 6, 2};
    u2.ajouter_ecue(&e1);
    u2.ajouter_ecue(&e2);

    UEseule u3(1, 2, 3, "df26df5", "u3", 1, 1);

    afficheur_txt aff{};
    aff.exporter_maquette(m);
}

int main()
{
    test_afficheur();
    return 0;
}
