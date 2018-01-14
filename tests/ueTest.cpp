#include "catch.hpp"
#include "../src/ue.h"
#include <string>


void ueALesBonnesValeurs(const ue& u,std::string code, std::string intitule, unsigned int credits, unsigned int coefficient)
{

    REQUIRE(u.code()==code);
    REQUIRE(u.intitule()==intitule);
    REQUIRE(u.credits()==credits);
    REQUIRE(u.coefficient()==coefficient);
}


TEST_CASE("L'UE  est bien cree", "[ue]")
{

    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Allemand";

    ue u(code,intitule,credits, coefficient);
    ue u2(u);


    SECTION("Les donnees lors de la construction d'ue sont correctes")
    {
       ueALesBonnesValeurs(u,code,intitule,credits,coefficient);
    }

    SECTION("Les donnees lors de la construction par recopie d'ue sont correctes")
    {
       ueSeuleALesBonnesValeurs(ues2,code,intitule,credits,coefficient);
    }

}

TEST_CASE("L'UE  est bien modifiee")
{


    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Allemand";

     ue u(heures_cm,heures_td,heures_tp,code,intitule,3,1);

    SECTION("Le code modifie a la bonne valeur")
    {
        u.code("13GURPG6");
        REQUIRE(u.code()=="13GURPG6");

    }

    SECTION ("L'intitule modifie a la bonne valeur")
    {
        u.intitule("Anglais");
        REQUIRE(u.intitule()=="Anglais");
    }

    SECTION("Les credits modifies ont la bonne valeurs ")
    {
        u.credits(2);
        REQUIRE(u.credits()==2);

    }

    SECTION ("Le coefficient modifie a la bonne valeur")
    {
       u.coefficient(2);
       REQUIRE(u.coefficient()==2);
    }

}







