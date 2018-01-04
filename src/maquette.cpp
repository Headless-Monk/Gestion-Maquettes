#include "maquette.h"

maquette::maquette(std::string mention, std::string parcours, unsigned int annee, unsigned int semestre) :
{}

maquette::maquette(std::vector <ue*> &ues, std::vector <UEchoix*> &ues_choix,
         std::string mention, std::string parcours, unsigned int annee, unsigned int semestre) :
{}

maquette::maquette(maquette &m)
{}

maquette::~maquette()
{}

void maquette::afficher(std::ostream &os) const
{

}

void maquette::ajouter_ue(ue *u)
{

}

void maquette::ajouter_ue(UEchoix *uc)
{

}

void maquette::supprimer_ue(ue *u)
{

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

}

void maquette::mention(std::string mention)
{

}

void maquette::parcours(std::string parcours)
{

}

void maquette::annee(unsigned int annee)
{

}

void maquette::semestre(unsigned int semestre)
{

}


std::string maquette::domaine() const
{

}

std::string maquette::mention() const
{

}

std::string maquette::parcours() const
{

}

unsigned int maquette::annee() const
{

}

unsigned int maquette::smestre() const
{

}

std::ostream& operator<<(std::ostream &os, maquette &m)
{

}
