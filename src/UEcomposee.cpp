#include "UEcomposee.h"

UEcomposee::UEcomposee(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient) :
            ue{code, intitule, credits, coefficient}, d_ecues{}
{}

UEcomposee::UEcomposee(std::vector <ecue*> &ecues, std::string code, std::string intitule,
           unsigned int credits, unsigned int coefficient) :
            ue{code, intitule, credits, coefficient}, d_ecues{ecues}
{}

UEcomposee::UEcomposee(UEcomposee &UEc) :
            ue{UEc.code(), UEc.intitule(), UEc.credits(), UEc.coefficient()}, d_ecues{UEc.liste_ecue()}
{}

UEcomposee::~UEcomposee()
{}

/**
    Affiche une UE composee
    @param[in] std::ostream& - os
*/
void UEcomposee::afficher(std::ostream &os) const
{
    os <<   code() << "   |   " <<
            coefficient() << "   |   " <<
            credits() << "   |   " <<
            intitule() << "   |   " << std::endl;

    for(unsigned int i=0; i<d_ecues.size(); i++)
    {
        os << *d_ecues[i];
    }
}

/**
    Ajoute un element constitutif d'UE
    @param[in] ecue* - e
*/
void UEcomposee::ajouter_ecue(ecue *e)
{
    d_ecues.push_back(e);
}

/**
    Supprime un element constitutif d'UE
    @param[in] unsigned int - ecue_a_supprimer
*/
void UEcomposee::supprimer_ecue(unsigned int ecue_a_supprimer)
{
    for(; ecue_a_supprimer<d_ecues.size()-1; ecue_a_supprimer++)
        std::swap(d_ecues[ecue_a_supprimer],d_ecues[ecue_a_supprimer+1]);
    d_ecues.resize(d_ecues.size()-1);
}

/**
    Modifie l'entete de l'element constitutif d'UE
    @param[in] std::ostream& - os
    @param[in] std::istream& - is
*/
void UEcomposee::modifier_entete(std::ostream &os, std::istream &is)
{
    std::string nouveau_code, nouveau_intitule;
    unsigned int nouveau_credits, nouveau_coefficient;

    os << "code : ";
    is >> nouveau_code;
    code(nouveau_code);

    os << "intitule : ";
    is >> nouveau_intitule;
    intitule(nouveau_intitule);

    os << "credits : ";
    is >> nouveau_credits;
    credits(nouveau_credits);

    os << "coefficient : ";
    is >> nouveau_coefficient;
    coefficient(nouveau_coefficient);
}

/**
    Monte l'element constitutif d'UE
    @param[in] unsigned int - ecue_a_monter
*/
void UEcomposee::monter_ecue(unsigned int ecue_a_monter)
{
	if (ecue_a_monter > 0)
		std::swap(d_ecues[ecue_a_monter], d_ecues[ecue_a_monter - 1]);
}


/**
    Descend l'element constitutif d'UE
    @param[in] unsigned int - ecue_a_descendre
*/
void UEcomposee::descendre_ecue(unsigned int ecue_a_descendre)
{
	if (ecue_a_descendre < d_ecues.size() - 1)
		std::swap(d_ecues[ecue_a_descendre], d_ecues[ecue_a_descendre + 1]);
}

/**
    Retourne la liste des elements constitutifs d'UE
    @param[out] std::vector<ecue*> - d_ecues
*/
std::vector<ecue*> UEcomposee::liste_ecue() const
{
    return d_ecues;
}

/**
    Surcharge d'operateur de flux de sortie
    @param[in] std::ostream& - os
    @param[in] UEcomposee& - UEc
    @param[out] std::ostream& - os
*/
std::ostream& operator<<(std::ostream &os, UEcomposee &UEc)
{
    UEc.afficher(os);
    return os;
}
