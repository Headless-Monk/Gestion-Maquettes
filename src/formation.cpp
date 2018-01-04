#include "formation.h"

formation::formation(std::string mention) :
            d_maquettes{}, d_mention{mention}
{}
/*
formation::formation(std::vector <maquette> &maquettes, std::string mention) :
            d_maquettes{maquettes}, d_mention{mention}
{}

formation::formation(formation &f) :
            d_maquettes{f.d_maquettes}, d_mention{f.d_mention}
{}
*/
formation::~formation()
{}

