#include "catch.hpp"
#include "../src/maquette.h"
#include "../src/UEseule.h"
#include "../src/UEchoix.h"

#include <string>
#include <vector>

void initiaisationMaquette(maquette &m, const std::vector <ue*> &liste_ue, const std::vector <UEchoix*> &liste_ue_choix, std::string domaine, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre)
{
    REQUIRE(m.nombre_ue() == liste_ue.size());
    REQUIRE(m.nombre_ue_choix() == liste_ue_choix.size());
    REQUIRE(m.position_ue_choix_dans_ue() == liste_ue.size());
    REQUIRE(m.domaine() == domaine);
    REQUIRE(m.mention() == mention);
    REQUIRE(m.parcours() == parcours);
    REQUIRE(m.annee() == annee);
    REQUIRE(m.semestre() == semestre);
}

TEST_CASE("Les maquettes sont bien construites", "[maquette]")
{
    std::vector <ue*> liste_ue{};
    std::vector <UEchoix*> liste_ue_choix{};

    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    SECTION("Le constructeur par défaut est correct")
    {
        maquette maquette_defaut{};
        initiaisationMaquette(maquette_defaut, liste_ue, liste_ue_choix, domaine, "", "", 0, 0);
    }

    SECTION("Le constructeur sans ue est correct")
    {
        maquette maquette_sans_ue{mention, parcours, annee, semestre};
        initiaisationMaquette(maquette_sans_ue, liste_ue, liste_ue_choix, domaine, mention, parcours, annee, semestre);
    }

    SECTION("Le constructeur avec ue est correct")
    {
        liste_ue.push_back(new UEseule{1, 2, 3, "13GUWEDY", "UE développement de sites web dynamiques", 3, 1});
        liste_ue_choix.push_back(new UEchoix{});
        maquette maquette_avec_ue{liste_ue, liste_ue_choix, mention, parcours, annee, semestre};

        initiaisationMaquette(maquette_avec_ue, liste_ue, liste_ue_choix, domaine, mention, parcours, annee, semestre);

        for(unsigned int i=0; i<liste_ue.size(); i++)
            delete liste_ue[i];

        for(unsigned int i=0; i<liste_ue_choix.size(); i++)
            delete liste_ue_choix[i];
    }

    SECTION("Le constructeur par recopie est correct")
    {
        maquette maquette_base{};
        maquette maquette_recopie{maquette_base};

        initiaisationMaquette(maquette_recopie, maquette_base.liste_ues(), maquette_base.liste_ues_choix(), maquette_base.domaine(), maquette_base.mention(), maquette_base.parcours(), maquette_base.annee(), maquette_base.semestre());
    }
}
