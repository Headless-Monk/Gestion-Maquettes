#include "catch.hpp"
#include "../src/maquette.h"
#include "../src/UEseule.h"
#include "../src/UEchoix.h"

#include <string>
#include <vector>
#include <sstream>

void valeursEntete(maquette &m, std::string domaine, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre)
{
    REQUIRE(m.domaine() == domaine);
    REQUIRE(m.mention() == mention);
    REQUIRE(m.parcours() == parcours);
    REQUIRE(m.annee() == annee);
    REQUIRE(m.semestre() == semestre);
}

void initiaisationMaquette(maquette &m, const std::vector <ue*> &liste_ue, const std::vector <UEchoix*> &liste_ue_choix, std::string domaine, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre)
{
    REQUIRE(m.nombre_ue() == liste_ue.size());
    REQUIRE(m.nombre_ue_choix() == liste_ue_choix.size());
    REQUIRE(m.position_ue_choix_dans_ue() == liste_ue.size());

    valeursEntete(m, domaine, mention, parcours, annee, semestre);
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

    SECTION("Le constructeur sans unité d'enseignement est correct")
    {
        maquette maquette_sans_ue{mention, parcours, annee, semestre};
        initiaisationMaquette(maquette_sans_ue, liste_ue, liste_ue_choix, domaine, mention, parcours, annee, semestre);
    }

    SECTION("Le constructeur avec unité d'enseignement est correct")
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



TEST_CASE("Affichage global", "[maquette]")
{
    std::vector <ue*> liste_ue{};
    std::vector <UEchoix*> liste_ue_choix{};

    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    std::string code = "13GUWEDY";
    std::string libele = "UE développement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;
    unsigned int heures_totales = heures_cm + heures_td + heures_tp;

    std::string formatAttendu = "";
    formatAttendu += "Domaine : " + domaine + "\n";
    formatAttendu += "Mention : " + mention + "\n";
    formatAttendu += "Parcours : " + parcours + "\n";
    formatAttendu += "Annee : " + std::to_string(annee) + "\n";
    formatAttendu += "Semestre : " + std::to_string(semestre) + "\n";

    std::string formatLu = "";

    SECTION("Une maquette sans unité d'enseignement s'affiche correctement")
    {
        maquette maquette_sans_ue{mention, parcours, annee, semestre};

        std::ostringstream ost{};
        ost << maquette_sans_ue;
        formatLu = ost.str();

        REQUIRE(formatLu == formatAttendu);
    }

    SECTION("Une maquette avec ue s'affiche correctement")
    {
        formatAttendu   += code + "   |   " + std::to_string(coefficient) + "   |   " + std::to_string(credits) + "   |   " + libele + "   |   "
                        + std::to_string(heures_cm) + "   |   " + std::to_string(heures_td) + "   |   " + std::to_string(heures_tp) + "   |   " + std::to_string(heures_totales) + "\n";

        liste_ue.push_back(new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient});
        maquette maquette_avec_ue{liste_ue, liste_ue_choix, mention, parcours, annee, semestre};
        maquette_avec_ue.ajouter_ue(liste_ue[0]);

        std::ostringstream ost{};
        ost << maquette_avec_ue;
        formatLu = ost.str();

        REQUIRE(formatLu == formatAttendu);

        for(unsigned int i=0; i<liste_ue.size(); i++)
            delete liste_ue[i];

    }

    SECTION("Une maquette avec UEchoix s'affiche correctement")
    {

    }

    SECTION("Une maquette avec deux types d'unités d'enseignement s'affiche correctement")
    {

    }
}



TEST_CASE("Affichage de l'entête", "[maquette]")
{
    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    std::string formatAttendu = "";
    formatAttendu += "Domaine : " + domaine + "\n";
    formatAttendu += "Mention : " + mention + "\n";
    formatAttendu += "Parcours : " + parcours + "\n";
    formatAttendu += "Annee : " + std::to_string(annee) + "\n";
    formatAttendu += "Semestre : " + std::to_string(semestre) + "\n";

    std::string formatLu = "";

    SECTION("Une maquette sans unité d'enseignement s'affiche correctement")
    {
        maquette m{mention, parcours, annee, semestre};

        std::ostringstream ost{};
        m.afficher_entete(ost);
        formatLu = ost.str();

        REQUIRE(formatLu == formatAttendu);
    }
}


TEST_CASE("Ajout d'une unité d'enseignement", "[maquette]")
{
    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;


    std::string code = "13GUWEDY";
    std::string libele = "UE développement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;
    unsigned int heures_totales = heures_cm + heures_td + heures_tp;

    maquette maquette_sans_ue{mention, parcours, annee, semestre};

    UEseule* UEs = new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient};
    UEchoix* UEc = new UEchoix{};

    SECTION("Ajout d'une ue")
    {
        REQUIRE(maquette_sans_ue.nombre_ue() == 0);
        maquette_sans_ue.ajouter_ue(UEs);
        REQUIRE(maquette_sans_ue.nombre_ue() == 1);
    }

    SECTION("Ajout d'une UEchoix")
    {
        REQUIRE(maquette_sans_ue.nombre_ue_choix() == 0);
        maquette_sans_ue.ajouter_ue(UEc);
        REQUIRE(maquette_sans_ue.nombre_ue_choix() == 1);
    }

    delete UEs;
    delete UEc;
}



TEST_CASE("Suppression d'une unité d'enseignement", "[maquette]")
{
    std::vector <ue*> liste_ue{};
    std::vector <UEchoix*> liste_ue_choix{};

    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;


    std::string code = "13GUWEDY";
    std::string libele = "UE développement de sites web dynamiques";
    unsigned int credits = 3;
    unsigned int coefficient = 1;
    unsigned int heures_cm = 4;
    unsigned int heures_td = 5;
    unsigned int heures_tp = 6;
    unsigned int heures_totales = heures_cm + heures_td + heures_tp;

    liste_ue.push_back(new UEseule{heures_cm, heures_td, heures_tp, code, libele, credits, coefficient});
    liste_ue_choix.push_back(new UEchoix{});

    maquette maquette_avec_ue{liste_ue, liste_ue_choix, mention, parcours, annee, semestre};

    SECTION("Suppression d'une ue")
    {
        REQUIRE(maquette_avec_ue.nombre_ue() == 1);
        maquette_avec_ue.supprimer_ue(liste_ue[0]);
        REQUIRE(maquette_avec_ue.nombre_ue() == 0);
    }

    SECTION("Suppression d'une UEchoix")
    {
        REQUIRE(maquette_avec_ue.nombre_ue_choix() == 1);
        maquette_avec_ue.supprimer_ue(liste_ue_choix[0]);
        REQUIRE(maquette_avec_ue.nombre_ue_choix() == 0);
    }
}



TEST_CASE("Modification de l'entête d'une unité d'enseignement", "[maquette]")
{
    std::string domaine = "SCIENCE ET TECHNOLOGIE";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    SECTION("Saisie de l'entête")
    {
        maquette maquette_defaut{};

        std::string formatLu = mention + "\n" + parcours + "\n" + std::to_string(annee) + "\n" + std::to_string(semestre) + "\n";
        std::istringstream ist{formatLu};
        std::ostringstream ost{};

        maquette_defaut.saisir_maquette(ost, ist);

        //valeursEntete(maquette_defaut, domaine, mention, parcours, annee, semestre);
    }
}



TEST_CASE("Mutateurs", "[maquette]")
{
    std::string domaine = "SCIENCEs ET TECHNOLOGIEs";
    std::string mention = "Licence Informatique";
    std::string parcours = "MIAGE";
    unsigned int annee = 3;
    unsigned int semestre = 6;

    maquette m{};

    SECTION("Mutateurs")
    {
        m.domaine(domaine);
        m.mention(mention);
        m.parcours(parcours);
        m.annee(annee);
        m.semestre(semestre);

        valeursEntete(m, domaine, mention, parcours, annee, semestre);
    }

}






















