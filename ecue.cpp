#include "ecue.h"

ecue::ecue() : d_code{""}, d_intitule{""}, d_cm{0}, d_td{0}, d_tp{0}
{}

ecue::ecue(string code, string intitule, unsigned int cm, unsigned int td, unsigned int tp) :
    d_code{code}, d_intitule{intitule}, d_cm{cm}, d_td{td}, d_tp{tp}
{}

ecue::~ecue()
{}
