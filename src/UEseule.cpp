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

/**
    Affiche une UE seule
    @param[in] std::ostream& - os
*/

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

/**
    Calcul le total d'heures pour l'unite d'enseignement seule
    @param[out] unsigned int -
*/
unsigned int UEseule::duree_totale() const
{
    return d_heures_cm + d_heures_td + d_heures_tp;
}

/**
    Affecte l'heure des cm à l'unite d'enseignement seule
    @param[in] unsigned int - cm
*/
void UEseule::heures_cm(unsigned int cm)
{
    d_heures_cm = cm;
}

/**
    Affecte l'heure des td à l'unite d'enseignement seule
    @param[in] unsigned int - td
*/
void UEseule::heures_td(unsigned int td)
{
    d_heures_td = td;
}

/**
    Affecte l'heure des tp à l'unite d'enseignement seule
    @param[in] unsigned int - tp
*/
void UEseule::heures_tp(unsigned int tp)
{
    d_heures_tp = tp;
}

/**
    Modifie tout les attrributs de l'unite d'enseignement seule
    @param[in] unsigned int - cm
    @param[in] unsigned int - td
    @param[in] unsigned int - tp
    @param[in] std::string - codeUE
    @param[in] std:string - intituleUE
    @param[in] unsigned int - credit
    @param[in] unsigned int - coeff
*/
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

/**
    Retourne l'heure des cm de l'unite d'enseignement seule
    @param[out] unsigned int - d_heures_cm
*/
unsigned int UEseule::heures_cm() const
{
    return d_heures_cm;
}

/**
    Retourne l'heure des td de l'unite d'enseignement seule
    @param[out] unsigned int - d_heures_td
*/
unsigned int UEseule::heures_td() const
{
    return d_heures_td;
}

/**
    Retourne l'heure des tp de l'unite d'enseignement seule
    @param[out] unsigned int - d_heures_tp
*/
unsigned int UEseule::heures_tp() const
{
    return d_heures_tp;
}

/**
    Surcharge de l'operateur de flux de sortie d'une unite d'enseignement libre
    @param[in] std::ostsream& - os
    @param[in] const UEseule& - UEs
    @param[out] std::ostream& - os
*/
std::ostream& operator<<(std::ostream &os, const UEseule &UEs)
{
    UEs.afficher(os);
    return os;
}

