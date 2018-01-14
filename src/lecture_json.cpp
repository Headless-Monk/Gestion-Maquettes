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

    std::vector<UEcomposee*> tmpUEComposeeMaquette;
    std::vector<UEseule*> tmpUESeulesMaquette;
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
            d_fichierLecture >> mot >> caractere;
            domaine = recupere_titre();
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere;
            mention = recupere_titre();
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> parcours >> caractere;
            d_fichierLecture >> mot >> caractere >> annees >> caractere;
            d_fichierLecture >> mot >> caractere >> semestres>> caractere;
            d_fichierLecture >> typeUE >> caractere;

            while(typeUE != "}")
            {
                //lire les UEs de la maquette
                if(typeUE =="\"UEComposee\"")
                    tmpUEComposeeMaquette = lire_UEcomposee();
                else if(typeUE=="\"UESeule\"")
                    tmpUESeulesMaquette = lire_UEseule();
                else if(typeUE=="\"UEChoix\"")
                    tmpUEChoixMaquette = lire_UEchoix();

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

                d_fichierLecture >> typeUE;
            }
        }
    }
    return maquettesFichier;
}

std::vector<UEseule*> lecture_json::lire_UEseule()
{
    std::vector<UEseule*> UEseulesFichier;
    std::string code, intitule;
    unsigned int credits, coefficient, heuresCM, heuresTD, heuresTP, heuresTotales;
    std::string mot;
    char caractere;

    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof() && mot != "]")
        {
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> code >> caractere;
            d_fichierLecture >> mot >> caractere;
            intitule = recupere_titre();
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> credits >> caractere;
            d_fichierLecture >> mot >> caractere >> coefficient >> caractere;
            d_fichierLecture >> mot >> caractere >> heuresCM >> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTD>> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTP>> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTotales;
            d_fichierLecture >> mot;

            UEseule ueCourante{heuresCM, heuresTD, heuresTP, code, intitule, credits, coefficient};
            UEseulesFichier.push_back(&ueCourante);
        }
    }
    return UEseulesFichier;
}

std::vector<UEcomposee*> lecture_json::lire_UEcomposee()
{
    std::vector<UEcomposee*> UEcomposeesFichier;
    std::string code, intitule;
    unsigned int credits, coefficient;
    std::string mot;
    char caractere;
    std::string ECUE;
    std::vector<ecue*> tmpECUE;


    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof() && mot != "]")
        {
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> code >> caractere;
            d_fichierLecture >> mot >> caractere;
            intitule = recupere_titre();
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> credits >> caractere;
            d_fichierLecture >> mot >> caractere >> coefficient >> caractere;
            d_fichierLecture >> ECUE >> caractere;

            tmpECUE = lire_ecue();

            UEcomposee ueComposeeCourante{code, intitule, credits, coefficient};
            for(int i = 0; i < tmpECUE.size(); i++)
                ueComposeeCourante.ajouter_ecue(tmpECUE[i]);

            UEcomposeesFichier.push_back(&ueComposeeCourante);

            d_fichierLecture >> mot;
        }
    }
    return UEcomposeesFichier;
}

std::vector<ecue*> lecture_json::lire_ecue()
{
    std::vector<ecue*> ecueFichier;

    std::string code, intitule;
    unsigned int coefficient, heuresCM, heuresTD, heuresTP, heuresTotales;
    std::string mot;
    char caractere;

    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof() && mot != "]")
        {
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> code >>  caractere;
            d_fichierLecture >> mot >> caractere;
            intitule = recupere_titre();
            d_fichierLecture >> caractere;
            d_fichierLecture >> mot >> caractere >> coefficient >> caractere;
            d_fichierLecture >> mot >> caractere >> heuresCM >> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTD>> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTP>> caractere;
            d_fichierLecture >> mot >> caractere >> heuresTotales;
            d_fichierLecture >> mot;

            ecue ecueCourante{coefficient, code, intitule, heuresCM, heuresTD, heuresTP};

            ecueFichier.push_back(&ecueCourante);
        }
    }

    return ecueFichier;
}

std::vector<UEchoix*> lecture_json::lire_UEchoix()
{
    std::vector<UEchoix*> UEchoixFichier;
    std::string code, intitule;
    unsigned int credits, coefficient, heuresCM, heuresTD, heuresTP, heuresTotales;
    std::string mot;
    char caractere;
    std::vector<ue*> tmpUE;
    std::vector<ecue*> tmpECUE;


    if(d_fichierLecture.is_open())
    {
        while(!d_fichierLecture.eof())
    {
            while(mot != "]")
            {
                d_fichierLecture >> mot;
                if(mot == "\"UESeule\"")
                {
                    d_fichierLecture >> caractere;
                    d_fichierLecture >> mot >> caractere >> code >> caractere;
                    d_fichierLecture >> mot >> caractere;
                    intitule = recupere_titre();
                    d_fichierLecture >> caractere;
                    d_fichierLecture >> mot >> caractere >> credits >> caractere;
                    d_fichierLecture >> mot >> caractere >> coefficient >> caractere;;
                    d_fichierLecture >> mot >> caractere >> heuresCM >> caractere;
                    d_fichierLecture >> mot >> caractere >> heuresTD>> caractere;
                    d_fichierLecture >> mot >> caractere >> heuresTP>> caractere;
                    d_fichierLecture >> mot >> caractere >> heuresTotales;
                    d_fichierLecture >> mot;

                    UEseule UEseuleCourante{heuresCM, heuresTD, heuresTP, code, intitule, credits, coefficient};
                    tmpUE.push_back(&UEseuleCourante);
                }
                else
                    if(mot == "\"UEComposee\":")
                {
                    d_fichierLecture >> caractere;
                    d_fichierLecture >> mot >> caractere >> code >> caractere;
                    d_fichierLecture >> mot >> caractere;
                    intitule = recupere_titre();
                    d_fichierLecture >> caractere;
                    d_fichierLecture >> mot >> caractere >> credits >> caractere;
                    d_fichierLecture >> mot >> caractere >> coefficient >> caractere;
                    d_fichierLecture >> mot >> caractere;

                    tmpECUE = lire_ecue();

                    UEcomposee ueComposeeCourante{code, intitule, credits, coefficient};
                    for(int i = 0; i < tmpECUE.size(); i++)
                        ueComposeeCourante.ajouter_ecue(tmpECUE[i]);

                    tmpUE.push_back(&ueComposeeCourante);
                }
            }
            d_fichierLecture >> mot;
            UEchoix UEChoixCourante{tmpUE};
            UEchoixFichier.push_back(&UEChoixCourante);
        }
    }
    return UEchoixFichier;
}

std::vector<formation*> lecture_json::lire_formation()
{
    std::vector<formation*> formationsFichier;

    return formationsFichier;
}

std::string lecture_json::recupere_titre()
{
    std::string mot, titre;
    d_fichierLecture >> mot >> titre >> mot;
    while(mot != "\"")
    {
        titre += " " + mot;
        d_fichierLecture >> mot;
    }
    return titre;
}
