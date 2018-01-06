#include <cstdlib>
#include "interface.h"


interface::interface()
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
        std::cout << std::endl;

        afficher_menu_principal();

        std::cin >> choix;

        switch (choix)
        {
            case 1:
                system("cls");
                afficher_menu_maquettes();
                break;
            case 2:
                system("cls");
                afficher_menu_formations();
                break;
            case 3:
                system("cls");
                afficher_menu_UEs();
                break;
            case 4:
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
    std::cout << "5) Quitter" << std::endl;
}

void interface::afficher_menu_maquettes()
{
    std::cout << "1) Creer maquette" << std::endl;
    std::cout << "2) Modifier maquette" << std::endl;
    std::cout << "3) Supprimer maquette" << std::endl;
    std::cout << "4) Retour" << std::endl;

    int choix = 0;
    std::cin >> choix;

    switch (choix)
    {
        case 1:
            system("cls");
            afficher_creer_maquette();
            break;
        case 2:
            system("cls");
            afficher_modifier_maquette();
            break;
        case 3:
            system("cls");
            afficher_supprimer_maquette();
            break;
        case 4:
            break;
        default:
            break;
    }
}

void interface::afficher_menu_formations()
{
    std::cout << "1) Creer maquette" << std::endl;
    std::cout << "2) Modifier maquette" << std::endl;
    std::cout << "3) Supprimer maquette" << std::endl;
    std::cout << "4) Retour" << std::endl;

    int choix = 0;
    std::cin >> choix;

    switch (choix)
    {
        case 1:
            system("cls");
            afficher_creer_formation();
            break;
        case 2:
            system("cls");
            afficher_modifier_formation();
            break;
        case 3:
            system("cls");
            afficher_supprimer_formation();
            break;
        case 4:
            break;
        default:
            break;
    }
}

void interface::afficher_menu_UEs()
{
    std::cout << "1) Creer UE" << std::endl;
    std::cout << "2) Modifier UE" << std::endl;
    std::cout << "3) Supprimer UE" << std::endl;
    std::cout << "4) Retour" << std::endl;

    int choix = 0;
    std::cin >> choix;

    switch (choix)
    {
        case 1:
            system("cls");
            afficher_creer_UE();
            break;
        case 2:
            system("cls");
            afficher_modifier_UE();
            break;
        case 3:
            system("cls");
            afficher_supprimer_UE();
            break;
        case 4:
            break;
        default:
            break;
    }
}

void interface::afficher_menu_ECUEs()
{
    std::cout << "1) Creer ECUE" << std::endl;
    std::cout << "2) Modifier ECUE" << std::endl;
    std::cout << "3) Supprimer ECUE" << std::endl;
    std::cout << "4) Retour" << std::endl;

    int choix = 0;
    std::cin >> choix;

    switch (choix)
    {
        case 1:
            system("cls");
            afficher_creer_ECUE();
            break;
        case 2:
            system("cls");
            afficher_modifier_ECUE();
            break;
        case 3:
            system("cls");
            afficher_supprimer_ECUE();
            break;
        case 4:
            break;
        default:
            break;
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

void interface::afficher_creer_formation()
{

}

void interface::afficher_modifier_formation()
{

}

void interface::afficher_supprimer_formation()
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

}

void interface::afficher_modifier_ECUE()
{

}

void interface::afficher_supprimer_ECUE()
{

}
