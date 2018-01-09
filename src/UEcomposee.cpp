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

void UEcomposee::ajouter_ecue(ecue *e)
{
    d_ecues.push_back(e);
}

void UEcomposee::supprimer_ecue(unsigned int ecue_a_supprimer)
{
    for(; ecue_a_supprimer<d_ecues.size()-1; ecue_a_supprimer++)
        std::swap(d_ecues[ecue_a_supprimer],d_ecues[ecue_a_supprimer+1]);
    d_ecues.resize(d_ecues.size()-1);
}

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

void UEcomposee::monter_ecue(unsigned int ecue_a_monter)
{
	if (ecue_a_monter > 0)
		std::swap(d_ecues[ecue_a_monter], d_ecues[ecue_a_monter - 1]);
}

void UEcomposee::descendre_ecue(unsigned int ecue_a_descendre)
{
	if (ecue_a_descendre < d_ecues.size() - 1)
		std::swap(d_ecues[ecue_a_descendre], d_ecues[ecue_a_descendre + 1]);
}

std::vector<ecue*> UEcomposee::liste_ecue() const
{
    return d_ecues;
}

void UEcomposee::sauvegarde_Json(std::ofstream &os)
{

}

std::ostream& operator<<(std::ostream &os, UEcomposee &UEc)
{
    UEc.afficher(os);
    return os;
}
