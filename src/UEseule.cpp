#include "UEseule.h"

UEseule::UEseule(unsigned int cm, unsigned int td, unsigned int tp,
                 std::string code, std::string intitule,
                 unsigned int credits, unsigned int coefficient) :
                    ue{code, intitule, credits, coefficient},
                    d_heures_cm{cm}, d_heures_td{td}, d_heures_tp{tp}
{}

UEseule::UEseule(UEseule &u) :
                    ue{u.code(), u.intitule(), u.credits(), u.coefficient()},
                    d_heures_cm{u.d_heures_cm}, d_heures_td{u.d_heures_td}, d_heures_tp{u.d_heures_tp}
{}

UEseule:: ~UEseule()
{}

void UEseule::afficher(std::ostream &os) const
{
    os <<   code() << "   |   " <<
            coefficient() << "   |   " <<
            credits() << "   |   " <<
            intitule() << "   |   " <<
            d_heures_cm << "   |   " <<
            d_heures_td << "   |   " <<
            d_heures_tp << "   |   " <<
            duree_totale() << std::endl;
}

unsigned int UEseule::duree_totale() const
{
    return d_heures_cm + d_heures_td + d_heures_tp;
}

void UEseule::heures_cm(unsigned int cm)
{
    d_heures_cm = cm;
}
void UEseule::heures_td(unsigned int td)
{
    d_heures_td = td;
}
void UEseule::heures_tp(unsigned int tp)
{
    d_heures_tp = tp;
}

void UEseule::modifier_completement_ue(unsigned int cm, unsigned int td, unsigned int tp, std::string codeUE, std::string intituleUE, unsigned int credit, unsigned int coeff)
{
    d_heures_cm = cm;
    d_heures_td = td;
    d_heures_tp = tp;
    code(codeUE);
    intitule(intituleUE);
    credits(credit);
    coefficient(coeff);

}

unsigned int UEseule::heures_cm() const
{
    return d_heures_cm;
}
unsigned int UEseule::heures_td() const
{
    return d_heures_td;
}
unsigned int UEseule::heures_tp() const
{
    return d_heures_tp;
}

std::ostream& operator<<(std::ostream &os, const UEseule &UEs)
{
    UEs.afficher(os);
    return os;
}

