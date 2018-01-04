#include "ecue.h"

ecue::ecue(std::string code, std::string intitule, unsigned int cm, unsigned int td, unsigned int tp):
    d_code{code}, d_intitule{intitule}, d_heures_cm{cm}, d_heures_td{td}, d_heures_tp{tp}
{}

ecue::ecue(ecue &e) :
    d_code{e.d_code}, d_intitule{e.d_intitule}, d_heures_cm{e.d_heures_cm}, d_heures_td{e.d_heures_td}, d_heures_tp{e.d_heures_tp}
{}

void ecue::afficher(std::ostream &os) const
{
    os <<   d_code << "   |   " <<
            d_intitule << "    |   " <<
            d_heures_cm << "   |   " <<
            d_heures_td << "   |   " <<
            d_heures_tp << "   |   " <<
            duree_totale() << std::endl;
}

unsigned int ecue::duree_totale() const
{
    return d_heures_cm + d_heures_td + d_heures_tp;
}

void ecue::code(std::string code)
{
    d_code = code;
}

void ecue::intitule(std::string intitule)
{
    d_intitule = intitule;
}

void ecue::heures_cm(unsigned int cm)
{
    d_heures_cm = cm;
}

void ecue::heures_td(unsigned int td)
{
    d_heures_td = td;
}

void ecue::heures_tp(unsigned int tp)
{
    d_heures_tp = tp;
}

std::string ecue::code() const
{
    return d_code;
}

std::string ecue::intitule() const
{
    return d_intitule;
}

unsigned int ecue::heures_cm() const
{
    return d_heures_cm;
}

unsigned int ecue::heures_td() const
{
    return d_heures_td;
}

unsigned int ecue::heures_tp() const
{
    return d_heures_tp;
}

std::ostream& operator<<(std::ostream &os, const ecue &e)
{
    e.afficher(os);
    return os;
}
