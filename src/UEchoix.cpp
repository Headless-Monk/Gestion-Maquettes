#include "UEchoix.h"

UEchoix::UEchoix()
{}

UEchoix::~UEchoix()
{}

std::ostream& operator<<(std::ostream &os, const UEchoix &u)
{
    u.afficher(os);
    return os;
}
