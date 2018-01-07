#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "maquette.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"

class afficheur
{
    public:
        afficheur();
        virtual ~afficheur();

        virtual void exporter_maquette(const maquette *m) =0;

    protected:
        virtual std::string nom(const maquette *m) =0;
        virtual void ecrire_details_maquette(const maquette *m) =0;
        virtual void ecrire_ue(ue *u) =0;
        virtual void ecrire_ue_choix(const UEchoix *UEc) =0;
        virtual void ecrire_ue_seule(const UEseule *UEs) =0;
        virtual void ecrire_ue_composee(const UEcomposee *UEc) =0;
        virtual void ecrire_ecue(const ecue *ec) =0;

    private:
};

#endif // AFFICHEUR_H
