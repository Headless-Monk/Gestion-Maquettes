#include "sauvegarde_json.h"

sauvegarde_json::sauvegarde_json(std::string &str)
{
    d_fichier.open(str);
}

sauvegarde_json::~sauvegarde_json()
{
    d_fichier.close();
}

void sauvegarde_json::sauvegarder_maquette(const std::vector <maquette *> &v_m)
{
    int i;
    for(i = 0; i < v_m.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_m[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_m[v_m.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_UESeule(const std::vector <UEseule*> &v_ueS)
{

    d_fichier << "{" << std::endl;
    d_fichier << "\"UESeule\" :" << std::endl;
    d_fichier << "[" << std::endl;

    for(int i = 0; i < v_ueS.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_ueS[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_ueS[v_ueS.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}," << std::endl;

    d_fichier << "]" << std::endl;
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_UEComposee(const std::vector <UEcomposee*> &v_ueC)
{
    for(int i = 0; i < v_ueC.size()-1; i++)
    {
        v_ueC[i]->entete_json(d_fichier);
        d_fichier << "[" << std::endl;
        v_ueC[i]->sauvegarde_json(d_fichier);
        d_fichier << "]," << std::endl;
    }
    v_ueC[v_ueC.size()-1]->entete_json(d_fichier);
    d_fichier << "[" << std::endl;
    v_ueC[v_ueC.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "]" << std::endl;

}

void sauvegarde_json::sauvegarder_ECUE(const std::vector <ecue*> &v_ec)
{
    d_fichier << "{" << std::endl;
    d_fichier << "\"ECUE\" :" << std::endl;
    d_fichier << "[" << std::endl;

    for(int i = 0; i < v_ec.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_ec[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_ec[v_ec.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;

    d_fichier << "]" << std::endl;
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_UEChoix(const std::vector <UEchoix*> &v_uech)
{
    for(int i = 0; i < v_uech.size()-1; i++)
    {
        v_uech[i]->entete_json(d_fichier);
        d_fichier << "[" << std::endl;
        v_uech[i]->sauvegarde_json(d_fichier);
        d_fichier << "]," << std::endl;
    }

    v_uech[v_uech.size()-1]->entete_json(d_fichier);
    d_fichier << "[" << std::endl;
    v_uech[v_uech.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "]" << std::endl;
}

void sauvegarde_json::sauvegarder_Formation(const std::vector <formation*> &v_form)
{
    d_fichier << "{" << std::endl;
    d_fichier << "\"Formation\" :" << std::endl;
    d_fichier << "[" << std::endl;

    for(int i = 0; i < v_form.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_form[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_form[v_form.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;

    d_fichier << "]" << std::endl;
    d_fichier << "}" << std::endl;
}
