#include "UEchoix.h"

UEchoix::UEchoix() : d_liste_ue{}
{}

UEchoix::UEchoix(std::vector <ue*> &ues) : d_liste_ue{ues}
{}

UEchoix::~UEchoix()
{}

/**
    Affiche une unite d'enseignement choix
    @param[in] std::ostream& - os
*/
void UEchoix::afficher(std::ostream &os) const
{
    for(unsigned int i=0; i<d_liste_ue.size(); i++)
        d_liste_ue[i]->afficher(os);
}

/**
    Ajouter une unite d'enseignement à l'unite d'enseignement choix
    @param[in] ue* - u
*/
void UEchoix::ajouter_ue(ue *u)
{
    d_liste_ue.push_back(u);
}

/**
    Supprime une unnite d'enseignement a choix
    @param[in] ue* - u
*/
void UEchoix::supprimer_ue(ue *u)
{
    unsigned int i = 0;
    while(u != d_liste_ue[i])
        i++;
    delete d_liste_ue[i];
    for(; i<d_liste_ue.size()-1; i++)
        std::swap(d_liste_ue[i],d_liste_ue[i+1]);
    d_liste_ue.resize(d_liste_ue.size()-1);
}

/**
    Retourne la liste des unites d'enseignement de l'unite d'enseignement a choix
    @param[out] std::vector<ue*> - d_liste_ue
*/
std::vector<ue*> UEchoix::liste_ue() const
{
    return d_liste_ue;
}

/**
    Modifie une unites d'enseignement de l'unite
    @param[in] std::vector <ue*> - ue
*/
void UEchoix::modifier_ue(std::vector <ue*> ue)
{
    d_liste_ue.clear();
    d_liste_ue.resize(ue.size());
    for(unsigned int i = 0; i < ue.size(); i++)
        d_liste_ue[i] = ue[i];
}

/**
    Retourne le nombre d'unite d'enseignement pour l'unite d'enseignement choix
    @param[out] unsigned int - taille de d_liste_ue
*/
unsigned int UEchoix::nombre_ue_choix() const
{
    return d_liste_ue.size();
}
