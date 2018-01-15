#include "formation.h"

formation::formation(std::string mention) :
            d_maquettes{}, d_mention{mention}
{}

formation::formation(std::vector <maquette*> &maquettes, std::string mention) :
            d_maquettes{maquettes}, d_mention{mention}
{}

formation::formation(formation &f) :
            d_maquettes{f.d_maquettes}, d_mention{f.d_mention}
{}

formation::~formation()
{}

/**
    Affiche les donnees de la formation
    @param[in] std::ostream& - os
*/
void formation::afficher(std::ostream &os)const
{
    os << "Mention : " << d_mention << std::endl;
    os << "Liste des maquettes :" << std::endl;
    for(unsigned int i = 0; i < d_maquettes.size(); i++)
        os << d_maquettes[i]->domaine() << " | "
                  << d_maquettes[i]->mention() << " | "
                  << d_maquettes[i]->parcours() << std::endl;
}

/**
    Modifie la liste des maquettes de la formation
    @param[in] std::vector<maquette*> - maq
*/
void formation::modifier_maquette(std::vector<maquette*> maq)
{
    d_maquettes.resize(maq.size());
    for(unsigned int i = 0; i < maq.size(); i++)
        d_maquettes[i] = maq[i];
}

/**
    Renvoie la mention de la formation
    @param[out] std::string - d_mention
*/
std::string formation::mention() const
{
    return d_mention;
}

/**
    Renvoie le nombre de maquettes de la formation
    @param[out] unsigned int
*/
unsigned int formation::nombre_maquettes() const
{
    return d_maquettes.size();
}

/**
    Renvoie le flux de sortie
    @param[in] std::ostream& - os
    @param[in] formation& - f
    @param[out] std::ostream& - os
*/
std::ostream& operator<<(std::ostream &os, formation &f)
{
    f.afficher(os);
    return os;
}
