#ifndef LECTURE_JSON_H
#define LECTURE_JSON_H

#include "maquette.h"
#include "ue.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "ecue.h"
#include "UEchoix.h"
#include "formation.h"

#include <fstream>
#include <vector>
#include <string>

class lecture_json
{
    public:
        lecture_json() = delete;
        lecture_json(std::string chemin);
        ~lecture_json();

        std::vector<maquette*> lire_maquette();
        std::vector<UEseule*> lire_UEseule();
        std::vector<UEcomposee*> lire_UEcomposee();
        std::vector<ecue*> lire_ecue();
        std::vector<UEchoix*> lire_UEchoix();
        std::vector<formation*> lire_formation();

        std::string recupere_titre();

    private:
        std::ifstream d_fichierLecture;
};

#endif // LECTURE_JSON_H
