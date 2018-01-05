#include "afficheur_txt.h"

afficheur_txt::afficheur_txt()
{}

afficheur_txt::~afficheur_txt()
{}

void afficheur_txt::exporter_maquette(const maquette &m)
{
    d_fichier.open(nom(m));

    ecrire_details_maquette(m);
    /*for(unsigned int cpt_ues=0, cpt_ecues=0; cpt_ecues<d_ues.size() + 1; cpt_ecues++)
    {
        if(cpt_ecues+1 == d_position_ue_choix_dans_ue)
        {
            for(unsigned int i=0; i<d_ues_choix.size(); i++)
                d_ues_choix[i]->afficher(os);
        }
        else
        {
            d_ues[cpt_ues]->afficher(os);
            cpt_ues++;
        }
    }*/

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

void afficheur_txt::ecrire_UEseule(const UEseule &UEs)
{

}

void afficheur_txt::ecrire_UEcomposee(const UEcomposee &UEc)
{

}

void afficheur_txt::ecrire_ecue(const ecue &ec)
{

}
