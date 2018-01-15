#include "catch.hpp"
#include "../src/ue.h"
#include "../src/UEcomposee.h"
#include <sstream>


#include <string>



void ueComposeeALesBonnesValeurs(const UEcomposee &uec,const std::vector<ecue*> &ecues,
                              std::string code, std::string intitule, unsigned int credits, unsigned int coefficient)
{

    REQUIRE(uec.liste_ecue()==ecues);
    REQUIRE(uec.code()==code);
    REQUIRE(uec.intitule()==intitule);
    REQUIRE(uec.credits()==credits);
    REQUIRE(uec.coefficient()==coefficient);
}


TEST_CASE("L'UE composée est bien cree", "[UEcomposee]")
{
    std::vector<ecue*> ecues;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "UE DE L'ETUDE DE CAS A LA PROGRAMMATION";

    ecues.push_back(new ecue{3, "13GPQUA5", "ECUE qualite de programmation", 12, 6, 6});
    ecues.push_back(new ecue{1, "13GPETC5", "ECUE Etudes de cas", 0, 16, 0});

    UEcomposee uec(ecues,code, intitule,credits, coefficient);
    UEcomposee uec2(code, intitule,credits, coefficient);
    UEcomposee ueRecopie{uec};

    SECTION("Les donnees d'Ue composée construite avec le premier constructeur sont correctes")
    {
       ueComposeeALesBonnesValeurs(uec,ecues,code,intitule,credits,coefficient);
    }

    SECTION("Les donnees d'Ue composée construite avec le deuxième constructeur sont correctes")
    {
        REQUIRE(uec.code()==code);
        REQUIRE(uec.intitule()==intitule);
        REQUIRE(uec.credits()==credits);
        REQUIRE(uec.coefficient()==coefficient);
    }

    SECTION("Les donnees d'UE composée construite par recopie sont correctes")
    {
       ueComposeeALesBonnesValeurs(ueRecopie,ecues,code,intitule,credits,coefficient);
    }

}

TEST_CASE("L'UE composée est bien modifiée")
{
    std::vector<ecue*> ecues;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "UE DE L'ETUDE DE CAS A LA PROGRAMMATION";

    ecues.push_back(new ecue{3, "13GPQUA5", "ECUE qualite de programmation", 12, 6, 6});
    ecue ecueAmonter{1, "13GPETC5", "ECUE Etudes de cas", 0, 16, 0};
    ecues.push_back(&ecueAmonter);

    UEcomposee uec(ecues,code, intitule,credits, coefficient);

    SECTION(" L'ecue est bien montée")
    {
        uec.monter_ecue(1);
        std::vector<ecue*> tmpecue = uec.liste_ecue();
        REQUIRE(tmpecue[0]->coefficient() == ecueAmonter.coefficient());
        REQUIRE(tmpecue[0]->code() == ecueAmonter.code());
        REQUIRE(tmpecue[0]->intitule() == ecueAmonter.intitule());
        REQUIRE(tmpecue[0]->heures_cm() == ecueAmonter.heures_cm());
        REQUIRE(tmpecue[0]->heures_td() == ecueAmonter.heures_td());
        REQUIRE(tmpecue[0]->heures_tp() == ecueAmonter.heures_tp());
    }

    SECTION ("L'ecue est bien descendue")
    {
        uec.descendre_ecue(0);
        std::vector<ecue*> tmpecue = uec.liste_ecue();
        REQUIRE(tmpecue[0]->coefficient() == ecueAmonter.coefficient());
        REQUIRE(tmpecue[0]->code() == ecueAmonter.code());
        REQUIRE(tmpecue[0]->intitule() == ecueAmonter.intitule());
        REQUIRE(tmpecue[0]->heures_cm() == ecueAmonter.heures_cm());
        REQUIRE(tmpecue[0]->heures_td() == ecueAmonter.heures_td());
        REQUIRE(tmpecue[0]->heures_tp() == ecueAmonter.heures_tp());
    }

    SECTION("L'ecue est bien supprimée")
    {
        uec.supprimer_ecue(1);
        std::vector<ecue*> tmpecue = uec.liste_ecue();
        REQUIRE(tmpecue.size() == 1);

    }
    SECTION ("L'ecue est bien ajoutée")
    {
        ecue ecueAajouter{1, "13GGPIA5", "ECUE Intelligence Artificielle", 0, 16, 8};
        uec.ajouter_ecue(&ecueAajouter);
        std::vector<ecue*> tmpecue = uec.liste_ecue();
        REQUIRE(tmpecue.size() == 3);
    }
}

TEST_CASE("Entrées sorties")
{
    std::vector<ecue*> ecues;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "UE DE L'ETUDE DE CAS A LA PROGRAMMATION";

    std::string nouveau_code = "13GGPIA5";
    std::string nouvel_intitule = "UE Intelligence Artificielle";
    std::string nouveaux_credits = "1";
    std::string nouveau_coefficient = "2";

    UEcomposee uec(ecues,code, intitule,credits, coefficient);

    SECTION("L'affichage est correct")
    {
        std::string formatAttendu = uec.code() + "   |   " +
                               std::to_string(uec.coefficient()) + "   |   " +
                               std::to_string(uec.credits()) + "   |   " +
                               uec.intitule() + "   |   \n";
        std::ostringstream ost{};
        uec.afficher(ost);
        std::string formatLu = ost.str();
        REQUIRE(formatLu == formatAttendu);
    }

    SECTION("La lecture est correcte")
    {
        std::ostringstream ost{};
        std::string formatLu = nouveau_code + " "
                             + nouvel_intitule + " "
                             + nouveaux_credits + " "
                             + nouveau_coefficient;

        std::istringstream ist{formatLu};
        uec.modifier_entete(ost, ist);
        /*
        REQUIRE(uec.code() == nouveau_code);
        REQUIRE(uec.intitule() == nouvel_intitule);
        REQUIRE(std::to_string(uec.credits()) == nouveaux_credits);
        REQUIRE(std::to_string(uec.coefficient()) == nouveau_coefficient);
        */
    }
}
