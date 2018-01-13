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
    for(unsigned int i = 0; i < v_m.size()-1; i++)
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
    for(unsigned int i = 0; i < v_ueS.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_ueS[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_ueS[v_ueS.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_UEComposee(const std::vector <UEcomposee*> &v_ueC)
{
    for(unsigned int i = 0; i < v_ueC.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_ueC[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_ueC[v_ueC.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;

}

void sauvegarde_json::sauvegarder_ECUE(const std::vector <ecue*> &v_ec)
{
    for(unsigned int i = 0; i < v_ec.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_ec[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_ec[v_ec.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_UEChoix(const std::vector <UEchoix*> &v_uech)
{
    for(unsigned int i = 0; i < v_uech.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_uech[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_uech[v_uech.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::sauvegarder_Formation(const std::vector <formation*> &v_form)
{
    for(unsigned int i = 0; i < v_form.size()-1; i++)
    {
        d_fichier << "{" << std::endl;
        v_form[i]->sauvegarde_json(d_fichier);
        d_fichier << "}," << std::endl;
    }

    d_fichier << "{" << std::endl;
    v_form[v_form.size()-1]->sauvegarde_json(d_fichier);
    d_fichier << "}" << std::endl;
}

void sauvegarde_json::recuperer_maquette(std::vector <maquette*> &v_m)
{

}

void sauvegarde_json::recuperer_UESeule(std::vector <UEseule*> &v_ueS)
{

}

void sauvegarde_json::recuperer_UEComposee(std::vector <UEcomposee*> &v_ueC)
{

}

void sauvegarde_json::recuperer_ECUE(std::vector <ecue*> &v_ec)
{

}

void sauvegarde_json::recuperer_UEChoix(std::vector <UEchoix*> &v_uech)
{

}

void sauvegarde_json::recuperer_Formation(std::vector <formation*> &v_form)
{

}
