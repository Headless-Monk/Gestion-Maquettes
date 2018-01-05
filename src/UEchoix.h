#ifndef UECHOIX_H
#define UECHOIX_H

#include <vector>
#include <ostream>

//utiliser soit un soit l'autre, bug sans les deux
#include "ue.h"
class ue;

class UEchoix
{
    public:
        UEchoix();
        UEchoix(std::vector <ue*> &ues);
        ~UEchoix();

        void afficher(std::ostream &os) const;
        void ajouter_ue(ue *u);
        void supprimer_ue(ue *u);

        std::vector<ue*> liste_ue() const;
    protected:


    private:
        std::vector <ue*> d_liste_ue;
};

#endif // UECHOIX_H
