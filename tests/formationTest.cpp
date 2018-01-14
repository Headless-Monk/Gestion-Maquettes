#include "catch.hpp"
#include "../src/formation.h"
#include "../src/maquette.h"

#include <vector>
#include <sstream>
#include <string>

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



TEST_CASE("Afficher la liste des formations", "[formation]")
{
    std::vector <maquette*> liste_maquette{};
    std::string mention = "Licence Informatique";

    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    std::string formatLu = "";
    std::string formatAttendu = "";

    formatAttendu += "Mention : " + mention + "\n";
    formatAttendu += "Liste des maquettes :\n";

    SECTION("Affichage d'une formation sans maquette")
    {
        formation formation_sans_maquette{mention};

        std::ostringstream ost{};
        ost << formation_sans_maquette;
        formatLu = ost.str();

        REQUIRE(formatLu == formatAttendu);
    }

    SECTION("Affichage d'une formation avec maquette")
    {
        liste_maquette.push_back(new maquette{mention, parcours, annee, semestre});
        formation formation_sans_maquette{liste_maquette, mention};

        formatAttendu += domaine + " | " + mention + " | " + parcours + "\n";

        std::ostringstream ost{};
        ost << formation_sans_maquette;
        formatLu = ost.str();

        REQUIRE(formatLu == formatAttendu);
    }

}

















