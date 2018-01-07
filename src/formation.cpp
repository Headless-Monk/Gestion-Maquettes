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
    std::cout << "Mention : " << d_mention << std::endl;
    std::cout << "Liste des maquettes :" << std::endl;
    for(unsigned int i = 0; i < d_maquettes.size(); i++)
        std::cout << d_maquettes[i]->domaine() << " | "
                  << d_maquettes[i]->mention() << " | "
                  << d_maquettes[i]->parcours() << std::endl;
}
