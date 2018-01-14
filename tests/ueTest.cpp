#include "catch.hpp"
#include "../src/ue.cpp"
#include <string>


void ueALesBonnesValeurs(const ue& u,std::string code, std::string intitule, unsigned int credits, unsigned int coefficient)
{

    REQUIRE(u.code()==code);
    REQUIRE(u.intitule()==intitule);
    REQUIRE(u.credits()==credits);
    REQUIRE(u.coefficient()==coefficient);
}


TEST_CASE("L'UE  est bien cree", "[UEseule]")
{


    unsigned int credits = 3;
    unsigned int coefficient = 1;
    std::string code = "13GUPRG5";
    std::string intitule = "Anglais";

}







