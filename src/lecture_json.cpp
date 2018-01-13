#include "lecture_json.h"

lecture_json::lecture_json(std::string chemin)
{
    d_fichierLecture.open(chemin);
}

lecture_json::~lecture_json()
{
    d_fichierLecture.close();
}

std::vector<maquette*> lecture_json::lire_maquette()
{
    std::vector<maquette*> maquettesFichier;

    std::vector<ue*> tmpUEComposeeMaquette;
    std::vector<ue*> tmpUESeulesMaquette;
    std::vector<UEchoix*> tmpUEChoixMaquette;

    std::string mot;
    std::string domaine, mention, parcours;
    int annees, semestres;
    std::string typeUE;
    char caractere;
    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof())
        {
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >>  caractere >> domaine;
            d_fichierLecture >> mot >> caractere >> caractere >> mention;
            d_fichierLecture >> mot >> caractere >> caractere >> parcours;
            d_fichierLecture >> mot >> caractere >> caractere >> annees >> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> semestres>> caractere;
            d_fichierLecture >> typeUE;

            while(typeUE != "}")
            {
                //lire les UEs de la maquette
                if(typeUE =="\"UEComposee\":")
                    tmpUEComposeeMaquette = lire_UEcomposee();
                else if(typeUE=="\"UESeule\":")
                    tmpUESeulesMaquette = lire_UEseule();
                else if(typeUE=="\"UEChoix\":")
                    tmpUEChoixMaquette = lire_UEchoix();

                d_fichierLecture >> typeUE;
            }

            //completer la maquette courante
            maquette maquetteCourante{mention, parcours, annees, semestres};
            for(int i = 0; i < tmpUEComposeeMaquette.size(); i++)
                maquetteCourante.ajouter_ue(tmpUEComposeeMaquette[i]);
           for(int i = 0; i < tmpUESeulesMaquette.size(); i++)
                maquetteCourante.ajouter_ue(tmpUESeulesMaquette[i]);
            for(int i = 0; i < tmpUEChoixMaquette.size();i++)
                maquetteCourante.ajouter_ue(tmpUEChoixMaquette[i]);

           //puis l'ajouter au vecteur de maquettes
           maquettesFichier.push_back(&maquetteCourante);

        }
    }
    return maquettesFichier;
}

std::vector<ue*> lecture_json::lire_UEseule()
{
    std::vector<ue*> UEseulesFichier;
    std::string code, intitule;
    unsigned int credits, coefficient, heuresCM, heuresTD, heuresTP, heuresTotales;
    std::string mot;
    char caractere;

    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof())
        {
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >>  caractere >> code;
            d_fichierLecture >> mot >> caractere >> caractere >> intitule;
            d_fichierLecture >> mot >> caractere >> caractere >> credits >> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> coefficient >> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> heuresCM >> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> heuresTD>> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> heuresTP>> caractere;
            d_fichierLecture >> mot >> caractere >> caractere >> heuresTotales;
            d_fichierLecture >> mot;

            UEseule ueCourante{heuresCM, heuresTD, heuresTP, code, intitule, credits, coefficient};
            UEseulesFichier.push_back(&ueCourante);
        }
    }
    return UEseulesFichier;
}

std::vector<ue*> lecture_json::lire_UEcomposee()
{
    std::vector<ue*> UEcomposeesFichier;

    return UEcomposeesFichier;
}

std::vector<ecue*> lecture_json::lire_ecue()
{
    std::vector<ecue*> ecueFichier;

    return ecueFichier;
}

std::vector<UEchoix*> lecture_json::lire_UEchoix()
{
    std::vector<UEchoix*> UEchoixFichier;

    return UEchoixFichier;
}

std::vector<formation*> lecture_json::lire_formation()
{
    std::vector<formation*> formationsFichier;

    return formationsFichier;
}
