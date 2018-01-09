#include "sauvegarde_json.h"

sauvegarde_json::sauvegarde_json()
{
    initialisation();
}

sauvegarde_json::~sauvegarde_json()
{
    d_fichier.close();
}

void sauvegarde_json::initialisation()
{
    d_fichier.open("save.json");
}

void sauvegarde_json::sauvegarder_maquette(const std::vector <maquette *> &v_m)
{
    for(int i = 0; i < v_m.size(); i++)
        v_m[i]->sauvegarde_Json(d_fichier);
}

void sauvegarde_json::sauvegarder_UESeule(const std::vector <UEseule*> &v_ueS)
{
    for(int i = 0; i < v_ueS.size(); i++)
        v_ueS[i]->sauvegarde_Json(d_fichier);
}

void sauvegarde_json::sauvegarder_UEComposee(const std::vector <UEcomposee*> &v_ueC)
{
    for(int i = 0; i < v_ueC.size(); i++)
        v_ueC[i]->sauvegarde_Json(d_fichier);
}

void sauvegarde_json::sauvegarder_ECUE(const std::vector <ecue*> &v_ec)
{
    for(int i = 0; i < v_ec.size(); i++)
        v_ec[i]->sauvegarde_Json(d_fichier);
}

void sauvegarde_json::sauvegarder_UEChoix(const std::vector <UEchoix*> &v_uech)
{
    for(int i = 0; i < v_uech.size(); i++)
        v_uech[i]->sauvegarde_Json(d_fichier);
}
