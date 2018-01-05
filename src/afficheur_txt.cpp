#include "afficheur_txt.h"

using std::cout;
using std::endl;

afficheur_txt::afficheur_txt()
{}

afficheur_txt::~afficheur_txt()
{}

void afficheur_txt::exporter_maquette(const maquette &m)
{
    d_fichier.open(nom(m));

    std::vector <ue*> ues{m.liste_ues()};
    std::vector <UEchoix*> ues_choix{m.liste_ues_choix()};

    ecrire_details_maquette(m);
    for(unsigned int cpt_ue=0, cpt_ue_choix=0; cpt_ue_choix<ues.size()+1; cpt_ue_choix++)
    {
        if(cpt_ue_choix == m.position_ue_choix_dans_ue())
        {
            //affichage ue_choix
            for(unsigned int i=0; i<ues_choix.size(); i++)
                ecrire_ue_choix(ues_choix[i]);
        }
        else
        {
            //affichage ue_choix
            ecrire_ue(ues[cpt_ue]);
            cpt_ue++;
        }
    }

    d_fichier.close();

}

std::string afficheur_txt::nom(const maquette &m)
{
    std::string nom_fichier;
    nom_fichier += m.mention() + "_";
    nom_fichier += static_cast<std::ostringstream*>( &(std::ostringstream() << m.annee()) )->str() + "_";
    nom_fichier += m.parcours() + "_s";

    nom_fichier += static_cast<std::ostringstream*>( &(std::ostringstream() << m.semestre()) )->str() + ".txt";


    for(unsigned int i=0; i<nom_fichier.length(); i++)
        if(nom_fichier[i] == ' ')
            nom_fichier[i] = '_';

    return nom_fichier;
}

void afficheur_txt::ecrire_details_maquette(const maquette &m)
{
    d_fichier << m.domaine() << std::endl;
    d_fichier << m.mention() << std::endl;
    d_fichier << m.parcours() << std::endl;
    d_fichier << m.annee() << std::endl;
    d_fichier << m.semestre() << std::endl;
}

void afficheur_txt::ecrire_ue(ue *u)
{
    if(dynamic_cast<UEseule*>(u) != nullptr)
    {
        ecrire_ue_seule(dynamic_cast<UEseule*>(u));
    }
    else
    {
        ecrire_ue_composee(dynamic_cast<UEcomposee*>(u));
    }
}

void afficheur_txt::ecrire_ue_choix(const UEchoix *UEc)
{
    std::vector <ue*> liste_ue{UEc->liste_ue()};
    for(unsigned int i=0; i<liste_ue.size(); i++)
        ecrire_ue(liste_ue[i]);
}

void afficheur_txt::ecrire_ue_seule(const UEseule *UEs)
{
    d_fichier   << UEs->code() << ";"
                << UEs->coefficient() << ";"
                << UEs->credits() << ";"
                << UEs->intitule() << ";"
                << UEs->heures_cm() << ";"
                << UEs->heures_td() << ";"
                << UEs->heures_tp() << ";"
                << UEs->duree_totale() << std::endl;
}

void afficheur_txt::ecrire_ue_composee(const UEcomposee *UEc)
{
    d_fichier   << UEc->code() << ";"
                << UEc->coefficient() << ";"
                << UEc->credits() << ";"
                << UEc->intitule() << std::endl;

    std::vector <ecue*> liste_ecue{UEc->liste_ecue()};
    for(unsigned int i=0; i<liste_ecue.size(); i++)
    {
        ecrire_ecue(*liste_ecue[i]);
    }
}

void afficheur_txt::ecrire_ecue(const ecue &ec)
{
    d_fichier   << ec.code() << ";"
                << ec.intitule() << ";"
                << ec.heures_cm() << ";"
                << ec.heures_td() << ";"
                << ec.heures_tp() << ";"
                << ec.duree_totale() << std::endl;
}
