#include <iostream>

#include "maquette.h"
#include "afficheur_txt.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"
#include "interface.h"
#include "ue.h"

void test_afficheur()
{
    maquette m{"Licence Informatique", "MIAGE", 3, 5};

    UEcomposee u1{"13GUPRG5", "UE DE L'ETUDE DE CAS A LA PROGRAMMATION", 3, 1};
    ecue e11{3, "13GPQUA5", "ECUE qualite de programmation", 12, 6, 6};
    ecue e12{1, "13GPETC5", "ECUE Etudes de cas", 0, 16, 0};
    u1.ajouter_ecue(&e11);
    u1.ajouter_ecue(&e12);
    m.ajouter_ue(&u1);

    UEseule u2{14, 20, 0, "13GUPOO5", "PROGRAMMATION ORIENTEE OBJET", 3, 1};
    m.ajouter_ue(&u2);

    UEseule u3{14, 22, 0, "13GUALGO", "ALGORITHMIQUE", 3, 1};
    m.ajouter_ue(&u3);

    UEseule u4{14, 26, 0, "13GUCSI5", "CONCEPTION DE SYTEMES D'INFORMATION", 3, 1};
    m.ajouter_ue(&u4);

    UEseule u5{18, 10, 0, "13GUINR5", "INTRODUCTION AUX RESEAUX", 3, 1};
    m.ajouter_ue(&u5);

    /* IA et RO ues à choix */
    UEchoix u6{};
    UEseule u61{15, 15, 0, "13GUIAR5", "INTELLIGENCE ARTIFICIELLE", 3, 1};
    UEseule u62{15, 20, 0, "13GUREO5", "RECHERCHE OPERATIONNELLE", 3, 1};
    u6.ajouter_ue(&u61);
    u6.ajouter_ue(&u62);
    m.ajouter_ue(&u6);
    m.position_ue_choix_dans_ue(6);

    UEcomposee u7{"13GUECOG", "ECONOMIE ET GESTION 1", 6, 2};
    ecue e71{2, "13GPECEN", "ECUE Economie d'entreprise", 20, 0, 0};
    ecue e72{1, "13GPCOMP", "ECUE Modele comtpable d'entreprise", 10, 0, 0};
    ecue e73{3, "13GPMICR", "ECUE Micro-Macroeconomie", 26, 10, 0};
    u7.ajouter_ecue(&e71);
    u7.ajouter_ecue(&e72);
    u7.ajouter_ecue(&e73);
    m.ajouter_ue(&u7);

    UEcomposee u8{"13GUTEXT", "TECHNIQUES D'EXPRESSION", 3, 1};
    ecue e81{2, "13GPANCO", "ECUE Anglais computing 1", 0, 20, 0};
    ecue e82{2, "13GPALL5", "ECUE Allemand", 0, 20, 0};
    ecue e83{1, "13GPSTAG", "ECUE Techniques de recherche de stage", 0, 10, 0};
    u8.ajouter_ecue(&e81);
    u8.ajouter_ecue(&e82);
    u8.ajouter_ecue(&e83);
    m.ajouter_ue(&u8);

    afficheur_txt aff{};
    aff.exporter_maquette(m);
}

void test_interface()
{
    interface test{};
    test.initialiser();

}

int main()
{
    //test_afficheur();
    test_interface();
    return 0;
}
