#include "catch.hpp"
#include "../src/UEchoix.h"
#include"../src/UEseule.h"

#include <string>
#include <sstream>
#include <vector>

TEST_CASE("L'UE Choix est bien construite", "[UEchoix]")
{
    std::vector <ue*> liste_ue{};

    std::string code = "13GUWEDY";
    std::string libele = "UE developpement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;

    SECTION("Le constructeur par defaut est correct")
    {
        UEchoix uechoix_defaut{};
        REQUIRE(liste_ue.size() == uechoix_defaut.liste_ue().size());
    }
    SECTION("Le constructeur est correct")
    {
        UEseule *ues = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};
        liste_ue.push_back(ues);
        UEchoix uec{liste_ue};
        REQUIRE(liste_ue.size() == uec.nombre_ue_choix());
        delete ues;
    }
}

TEST_CASE("L'affichage d'une a choix est correct", "[UEchoix]")
{
    std::string code = "13GUPOO5";
    std::string libele = "PROGRAMMATION ORIENTEE OBJET";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 14;
    unsigned int heures_td = 20;
    unsigned int heures_tp = 0;
    UEseule *ues1 = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};

    std::string formatAttendu = code + "   |   " +
            std::to_string(coefficient) + "   |   " +
            std::to_string(credits) + "   |   " +
            libele + "   |   " +
            std::to_string(heures_cm) + "   |   " +
            std::to_string(heures_td) + "   |   " +
            std::to_string(heures_tp) + "   |   " +
            std::to_string(heures_cm + heures_td + heures_tp) + "\n";

    code = "13GUALGO";
    libele = "ALGORITHMIQUE";
    credits = 3;
    coefficient = 1;
    heures_cm = 14;
    heures_td = 22;
    heures_tp = 0;
    UEseule *ues2 = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};

    formatAttendu += code + "   |   " +
            std::to_string(coefficient) + "   |   " +
            std::to_string(credits) + "   |   " +
            libele + "   |   " +
            std::to_string(heures_cm) + "   |   " +
            std::to_string(heures_td) + "   |   " +
            std::to_string(heures_tp) + "   |   " +
            std::to_string(heures_cm + heures_td + heures_tp) + "\n";

    UEchoix *uec = new UEchoix{};
    uec->ajouter_ue(ues1);
    uec->ajouter_ue(ues2);

    std::ostringstream ost{};
    uec->afficher(ost);
    std::string formatLu = ost.str();

    REQUIRE(formatLu == formatAttendu);
}

TEST_CASE("L'ajout d'une UE est correct", "[UEchoix]")
{
    std::vector <ue*> liste_ue{};

    std::string code = "13GUWEDY";
    std::string libele = "UE développement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;

    UEseule ues{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};
    UEchoix uec{};
    uec.ajouter_ue(&ues);
    REQUIRE(uec.nombre_ue_choix() == 1);
}

TEST_CASE("La suppression d'une UE est correct","[UEchoix]")
{
    std::vector <ue*> liste_ue{};

    std::string code = "13GUWEDY";
    std::string libele = "UE developpement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;

    UEseule *ues = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};
    liste_ue.push_back(ues);
    UEchoix uec{liste_ue};

    uec.supprimer_ue(ues);
    REQUIRE(uec.nombre_ue_choix() == 0);
}

TEST_CASE("La modification de la liste des UEs fonctionne","[UEchoix]")
{
    std::string code = "13GUPOO5";
    std::string libele = "PROGRAMMATION ORIENTEE OBJET";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 14;
    unsigned int heures_td = 20;
    unsigned int heures_tp = 0;
    UEseule *ues1 = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};

    code = "13GUALGO";
    libele = "ALGORITHMIQUE";
    credits = 3;
    coefficient = 1;
    heures_cm = 14;
    heures_td = 22;
    heures_tp = 0;
    UEseule *ues2 = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};

    code = "13GUWEDY";
    libele = "UE developpement de sites web dynamiques";
    credits = 3;
    coefficient = 1;
    heures_cm = 4;
    heures_td = 5;
    heures_tp = 6;
    UEseule *ues3 = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};

    std::vector <ue*> liste_ue1{};
    std::vector <ue*> liste_ue2{};

    liste_ue1.push_back(ues1);
    liste_ue1.push_back(ues2);

    liste_ue2.push_back(ues3);

    UEchoix uec{liste_ue1};
    REQUIRE(uec.nombre_ue_choix() == 2);
    uec.modifier_ue(liste_ue2);
    REQUIRE(uec.nombre_ue_choix() == 1);
}
