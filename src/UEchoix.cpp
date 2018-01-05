#include "UEchoix.h"

UEchoix::UEchoix() : d_liste_ue{}
{}

UEchoix::UEchoix(std::vector <ue*> &ues) : d_liste_ue{ues}
{}

UEchoix::~UEchoix()
{}

void UEchoix::afficher(std::ostream &os) const
{
    for(unsigned int i=0; i<d_liste_ue.size(); i++)
        d_liste_ue[i]->afficher(os);
}

void UEchoix::ajouter_ue(ue *u)
{
    d_liste_ue.push_back(u);
}

void UEchoix::supprimer_ue(ue *u)
{
    unsigned int i = 0;
    while(u != d_liste_ue[i])
        i++;
    delete d_liste_ue[i];
    for(; i<d_liste_ue.size()-1; i++)
        std::swap(d_liste_ue[i],d_liste_ue[i+1]);
    d_liste_ue.resize(d_liste_ue.size());
}
