#include "catch.hpp"
#include "../src/UEseule.cpp"
#include <string>
#include <vector>


void UESeuleALesBonnesValeurs(const UEseule& ues){

        REQUIRE(ues.heures_cm(),heures_cm);
        REQUIRE(ues.heures_td(),heures_td);
        REQUIRE(ues.heures_tp(),heures_tp);
        REQUIRE(ues.code(),code);
        REQUIRE(ues.intitule(),intitule);
        REQUIRE(ues.credits(),credits);
        REQUIRE(ues.coefficient(),coefficient);
}

TEST_CASE("L'UE seule est bien cree", "[UEseule]")
{

    int heures_cm = 3;
    int heures _td = 2;
    int heures_tp = 1;
    int credits = 3;
    int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Anglais";

    UEseule ues(heures_cm,heures_td,heures_tp,code,
            intitule,credits, coefficient);
    UEseule ues2(ues);


    SECTION("Les donnees d'Ue seule construite sont correctes")
    {
       UESeuleALesBonnesValeurs(ues);
    }
    SECTION("Les donnees d'UE seule construite par recopie sont correctes")
    {
       UESeuleALesBonnesValeurs(ues2);
    }

}

TEST_CASE("L'UE seule est bien modifiee")
{
    SECTION(" L'heure des cm modifiee a la bonne valeur")
    {

    }

    SECTION ("L'heure des td modifiee a la bonne valeur")
    {

    }

    SECTION("L'heure des tp modifiee a la bonne valeur")
    {

    }

    SECTION ("L'UE seule modifé a les bonnes valeurs")

}






