#include "catch.hpp"
#include "../src/ecue.h"

#include <string>
#include <sstream>

void valeursEntete(ecue &testecue, unsigned int coefficient, std::string code, std::string intitule, unsigned int heures_cm, unsigned int heures_td, unsigned int heures_tp)
{
    REQUIRE(testecue.coefficient() == coefficient);
    REQUIRE(testecue.code() == code);
    REQUIRE(testecue.intitule() == intitule);
    REQUIRE(testecue.heures_cm() == heures_cm);
    REQUIRE(testecue.heures_td() == heures_td);
    REQUIRE(testecue.heures_tp() == heures_tp);
}

TEST_CASE("Les ECUEs sont bien construites", "[ECUE]")
{
    unsigned int heures_cm = 12;
    unsigned int heures_td = 6;
    unsigned int heures_tp = 6;
    unsigned int coefficient = 3;
    std::string code = "13GPQUA5";
    std::string intitule = "ECUE qualite de programmation";

    ecue ecue0{};
    ecue ecue1(coefficient,code,intitule,
            heures_cm,heures_td, heures_tp);
    ecue ecue2(ecue1);

    SECTION("Le constructeur par defaut est correct")
    {
        valeursEntete(ecue0,0,"","",0,0,0);
    }
    SECTION("Le constructeur est correct")
    {
       valeursEntete(ecue1,coefficient,code,intitule,heures_cm,heures_td,heures_tp);
    }
    SECTION("Le constructeur par recopie est correct")
    {
       valeursEntete(ecue2,coefficient,code,intitule,heures_cm,heures_td,heures_tp);
    }
}

TEST_CASE("L'affichage est correct", "[ECUE]")
{
    unsigned int heures_cm = 12;
    unsigned int heures_td = 6;
    unsigned int heures_tp = 6;
    unsigned int coefficient = 3;
    std::string code = "13GPQUA5";
    std::string intitule = "ECUE qualite de programmation";

    ecue ecue1(coefficient,code,intitule,
            heures_cm,heures_td, heures_tp);

    std::string formatAttendu = code + "   |   " +
            std::to_string(coefficient) + "   |   " +
            intitule + "    |   " +
            std::to_string(heures_cm) + "   |   " +
            std::to_string(heures_td) + "   |   " +
            std::to_string(heures_tp) + "   |   " +
            std::to_string(heures_cm + heures_td + heures_td) + "\n";

    std::ostringstream ost{};
    ecue1.afficher(ost);
    std::string formatLu = ost.str();

    REQUIRE(formatLu == formatAttendu);
}

TEST_CASE("L'heure totale de l'ECUE est correcte", "[ECUE]")
{
    unsigned int heures_cm = 12;
    unsigned int heures_td = 6;
    unsigned int heures_tp = 6;
    unsigned int coefficient = 3;
    std::string code = "13GPQUA5";
    std::string intitule = "ECUE qualite de programmation";

    ecue ecue1(coefficient,code,intitule,
            heures_cm,heures_td, heures_tp);

    REQUIRE(ecue1.duree_totale() == heures_cm + heures_td + heures_tp);
}

TEST_CASE("Les ECUEs sont bien modifiés", "[ECUE]")
{
    unsigned int heures_cm = 12;
    unsigned int heures_td = 6;
    unsigned int heures_tp = 6;
    unsigned int coefficient = 3;
    std::string code = "13GPQUA5";
    std::string intitule = "ECUE qualite de programmation";

    ecue ecue1(coefficient,code,intitule,
            heures_cm,heures_td, heures_tp);

    SECTION("Le coefficient est bien modifé")
    {
        ecue1.coefficent(5);
        REQUIRE(ecue1.coefficient() == 5);
    }
    SECTION("Le code est bien modifé")
    {
        ecue1.code("12GPQUA7");
        REQUIRE(ecue1.code() == "12GPQUA7");
    }
    SECTION("L'intitule est bien modifé")
    {
        ecue1.intitule("Qualite de programmation");
        REQUIRE(ecue1.intitule() == "Qualite de programmation");
    }
    SECTION("Le nombre d'heures des CM est bien modifé")
    {
        ecue1.heures_cm(10);
        REQUIRE(ecue1.heures_cm() == 10);
    }
    SECTION("Le nombre d'heures des TD est bien modifé")
    {
        ecue1.heures_td(7);
        REQUIRE(ecue1.heures_td() == 7);
    }
    SECTION("Le nombre d'heures des TP est bien modifé")
    {
        ecue1.heures_tp(7);
        REQUIRE(ecue1.heures_tp() == 7);
    }
}
