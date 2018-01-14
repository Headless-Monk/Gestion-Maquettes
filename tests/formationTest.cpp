#include "catch.hpp"
#include "../src/formation.h"
#include "../src/maquette.h"

#include <iostream>
#include <vector>

void initialisationFormation(formation &f, std::vector <maquette*> &liste_maquette, std::string mention)
{
    REQUIRE(f.mention() == mention);
    REQUIRE(f.nombre_maquettes() == liste_maquette.size());
}

TEST_CASE("Les formations sont bien construites", "[formation]")
{
    std::vector <maquette*> liste_maquette{};
    std::string mention = "Licence Informatique";

    SECTION("Le constructeur sans maquette est correct")
    {
        formation formation_sans_maquette{mention};
        initialisationFormation(formation_sans_maquette, liste_maquette, mention);
    }

    SECTION("Le constructeur avec maquette est correct")
    {
        liste_maquette.push_back(new maquette{});

        formation formation_avec_maquette{liste_maquette, mention};
        initialisationFormation(formation_avec_maquette, liste_maquette, mention);
    }

    SECTION("Le constructeur par recopie est correct")
    {
        liste_maquette.push_back(new maquette{});
        formation formation_base{liste_maquette, mention};

        formation formation_copie{liste_maquette, mention};

        initialisationFormation(formation_copie, liste_maquette, mention);
    }
}
