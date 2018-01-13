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
        lecture_json(std::string chemin);
        ~lecture_json();

    private:
        std::ifstream d_fichierLecture;
};

#endif // LECTURE_JSON_H
