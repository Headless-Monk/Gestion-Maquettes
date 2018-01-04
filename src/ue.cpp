#include "ue.h"

void ue::code(std::string code)
{
    d_code = code;
}
void ue::intitule(std::string intitule)
{
    d_intitule = intitule;
}
void ue::credits(unsigned int credits)
{
    d_credits = credits;
}
void ue::coefficient(unsigned int coefficient)
{
    d_coefficient = coefficient;
}


std::string ue::code() const
{
    return d_code;
}
std::string ue::intitule() const
{
    return d_intitule;
}
unsigned int ue::credits() const
{
    return d_credits;
}
unsigned int ue::coefficient() const
{
    return d_coefficient;
}

ue::ue(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient) :
        UEchoix{},
        d_code{code},
        d_intitule{intitule},
        d_credits{credits},
        d_coefficient{coefficient}
{}

ue::ue(ue &u) :
        UEchoix{},
        d_code{u.code()},
        d_intitule{u.intitule()},
        d_credits{u.credits()},
        d_coefficient{u.coefficient()}
{}

ue::~ue()
{}

std::ostream& operator<<(std::ostream &os, const ue &u)
{
    u.afficher(os);
    return os;
}
