#include "interface.h"

interface::interface():d_maquette{}, d_formation{}, d_UEseule{}, d_UEcomposee{}, d_ecue{}, d_UEchoix{}
{

}

interface::~interface()
{

}

void interface::initialiser()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << std::endl;

        afficher_menu_principal();

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_menu_maquettes();
                break;
            case 2:
                afficher_menu_formations();
                break;
            case 3:
                afficher_menu_UEseuls();
                break;
            case 4:
                afficher_menu_ECUEs();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

void interface::afficher_menu_principal()
{
    std::cout << "1) Gerer les maquettes" << std::endl;
    std::cout << "2) Gerer les formations" << std::endl;
    std::cout << "3) Gerer les UEs" << std::endl;
    std::cout << "4) Gerer les ECUEs" << std::endl;
    std::cout << "5) Gerer les UEs a choix" << std::endl;
    std::cout << "6) Quitter" << std::endl;
}

void interface::afficher_menu_maquettes()
{
    int choix = 0;
    while(choix != 4)
    {
        system("cls");
        std::cout << "1) Creer maquette" << std::endl;
        std::cout << "2) Modifier maquette" << std::endl;
        std::cout << "3) Supprimer maquette" << std::endl;
        std::cout << "4) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_maquette();
                break;
            case 2:
                afficher_modifier_maquette();
                break;
            case 3:
                afficher_supprimer_maquette();
                break;
            case 4:
                break;
            default:
                break;
        }
    }
}

void interface::afficher_menu_formations()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << "1) Creer maquette" << std::endl;
        std::cout << "2) Modifier maquette" << std::endl;
        std::cout << "3) Supprimer maquette" << std::endl;
        std::cout << "4) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_formation();
                break;
            case 2:
                afficher_modifier_formation();
                break;
            case 3:
                afficher_supprimer_formation();
                break;
            case 4:
                afficher_liste_formation();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

void interface::afficher_menu_UEseuls()
{
    int choix = 0;
    while(choix != 4)
    {
        system("cls");
        std::cout << "1) Creer UE seule" << std::endl;
        std::cout << "2) Modifier UE seule" << std::endl;
        std::cout << "3) Supprimer UE seule" << std::endl;
        std::cout << "4) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UEseule();
                break;
            case 2:
                afficher_modifier_UEseule();
                break;
            case 3:
                afficher_supprimer_UEseule();
                break;
            case 4:
                break;
            default:
                break;
        }
    }
}

void interface::afficher_menu_UEcomposees()
{
    int choix = 0;
    while(choix != 4)
    {
        system("cls");
        std::cout << "1) Creer UE composée" << std::endl;
        std::cout << "2) Modifier UE composée" << std::endl;
        std::cout << "3) Supprimer UE composée" << std::endl;
        std::cout << "4) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UEcomposee();
                break;
            case 2:
                afficher_modifier_UEcomposee();
                break;
            case 3:
                afficher_supprimer_UEcomposee();
                break;
            case 4:
                break;
            default:
                break;
        }
    }
}
void interface::afficher_menu_ECUEs()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << "1) Creer ECUE" << std::endl;
        std::cout << "2) Modifier ECUE" << std::endl;
        std::cout << "3) Supprimer ECUE" << std::endl;
        std::cout << "4) Afficher toutes les ECUEs" << std::endl;
        std::cout << "5) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_ECUE();
                break;
            case 2:
                afficher_modifier_ECUE();
                break;
            case 3:
                afficher_supprimer_ECUE();
                break;
            case 4:
                afficher_liste_ECUE();
                break;
            case 5:
                break;
            default:
                break;
        }
    }
}

void interface::afficher_creer_maquette()
{

}

void interface::afficher_modifier_maquette()
{

}

void interface::afficher_supprimer_maquette()
{

}

void interface::afficher_liste_maquette()
{
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        std::cout << " " << i << "  |  ";
        d_maquette[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    system("pause");
}

void interface::afficher_creer_formation()
{
    std::string mention;
    std::cout << "Mention : ";
    std::cin >> mention;
    std::cout << "Selectionnez les maquettes que vous voulez inclure dans la formation : " << std::endl;
    //d_maquette.afficher_liste_maquette();

}

void interface::afficher_modifier_formation()
{

}

void interface::afficher_supprimer_formation()
{

}

void interface::afficher_liste_formation()
{

}

void interface::afficher_creer_UEcomposee()
{
    std::string code, intitule, intituleECUE;
    unsigned int credits, coefficient, nbEcues;

    std::cout<<"Code UEcomposé : ";
    std::cin>>code;

    std::cout<<"Intitule UEcomposé : ";
    std::cin>>intitule;

    std::cout<<"Nombre de credits UEcomposé : ";
    std::cin>>credits;

    std::cout<<"Coefficient UEcomposé : ";
    std::cin>>coefficient;

    std::cout<<"Nombre d'ecue qui feront partie de cette UEcomposé : ";
    std::cin>>nbEcues;
    std::vector<ecue*> liste_des_ecues{};
    for(unsigned int i = 0; i < nbEcues; i++)
    {
        std::cout<<"Intitulé ecue "<<i+1<<" : ";
        std::cin>>intituleECUE;//je suppose riviere clever boy et input que des intitulés qui existent
        int indexECUE = 0;
        while(d_ecue[indexECUE]->intitule() != intituleECUE)
                indexECUE++;
        liste_des_ecues.push_back(d_ecue[indexECUE]);
    }
    d_UEcomposee.push_back(new UEcomposee(liste_des_ecues, code, intitule, credits, coefficient));

}

void interface::afficher_creer_UEseule()
{
    std::string codeUE, intituleUE;
    unsigned int creditsUE, coefficientUE, td, tp, cm;
    std::cout<<"Code UE : ";
    std::cin>>codeUE;

    std::cout<<"Intitule UE : ";
    std::cin>>intituleUE;

    std::cout<<"Nombre de credits UE : ";
    std::cin>>creditsUE;

    std::cout<<"Coefficient UE : ";
    std::cin>>coefficientUE;

    std::cout << "Heures td : ";
    std::cin >> td;

    std::cout << "Heures tp : ";
    std::cin >> tp;

    std::cout << "Heures cm : ";
    std::cin >> cm;
    d_UEseule.push_back(new UEseule(cm, td, tp, codeUE, intituleUE, creditsUE, coefficientUE));
    for(unsigned int i = 0; i < d_UEseule.size(); i++)
    {
        d_UEseule[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    //d_UEseule[0]->afficher(std::cout);
   // std::cout << std::endl;
    std::cout << "UE correctement cree";
    std::cout << std::endl;
    system("pause");

}

void interface::afficher_modifier_UEseule()//il y a du copy pasta : peut etre "afficher_modifier_matiere(vectUE/ECUE)" ?
{
    unsigned int coeff, td, tp, cm, credits;
    std::string code, intitule, intitule_recherche;
    std::cout << "Quelle UE voulez-vous modifier ?" << std::endl;
    std::cin >> intitule_recherche;
    int i = 0;
    while(d_UEseule[i]->intitule() != intitule_recherche)
        i++;

    std::cout << "Code : ";
    std::cin >> code;

    std::cout << "Intitule : ";
    std::cin >> intitule;

    std::cout<<"Nombre de credits UE : ";
    std::cin>>credits;

    std::cout << "Coefficient : ";
    std::cin >> coeff;

    std::cout << "Heures td : ";
    std::cin >> td;

    std::cout << "Heures tp : ";
    std::cin >> tp;

    std::cout << "Heures cm : ";
    std::cin >> cm;
    d_UEseule[i]->modifier_completement_ue(cm, td, tp, code, intitule, credits, coeff);

    std::cout << std::endl;
    d_UEseule[0]->afficher(std::cout);
    std::cout << std::endl;
    std::cout << "UE correctement cree";
    std::cout << std::endl;
    system("pause");
}

void interface::afficher_supprimer_UEseule()
{
    std::string intitule_recherche;
    std::cout << "Quelle UE voulez-vous supprimer ?" << std::endl;
    for(int i = 0; i < d_UEseule.size(); i++)
    {
        d_UEseule[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    std::cin >> intitule_recherche;

    unsigned int i = 0;
    while(d_UEseule[i]->intitule() != intitule_recherche)
        i++;

    delete d_UEseule[i];

    for(; i<d_ecue.size()-1; i++)
        std::swap(d_UEseule[i],d_UEseule[i+1]);
    d_UEseule.resize(d_UEseule.size()-1);
}

void interface::afficher_creer_ECUE()
{
    unsigned int coeff, td, tp, cm;
    std::string code, intitule;

    std::cout << "intitule : ";
    std::cin >> intitule;

    std::cout << "code : ";
    std::cin >> code;

    std::cout << "coefficient : ";
    std::cin >> coeff;

    std::cout << "heures td : ";
    std::cin >> td;

    std::cout << "heures tp : ";
    std::cin >> tp;

    std::cout << "heures cm : ";
    std::cin >> cm;
    std::cout << std::endl;

    d_ecue.push_back(new ecue{coeff,code,intitule,cm,td,tp});

    d_ecue[0]->afficher(std::cout);
    std::cout << std::endl;
    std::cout << "ECUE correctement creee";
    std::cout << std::endl;
    system("pause");
}

void interface::afficher_modifier_ECUE()
{
    unsigned int coeff, td, tp, cm;
    std::string code, intitule, intitule_recherche;
    std::cout << "Quelle ECUE voulez-vous modifier ?" << std::endl;
    std::cin >> intitule_recherche;
    int i = 0;
    while(d_ecue[i]->intitule() != intitule_recherche)
        i++;

    std::cout << "intitule : ";
    std::cin >> intitule;
    d_ecue[i]->intitule(intitule);

    std::cout << "code : ";
    std::cin >> code;
    d_ecue[i]->code(code);

    std::cout << "coefficient : ";
    std::cin >> coeff;
    d_ecue[i]->coefficent(coeff);

    std::cout << "heures td : ";
    std::cin >> td;
    d_ecue[i]->heures_td(td);

    std::cout << "heures tp : ";
    std::cin >> tp;
    d_ecue[i]->heures_tp(tp);

    std::cout << "heures cm : ";
    std::cin >> cm;
    d_ecue[i]->heures_cm(cm);

    std::cout << std::endl;
}

void interface::afficher_supprimer_ECUE()
{
    std::string intitule_recherche;
    std::cout << "Quelle ECUE voulez-vous supprimer ?" << std::endl;
    std::cin >> intitule_recherche;

    unsigned int i = 0;
    while(d_ecue[i]->intitule() != intitule_recherche)
        i++;

    delete d_ecue[i];

    for(; i<d_ecue.size()-1; i++)
        std::swap(d_ecue[i],d_ecue[i+1]);
    d_ecue.resize(d_ecue.size()-1);
}

void interface::afficher_liste_ECUE()
{
    for(unsigned int i=0; i<d_ecue.size(); i++)
    {
        std::cout << " " << i << "  |  ";
        d_ecue[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    system("pause");
}

void interface::afficher_creer_UE_choix()
{

}

void interface::afficher_modifier_UE_choix()
{

}

void interface::afficher_supprimer_UE_choix()
{

}

void interface::afficher_liste_UE_choix()
{

}
