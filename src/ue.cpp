#include "ue.h"

ue::ue(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient) :
        d_code{code},
        d_intitule{intitule},
        d_credits{credits},
        d_coefficient{coefficient}
{}

ue::ue(ue &u) :
        d_code{u.code()},
        d_intitule{u.intitule()},
        d_credits{u.credits()},
        d_coefficient{u.coefficient()}
{}

ue::~ue()
{}

/**
    Affecte la valeur au code de l'unite d'enseignement
    @param[in] std::string - code
*/
void ue::code(std::string code)
{
    d_code = code;
}

/**
    Affecte la valeur a l'intitule de l'unite d'enseignement
    @param[in] std::string - intitule
*/
void ue::intitule(std::string intitule)
{
    d_intitule = intitule;
}

/**
    Affecte la valeur aux credits de l'unite d'enseignement
    @param[in] std::string - credit
*/
void ue::credits(unsigned int credits)
{
    d_credits = credits;
}

/**
    Affecte la valeur du coefficient a l'unite d'enseignement
    @param[in] std::string - coefficient
*/
void ue::coefficient(unsigned int coefficient)
{
    d_coefficient = coefficient;
}

/**
    Retourne le code de l'unite d'enseignement
    @param[out] std::string - d_code
*/
std::string ue::code() const
{
    return d_code;
}

/**
    Retourne l'intitule de l'unite d'enseignement
    @param[out] std::string - intitule
*/
std::string ue::intitule() const
{
    return d_intitule;
}

/**
    Retourne le code de l'unite d'enseignement
    @param[out] unsigned int - d_credits
*/
unsigned int ue::credits() const
{
    return d_credits;
}

/**
    Retourne le coefficient de l'unite d'enseignement
    @param[out] std::string - d-coefficient
*/
unsigned int ue::coefficient() const
{
    return d_coefficient;
}

/**
    Surcharge de l'operateur de flux de sortie
    @param[in] std::ostream& - os
    @param[in] const ue& -u
    @param[out] std:ostream& - os
*/
std::ostream& operator<<(std::ostream &os, const ue &u)
{
    u.afficher(os);
    return os;
}
