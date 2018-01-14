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

void formation::afficher(std::ostream &os)const
{
    os << "Mention : " << d_mention << std::endl;
    os << "Liste des maquettes :" << std::endl;
    for(unsigned int i = 0; i < d_maquettes.size(); i++)
        os << d_maquettes[i]->domaine() << " | "
                  << d_maquettes[i]->mention() << " | "
                  << d_maquettes[i]->parcours() << std::endl;
}

void formation::modifier_maquette(std::vector<maquette*> maq)
{
    d_maquettes.resize(maq.size());
    for(unsigned int i = 0; i < maq.size(); i++)
        d_maquettes[i] = maq[i];
}

void formation::sauvegarde_json(std::ofstream &os)
{
    os << "\"Mention\" : \" " << d_mention << " \" ," << std::endl;
    os << "{" << std::endl;
    os << "\"Maquettes\" :" << std::endl;
    os << "[" << std::endl;

    for(unsigned int i = 0; i < d_maquettes.size()-1; i++)
    {
        os << "{" << std::endl;
        d_maquettes[i]->sauvegarde_json(os);
        os << "}," << std::endl;
    }

    os << "{" << std::endl;
    d_maquettes[d_maquettes.size()-1]->sauvegarde_json(os);
    os << "}" << std::endl;

    os << "]" << std::endl;
    os << "}" << std::endl;
}

std::string formation::mention() const
{
    return d_mention;
}

unsigned int formation::nombre_maquettes() const
{
    return d_maquettes.size();
}

std::ostream& operator<<(std::ostream &os, formation &f)
{
    f.afficher(os);
    return os;
}
