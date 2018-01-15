#include "ecue.h"

ecue::ecue():d_coefficient{0}, d_code{""}, d_intitule{""}, d_heures_cm{0}, d_heures_td{0}, d_heures_tp{0}
{}

ecue::ecue(unsigned int coeff, std::string code, std::string intitule, unsigned int cm, unsigned int td, unsigned int tp):
    d_coefficient{coeff}, d_code{code}, d_intitule{intitule}, d_heures_cm{cm}, d_heures_td{td}, d_heures_tp{tp}
{}

ecue::ecue(ecue &e) :
    d_coefficient{e.d_coefficient}, d_code{e.d_code}, d_intitule{e.d_intitule}, d_heures_cm{e.d_heures_cm}, d_heures_td{e.d_heures_td}, d_heures_tp{e.d_heures_tp}
{}

ecue::~ecue()
{}

/**
    Affiche les donnee de l'ECUE
    @param[in] std::ostream& - os
*/
void ecue::afficher(std::ostream &os) const
{
    os <<   d_code << "   |   " <<
            d_coefficient << "   |   " <<
            d_intitule << "    |   " <<
            d_heures_cm << "   |   " <<
            d_heures_td << "   |   " <<
            d_heures_tp << "   |   " <<
            duree_totale() << std::endl;
}

/**
    Renvoie le nombre totale d'heures de l'ECUE
    @param[out] unsigned int
*/
unsigned int ecue::duree_totale() const
{
    return d_heures_cm + d_heures_td + d_heures_tp;
}

/**
    Modifie le coefficient de l'ECUE
    @param[in] unsigned int - coeff
*/
void ecue::coefficent(unsigned int coeff)
{
    d_coefficient = coeff;
}

/**
    Modifie le code de l'ECUE
    @param[in] std::string - code
*/
void ecue::code(std::string code)
{
    d_code = code;
}

/**
    Modifie l'intitule de l'ECUE
    @param[in] std::string - intitule
*/
void ecue::intitule(std::string intitule)
{
    d_intitule = intitule;
}

/**
    Modifie le nombre d'heures de CM de l'ECUE
    @param[in] unsigned int - cm
*/
void ecue::heures_cm(unsigned int cm)
{
    d_heures_cm = cm;
}

/**
    Modifie le nombre d'heures de TD de l'ECUE
    @param[in] unsigned int - td
*/
void ecue::heures_td(unsigned int td)
{
    d_heures_td = td;
}

/**
    Modifie le nombre d'heures de TP de l'ECUE
    @param[in] unsigned int - tp
*/
void ecue::heures_tp(unsigned int tp)
{
    d_heures_tp = tp;
}

/**
    Renvoie le coefficient de l'ECUE
    @param[out] unsigned int - d_coefficient
*/
unsigned int ecue::coefficient() const
{
    return d_coefficient;
}

/**
    Renvoie le code de l'ECUE
    @param[out] std::string - d_code
*/
std::string ecue::code() const
{
    return d_code;
}

/**
    Renvoie l'intitule de l'ECUE
    @param[out] std::string - d_intitule
*/
std::string ecue::intitule() const
{
    return d_intitule;
}

/**
    Renvoie le nombre d'heures de CM de l'ECUE
    @param[out] unsigned int - cm
*/
unsigned int ecue::heures_cm() const
{
    return d_heures_cm;
}

/**
    Renvoie le nombre d'heures de TD de l'ECUE
    @param[out] unsigned int - td
*/
unsigned int ecue::heures_td() const
{
    return d_heures_td;
}

/**
    Renvoie le nombre d'heures de TP de l'ECUE
    @param[out] unsigned int - tp
*/
unsigned int ecue::heures_tp() const
{
    return d_heures_tp;
}

/**
    Renvoie le flux de sortie
    @param[in] std::ostream& - os
    @param[in] ecue& - e
    @param[out] std::ostream& - os
*/
std::ostream& operator<<(std::ostream &os, const ecue &e)
{
    e.afficher(os);
    return os;
}
