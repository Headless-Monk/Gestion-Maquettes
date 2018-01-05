#include "maquette.h"

maquette::maquette(std::string mention, std::string parcours, unsigned int annee, unsigned int semestre) :
            d_ues{}, d_ues_choix{}, d_position_ue_choix_dans_ue{d_ues.size()},
            d_domaine{"SCIENCE ET TECHNOLOGIE"},
            d_mention{mention},
            d_parcours{parcours},
            d_annee{annee},
            d_semestre{semestre}
{}

maquette::maquette(std::vector <ue*> &ues, std::vector <UEchoix*> &ues_choix,
         std::string mention, std::string parcours, unsigned int annee, unsigned int semestre) :
            d_ues{ues}, d_ues_choix{ues_choix}, d_position_ue_choix_dans_ue{0},
            d_domaine{"SCIENCE ET TECHNOLOGIE"},
            d_mention{mention},
            d_parcours{parcours},
            d_annee{annee},
            d_semestre{semestre}
{}

maquette::maquette(maquette &m) :
            d_ues{m.d_ues}, d_ues_choix{m.d_ues_choix}, d_position_ue_choix_dans_ue{m.d_position_ue_choix_dans_ue},
            d_domaine{"SCIENCE ET TECHNOLOGIE"},
            d_mention{m.d_mention},
            d_parcours{m.d_parcours},
            d_annee{m.d_annee},
            d_semestre{m.d_semestre}
{}

maquette::~maquette()
{}

void maquette::afficher(std::ostream &os) const
{
    os << "Domaine : " << d_domaine << std::endl;
    os << "Mention : " << d_mention << std::endl;
    os << "Parcours : " << d_parcours << std::endl;
    os << "Année : " << d_annee << std::endl;
    os << "Semestre : " << d_semestre << std::endl;

    for(unsigned int cpt_ues=0, cpt_ecues=0; cpt_ecues<d_ues.size() + 1; cpt_ecues++)
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
    }

}

void maquette::ajouter_ue(ue *u)
{
    d_ues.push_back(u);
}

void maquette::ajouter_ue(UEchoix *uc)
{
    d_ues_choix.push_back(uc);
}

void maquette::supprimer_ue(ue *u)
{
    unsigned int i = 0;
    while(u != d_ues[i])
        i++;
    delete d_ues[i];
    for(; i<d_ues.size()-1; i++)
        std::swap(d_ues[i],d_ues[i+1]);
    d_ues.resize(d_ues.size()-1);
}

void maquette::supprimer_ue(UEchoix *uc)
{

}

void maquette::monter_ue(ue *u) //déplace de 1 dans la liste
{

}

void maquette::monter_ue(UEchoix *uc)
{

}

void maquette::descendre_ue(ue *u)
{

}

void maquette::descendre_ue(UEchoix *uc)
{

}


void maquette::domaine(std::string domaine)
{
    d_domaine = domaine;
}

void maquette::mention(std::string mention)
{
    d_mention = mention;
}

void maquette::parcours(std::string parcours)
{
    d_parcours = parcours;
}

void maquette::annee(unsigned int annee)
{
    d_annee = annee;
}

void maquette::semestre(unsigned int semestre)
{
    d_semestre = semestre;
}

std::vector <ue*> maquette::liste_ues() const
{
    return d_ues;
}

std::vector <UEchoix*> maquette::liste_ues_choix() const
{
    return d_ues_choix;
}

unsigned int maquette::position_ue_choix_dans_ue() const
{
    return d_position_ue_choix_dans_ue;
}

std::string maquette::domaine() const
{
    return d_domaine;
}

std::string maquette::mention() const
{
    return d_mention;
}

std::string maquette::parcours() const
{
    return d_parcours;
}

unsigned int maquette::annee() const
{
    return d_annee;
}

unsigned int maquette::semestre() const
{
    return d_semestre;
}

std::ostream& operator<<(std::ostream &os, maquette &m)
{
    m.afficher(os);
    return os;
}
