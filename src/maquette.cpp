#include "maquette.h"

maquette::maquette() :
            d_ues{}, d_ues_choix{}, d_position_ue_choix_dans_ue{0},
            d_domaine{"SCIENCE ET TECHNOLOGIE"},
            d_mention{""},
            d_parcours{""},
            d_annee{0},
            d_semestre{0}
{}

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
            d_ues{ues}, d_ues_choix{ues_choix}, d_position_ue_choix_dans_ue{d_ues.size()},
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

/**
    Affiche les donnees de la maquette
    @param[in] std::ostream& - os
*/
void maquette::afficher(std::ostream &os) const
{
    os << "Domaine : " << d_domaine << std::endl;
    os << "Mention : " << d_mention << std::endl;
    os << "Parcours : " << d_parcours << std::endl;
    os << "Annee : " << d_annee << std::endl;
    os << "Semestre : " << d_semestre << std::endl;

    int ajout_ues_choix = d_ues_choix.size()>0 ? 1:0;
    for(unsigned int cpt_ues=0, cpt_ues_choix=0, cpt_affichage=1; cpt_ues_choix<d_ues.size() + ajout_ues_choix; cpt_ues_choix++)
    {
        if(cpt_ues_choix+1 == d_position_ue_choix_dans_ue)
        {
            for(unsigned int i=0; i<d_ues_choix.size(); i++)
            {
                os << " " << cpt_affichage << "  |  " << std::endl;
                cpt_affichage += d_ues_choix[i]->nombre_ue_choix();
                d_ues_choix[i]->afficher(os);
            }
        }
        else if(d_ues.size() > 0)
        {
            os << " " << cpt_affichage << "  |  " << std::endl;
            cpt_affichage++;
            d_ues[cpt_ues]->afficher(os);
            cpt_ues++;
        }
    }
}

/**
    Affiche l'entete de la maquette
    @param[in] std::ostream& - os
*/
void maquette::afficher_entete(std::ostream &os) const
{
    os << "Domaine : " << d_domaine << std::endl;
    os << "Mention : " << d_mention << std::endl;
    os << "Parcours : " << d_parcours << std::endl;
    os << "Annee : " << d_annee << std::endl;
    os << "Semestre : " << d_semestre << std::endl;
}

/**
    Ajouter une UE a la maquette
    @param[in] ue* - u
*/
void maquette::ajouter_ue(ue *u)
{
    d_ues.push_back(u);
}

/**
    Ajouter une UE a choix a la maquette
    @param[in] UEchoix* - uc
*/
void maquette::ajouter_ue(UEchoix *uc)
{
    d_ues_choix.push_back(uc);
}

/**
    Supprimer une UE de la maquette
    @param[in] ue* - u
*/
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

/**
    Supprimer une UE a choix de la maquette
    @param[in] UEchoix* - uc
*/
void maquette::supprimer_ue(UEchoix *uc)
{
    unsigned int i = 0;
    while(uc != d_ues_choix[i])
        i++;
    delete d_ues_choix[i];
    for(; i<d_ues_choix.size()-1; i++)
        std::swap(d_ues_choix[i],d_ues_choix[i+1]);
    d_ues_choix.resize(d_ues_choix.size()-1);
}

/**
    Saisir les donnees d'une maquette
    @param[in] std::ostream& - os
    @param[in] std::istream& - is
*/
void maquette::saisir_maquette(std::ostream &os, std::istream &is)
{
    os << "mention : ";
    is >> d_mention;

    os << "parcours : ";
    is >> d_parcours;

    os << "annee : ";
    is >> d_annee;

    os << "semestre : ";
    is >> d_semestre;
}

/**
    Deplacer l'UE d'une place vers l'avant
    @param[in] ue* - u
*/
void maquette::monter_ue(ue *u) //déplace de 1 dans la liste
{
	unsigned int index = 0;
	while (index < d_ues.size() && d_ues[index] != u)
		index++;
	if (index < d_ues.size() && index > 0)
		std::swap(d_ues[index], d_ues[index - 1]);
}

/**
    Deplacer l'UE a choix d'une place vers l'avant
    @param[in] UEchoix* - uc
*/
void maquette::monter_ue(UEchoix *uc)
{
    if(d_position_ue_choix_dans_ue > 1)
        d_position_ue_choix_dans_ue--;
}

/**
    Deplacer l'UE d'une place vers l'avant
    @param[in] unsigned int - numero_ue
*/
void maquette::monter_ue(unsigned int numero_ue)
{
    numero_ue--;
    if(d_ues.size() == 0)
        monter_ue(d_ues_choix[numero_ue]);
    else if(d_ues_choix.size() == 0)
        monter_ue(d_ues[numero_ue]);
    else
    {
        if( (numero_ue < d_position_ue_choix_dans_ue) || (numero_ue >= (d_position_ue_choix_dans_ue+d_ues_choix.size()-1)) )
            monter_ue(d_ues[numero_ue]);
        else
            monter_ue(d_ues_choix[numero_ue]);
    }
}

/**
    Deplacer l'UE d'une place vers l'arriere
    @param[in] ue* - u
*/
void maquette::descendre_ue(ue *u)
{
	unsigned int index = 0;
	while (index < d_ues.size() && d_ues[index] != u)
		index++;
	if (index < d_ues.size() - 1)
		std::swap(d_ues[index], d_ues[index + 1]);
}

/**
    Deplacer l'UE a choix d'une place vers l'arriere
    @param[in] UEchoix* - uc
*/
void maquette::descendre_ue(UEchoix *uc)
{
   if(d_position_ue_choix_dans_ue < (d_ues.size() + d_ues_choix.size()) )
        d_position_ue_choix_dans_ue++;
}

/**
    Deplacer l'UE a choix d'une place vers l'arriere
    @param[in] unsigned int - numero_ue
*/
void maquette::descendre_ue(unsigned int numero_ue)
{
    numero_ue--;
    if(d_ues.size() == 0)
        descendre_ue(d_ues_choix[numero_ue]);
    else if(d_ues_choix.size() == 0)
        descendre_ue(d_ues[numero_ue]);
    else
    {
        if( (numero_ue < d_position_ue_choix_dans_ue) || (numero_ue >= (d_position_ue_choix_dans_ue+d_ues_choix.size())) )
            descendre_ue(d_ues[numero_ue]);
        else
            descendre_ue(d_ues_choix[numero_ue]);
    }
}

/**
    Modifie le domaine de la maquette
    @param[in] std::string - domaine
*/
void maquette::domaine(std::string domaine)
{
    d_domaine = domaine;
}

/**
    Modifie la mention de la maquette
    @param[in] std::string - mention
*/
void maquette::mention(std::string mention)
{
    d_mention = mention;
}

/**
    Modifie le parcours de la maquette
    @param[in] std::string - parcours
*/
void maquette::parcours(std::string parcours)
{
    d_parcours = parcours;
}

/**
    Modifie l'annee de la maquette
    @param[in] unsigned int - annee
*/
void maquette::annee(unsigned int annee)
{
    d_annee = annee;
}

/**
    Modifie le semestre de la maquette
    @param[in] unsigned int - semestre
*/
void maquette::semestre(unsigned int semestre)
{
    d_semestre = semestre;
}

/**
    Modifie position_ue_choix_dans_ue de la maquette
    @param[in] unsigned int - position
*/
void maquette::position_ue_choix_dans_ue(unsigned int position)
{
    d_position_ue_choix_dans_ue = position;
}

/**
    Renvoie la liste des UEs de la maquette
    @param[out] std::vector <ue*> - d_ues
*/
std::vector <ue*> maquette::liste_ues() const
{
    return d_ues;
}

/**
    Renvoie la liste des UEs a choix de la maquette
    @param[out] std::vector <UEchoix*> - d_ues_choix
*/
std::vector <UEchoix*> maquette::liste_ues_choix() const
{
    return d_ues_choix;
}

/**
    Renvoie position_ue_choix_dans_ue de la maquette
    @param[out] unsigned int - d_position_ue_choix_dans_ue
*/
unsigned int maquette::position_ue_choix_dans_ue() const
{
    return d_position_ue_choix_dans_ue;
}

/**
    Renvoie le domaine de la maquette
    @param[out] std::string - d_domaine
*/
std::string maquette::domaine() const
{
    return d_domaine;
}

/**
    Renvoie la mention de la maquette
    @param[out] std::string - d_mention
*/
std::string maquette::mention() const
{
    return d_mention;
}

/**
    Renvoie le parcours de la maquette
    @param[out] std::string - d_parcours
*/
std::string maquette::parcours() const
{
    return d_parcours;
}

/**
    Renvoie l'annee de la maquette
    @param[out] unsigned int - d_annee
*/
unsigned int maquette::annee() const
{
    return d_annee;
}

/**
    Renvoie le semestre de la maquette
    @param[out] unsigned int - d_semestre
*/
unsigned int maquette::semestre() const
{
    return d_semestre;
}

/**
    Renvoie le nombre d'UEs a choix de la maquette
    @param[out] unsigned int
*/
unsigned int maquette::nombre_ue_choix() const
{
    return d_ues_choix.size();
}

/**
    Renvoie le nombre d'UEs de la maquette
    @param[out] unsigned int
*/
unsigned int maquette::nombre_ue() const
{
    return d_ues.size();
}

/**
    Renvoie le flux de sortie
    @param[in] std::ostream& - os
    @param[in] maquette& - m
    @param[out] std::ostream& - os
*/
std::ostream& operator<<(std::ostream &os, maquette &m)
{
    m.afficher(os);
    return os;
}
