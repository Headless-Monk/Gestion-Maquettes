#include "interface.h"

using std::cout;
using std::endl;
using std::cin;

interface::interface():d_maquette{}, d_formation{}, d_ue{}, d_ecue{}, d_UEchoix{}
{

}

interface::~interface()
{
/*
*
*
*   FUITESSSSSSSSSSSSSSSSSS DE MEMOIRE
*
*
*
*/
}

void interface::initialiser()
{
    int choix = 0;
    while(choix != 6)
    {
        system("cls");

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
    while(choix != 5)
    {
        system("cls");
        cout << "1) Creer maquette" << endl;
        cout << "2) Modifier maquette" << endl;
        cout << "3) Supprimer maquette" << endl;
        cout << "4) Afficher liste des maquettes" << endl;
        cout << "5) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                afficher_creer_maquette();
                system("pause");
                break;
            case 2:
                afficher_modifier_maquette();
                break;
            case 3:
                afficher_supprimer_maquette();
                break;
            case 4:
                afficher_liste_maquette();
                system("pause");
                break;
            case 5:
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

void interface::afficher_creer_maquette()
{
    system("cls");
    d_maquette.push_back(new maquette{});
    d_maquette[d_maquette.size()-1]->saisir_maquette(cout, cin);
    cout << endl << "Maquette creee :" << endl;
    d_maquette[d_maquette.size()-1]->afficher(cout);
    cout << endl;
}

void interface::afficher_modifier_maquette()
{
    system("cls");
    unsigned int maquette_a_modifier = 0;
    afficher_liste_maquette_entete();
    cout << "Saisir le numero de la maquette a modifier (0 pour annuler) :" << endl;
    cin >> maquette_a_modifier;

    if(maquette_a_modifier != 0)
    {
        maquette_a_modifier--;
        afficher_menu_modification_maquette(d_maquette[maquette_a_modifier]);
    }
}

void interface::afficher_menu_modification_maquette(maquette *m)
{
    int choix = 0;
    while(choix != 7)
    {
        system("cls");
        m->afficher(cout);
        cout << endl;
        cout << "1) Modifier l'entete" << endl;
        cout << "2) Ajouter une UE a choix" << endl;
        cout << "3) Ajouter une UE seule" << endl;
        cout << "4) Ajouter une UE composee" << endl;
        cout << "5) Deplacer une UE de 1 vers le haut" << endl;
        cout << "6) Deplacer une UE de 1 vers le bas" << endl;
        cout << "7) Retour" << endl;

        cin >> choix;

        switch (choix)
        {
            case 1:
                m->saisir_maquette(cout, cin);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:



            test(m);



                break;
            case 6:

                break;
            case 7:
                break;
            default:
                break;
        }
    }
}

void interface::test(maquette *m)
{
                  unsigned int ue_a_deplacer = 0;
                cout << "Saisir le numero de l'ue a deplacer (0 pour annuler) :" << endl;
                cin >> ue_a_deplacer;

                if(ue_a_deplacer != 0)
                {
                    ue_a_deplacer--;
                    m->monter_ue(ue_a_deplacer);
                }
}

void interface::afficher_supprimer_maquette()
{
    system("cls");
    unsigned int maquette_a_supprimer = 0;
    afficher_liste_maquette_entete();
    cout << "Saisir le numero de la maquette a supprimer (0 pour annuler) :" << endl;
    cin >> maquette_a_supprimer;

    if(maquette_a_supprimer != 0)
    {
        maquette_a_supprimer--;
        delete d_maquette[maquette_a_supprimer];

        for(; maquette_a_supprimer<d_maquette.size()-1; maquette_a_supprimer++)
            std::swap(d_maquette[maquette_a_supprimer],d_maquette[maquette_a_supprimer+1]);
        d_maquette.resize(d_maquette.size()-1);
    }
}

void interface::afficher_liste_maquette()
{
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_maquette[i]->afficher(cout);
        cout << endl;
    }
}

void interface::afficher_liste_maquette_entete()
{
    for(unsigned int i=0; i<d_maquette.size(); i++)
    {
        cout << " " << i+1 << "  |  " << endl;
        d_maquette[i]->afficher_entete(cout);
        cout << endl;
    }
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
