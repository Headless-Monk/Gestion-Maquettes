#ifndef SAUVEGARDE_JSON_H
#define SAUVEGARDE_JSON_H

#include "maquette.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"
#include "UEchoix.h"

#include <fstream>
#include <vector>
#include <string>

class maquette;
class ue;
class UEseule;
class UEchoix;
class UEcomposee;
class ecue;

class sauvegarde_json
{
    public:
        sauvegarde_json();
        ~sauvegarde_json();

        void initialisation();
        void sauvegarder_maquette(const std::vector <maquette*> &v_m);
        void sauvegarder_UESeule(const std::vector <UEseule*> &v_ueS);
        void sauvegarder_UEComposee(const std::vector <UEcomposee*> &v_ueC);
        void sauvegarder_ECUE(const std::vector <ecue*> &v_ec);
        void sauvegarder_UEChoix(const std::vector <UEchoix*> &v_uech);


    private:
        std::ofstream d_fichier;
};

#endif // SAUVEGARDE_JSON_H
