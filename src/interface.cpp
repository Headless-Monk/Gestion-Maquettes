#include "interface.h"

interface::interface():d_maquette{}, d_formation{}, d_ue{}, d_ecue{}, d_UEchoix{}
{

}

interface::~interface()
{

}

void interface::initialiser()
{
    int choix = 0;
    while(choix != 6)
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
                afficher_menu_UEs();
                break;
            case 4:
                afficher_menu_ECUEs();
                break;
            case 5:
                afficher_menu_UEchoix();
                break;
            case 6:
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
        std::cout << "1) Creer formation" << std::endl;
        std::cout << "2) Modifier formation" << std::endl;
        std::cout << "3) Supprimer formation" << std::endl;
        std::cout << "4) Afficher toutes les formation" << std::endl;
        std::cout << "5) Retour" << std::endl;

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

void interface::afficher_menu_UEs()
{
    int choix = 0;
    while(choix != 4)
    {
        system("cls");
        std::cout << "1) Creer UE" << std::endl;
        std::cout << "2) Modifier UE" << std::endl;
        std::cout << "3) Supprimer UE" << std::endl;
        std::cout << "4) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UE();
                break;
            case 2:
                afficher_modifier_UE();
                break;
            case 3:
                afficher_supprimer_UE();
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

void interface::afficher_menu_UEchoix()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");
        std::cout << "1) Creer UE a choix" << std::endl;
        std::cout << "2) Modifier UE a choix" << std::endl;
        std::cout << "3) Supprimer UE a choix" << std::endl;
        std::cout << "4) Afficher toutes les UEs a choix" << std::endl;
        std::cout << "5) Retour" << std::endl;

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_UE_choix();
                break;
            case 2:
                afficher_modifier_UE_choix();
                break;
            case 3:
                afficher_supprimer_UE_choix();
                break;
            case 4:
                afficher_liste_UE_choix();
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
    std::vector<int> numero_maquette;
    std::vector<maquette*> maquette;
    int taille;
    std::string mention;
    std::cout << "Mention : ";
    std::cin >> mention;
    std::cout << "Combien de maquettes voulez-vous inserer dans la formation : ";
    std::cin >> taille;

    numero_maquette.resize(taille);

    std::cout << "Selectionnez les maquettes que vous voulez inclure dans la formation : " << std::endl;
    afficher_liste_maquette();
    for(unsigned int i = 0; i < numero_maquette.size(); i++)
    {
        std::cout << "maquette " << i << " : ";
        std::cin >> numero_maquette[i];
        std::cout << std::endl;
    }
    for(unsigned int i=0; i<numero_maquette.size(); i++)
        maquette.push_back(d_maquette[numero_maquette[i]]);

    d_formation.resize(d_formation.size()+1);
    d_formation.push_back(new formation(maquette ,mention));

    std::cout << "Formation correctement créée" << std::endl;
    system("pause");
}

void interface::afficher_modifier_formation()
{
    unsigned int i;
    std::vector<int> numero_maquette;
    std::vector<maquette*> maquette;
    int taille;
    std::string mention;
    afficher_liste_formation();
    std::cout << "Quelle formation voulez-vous modifier : ";
    std::cin >> i;
    std::cout << std::endl;

    std::cout << "Nouvelle mention : ";
    std::cin >> mention;

    std::cout << "Combien de maquettes voulez-vous inserer dans la formation : ";
    std::cin >> taille;

    numero_maquette.resize(taille);

    std::cout << "Selectionnez les maquettes que vous voulez inclure dans la formation : " << std::endl;
    afficher_liste_maquette();
    for(unsigned int i = 0; i < numero_maquette.size(); i++)
    {
        std::cout << "maquette " << i << " : ";
        std::cin >> numero_maquette[i];
        std::cout << std::endl;
    }
    for(unsigned int i=0; i<numero_maquette.size(); i++)
        maquette.push_back(d_maquette[numero_maquette[i]]);

    d_formation[i]->modifier_maquette(maquette);

    std::cout << "Formation correctement créée" << std::endl;
    system("pause");
}

void interface::afficher_supprimer_formation()
{
    unsigned int i;
    afficher_liste_formation();

    std::cout << "Quelle formation voulez vous supprimer : " << std::endl;
    std::cin >> i;

    delete d_formation[i];

    for(; i<d_formation.size()-1; i++)
        std::swap(d_formation[i],d_formation[i+1]);
    d_formation.resize(d_formation.size()-1);

    std::cout << "Formation correctement supprimée" << std::endl;
    system("pause");
}

void interface::afficher_liste_formation()
{
    for(unsigned int i=0; i<d_formation.size(); i++)
    {
        std::cout << " " << i << "  |  ";
        d_formation[i]->afficher(std::cout);
        std::cout << std::endl;
    }
    system("pause");
}

void interface::afficher_creer_UE()
{

}

void interface::afficher_modifier_UE()
{

}

void interface::afficher_supprimer_UE()
{

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
