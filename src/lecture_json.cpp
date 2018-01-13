#include "lecture_json.h"

lecture_json::lecture_json(std::string chemin)
{
    d_fichierLecture.open(chemin);
}

lecture_json::~lecture_json()
{
    d_fichierLecture.close();
}

std::vector<maquette*>& lecture_json::lire_maquette()
{
    std::vector<maquette*> maquettesFichier;
    maquette maquetetCourante;
    std::string mot;
    char caractere;
    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof())
        {

        }
    }
    return maquettesFichier;
}

std::vector<UEseule*>& lecture_json::lire_UEseule()
{
    std::vector<UEseule*> UEseulesFichier;

    return UEseulesFichier;
}

std::vector<UEcomposee*>& lecture_json::lire_UEcomposee()
{
    std::vector<UEcomposee*> UEcomposeesFichier;

    return UEcomposeesFichier;
}

std::vector<ecue*>& lecture_json::lire_ecue()
{
    std::vector<ecue*> ecueFichier;

    return ecueFichier;
}

std::vector<UEchoix*>& lecture_json::lire_UEchoix()
{
    std::vector<UEchoix*> UEchoixFichier;

    return UEchoixFichier;
}

std::vector<formation*>& lecture_json::lire_formation()
{
    std::vector<formation*> formationsFichier;

    return formationsFichier;
}
