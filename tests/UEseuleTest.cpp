#include "catch.hpp"
#include "../src/ue.h"
#include "../src/UEseule.h"

#include <string>
#include <sstream>



void ueSeuleALesBonnesValeurs(const UEseule &ues,unsigned int heures_cm,unsigned int heures_td, unsigned int heures_tp,
                              std::string code, std::string intitule, unsigned int credits, unsigned int coefficient)
{

    REQUIRE(ues.heures_cm()==heures_cm);
    REQUIRE(ues.heures_td()==heures_td);
    REQUIRE(ues.heures_tp()==heures_tp);
    REQUIRE(ues.code()==code);
    REQUIRE(ues.intitule()==intitule);
    REQUIRE(ues.credits()==credits);
    REQUIRE(ues.coefficient()==coefficient);
}


TEST_CASE("L'UE seule est bien cree", "[UEseule]")
{

    unsigned int heures_cm = 3;
    unsigned int heures_td = 2;
    unsigned int heures_tp = 1;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Anglais";

    UEseule ues{heures_cm,heures_td,heures_tp,code,
            intitule,credits, coefficient};
    UEseule ues2{ues};


    SECTION("Les donnees d'Ue seule construite sont correctes")
    {
       ueSeuleALesBonnesValeurs(ues,heures_cm,heures_td,heures_tp,code,intitule,credits,coefficient);
    }
    SECTION("Les donnees d'UE seule construite par recopie sont correctes")
    {
       ueSeuleALesBonnesValeurs(ues2,heures_cm,heures_td,heures_tp,code,intitule,credits,coefficient);
    }

}

TEST_CASE("L'UE seule est bien modifiee")
{

    unsigned int heures_cm = 3;
    unsigned int heures_td = 2;
    unsigned int heures_tp = 1;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Anglais";

    UEseule ues(heures_cm,heures_td,heures_tp,code,intitule,credits,coefficient);

    SECTION(" L'heure des cm modifiee a la bonne valeur")
    {
        ues.heures_cm(4);
        REQUIRE(ues.heures_cm()==4);

    }

    SECTION ("L'heure des td modifiee a la bonne valeur")
    {
        ues.heures_td(5);
        REQUIRE(ues.heures_td()==5);
    }

    SECTION("L'heure des tp modifiee a la bonne valeur")
    {
        ues.heures_tp(6);
        REQUIRE(ues.heures_tp()==6);

    }
    SECTION ("Le total des heures a la bonne valeur")
    {
        unsigned int total = heures_cm + heures_td + heures_tp;
        REQUIRE(ues.duree_totale()==total);
    }
    SECTION("Les credit modifiee ont la bonne valeur")
    {
        ues.credits(2);
        REQUIRE(ues.credits()==2);
    }

    SECTION ("Le coefficient modifie a la bonne valeur")
    {
        ues.coefficient(2);
        REQUIRE(ues.coefficient()==2);
    }

    SECTION ("Le code modifie a la bonne valeur")
    {
        ues.code("13GUPRG6");
        REQUIRE(ues.code()=="13GUPRG6");

    }
    SECTION ("L'UE seule modifee a les bonnes valeurs")
    {
        ues.modifier_completement_ue(1,1,1,"13GUPRG6","Allemand",1,2);
        ueSeuleALesBonnesValeurs(ues,1,1,1,"13GUPRG6","Allemand",1,2);
    }

}

TEST_CASE("L'affichage d'une UE est correct"){

    unsigned int heures_cm = 3;
    unsigned int heures_td = 2;
    unsigned int heures_tp = 1;
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Anglais";

    UEseule ues(heures_cm,heures_td,heures_tp,code,intitule,credits,coefficient);

     std::string formatAttendu = code + "   |   " +
            std::to_string(coefficient) + "   |   " +
            std::to_string(credits) + "   |   " +
            intitule + "   |   " +
            std::to_string(heures_cm) + "   |   " +
            std::to_string(heures_td) + "   |   " +
            std::to_string(heures_tp) + "   |   " +
            std::to_string(heures_cm + heures_td + heures_tp) + "\n";

    std::ostringstream ost{};
    ues.afficher(ost);
    std::string formatLu = ost.str();

    REQUIRE(formatLu == formatAttendu);

}






