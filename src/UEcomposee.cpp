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
        os << d_ecues[i];
    }
}

void UEcomposee::ajouter_ecue(ecue *e)
{
    d_ecues.push_back(e);
}

void UEcomposee::supprimer_ecue(ecue *e)
{
    for(unsigned int i=0; i<d_ecues.size(); i++)
    {
        if(d_ecues[i] == e)
        {
            for(unsigned int j=i; j<d_ecues.size(); j++)
            {
                d_ecues[j] = d_ecues[j+1];
            }
            d_ecues.resize(d_ecues.size());
        }
    }
}

void UEcomposee::monter_ecue(ecue *ec)
{

}

void UEcomposee::descendre_ecue(ecue *ec)
{

}

std::vector<ecue*> UEcomposee::liste_ecue() const
{
    return d_ecues;
}

std::ostream& operator<<(std::ostream &os, UEcomposee &UEc)
{
    UEc.afficher(os);
    return os;
}
