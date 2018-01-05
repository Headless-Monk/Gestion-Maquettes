#include <iostream>

#include "maquette.h"
#include "afficheur_txt.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"

void test_afficheur()
{
    maquette m{"Licence Informatique", "MIAGE", 3, 5};

    UEseule u1{15, 15, 0, "13GUIAR5", "UE INTELLIGENCE ARTIFICIELLE", 3, 1};

    ecue e1{"13GPQUA5", "ECUE qualite de programmation", 12, 6, 6};
    ecue e2{"13GPETC5", "ECUE Etudes de cas", 0, 16, 0};
    UEcomposee u2{"13GUPRG5", "UE DE L'ETUDE DE CAS A LA PROGRAMMATION", 3, 1};
    u2.ajouter_ecue(&e1);
    u2.ajouter_ecue(&e2);

    UEseule u3(14, 22, 0, "13GUALGO", "UE ALGORITHMIQUE ET STRUCTURES RECURSIVES", 3, 1);

    m.ajouter_ue(&u1);
    m.ajouter_ue(&u2);
    m.ajouter_ue(&u3);

    afficheur_txt aff{};
    aff.exporter_maquette(m);
}

int main()
{
    test_afficheur();
    return 0;
}
