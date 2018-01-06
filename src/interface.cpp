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
                system("cls");
                afficher_menu_ECUEs();
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
            afficher_creer_maquette();
            break;
        case 2:
            afficher_modifier_maquette();
            break;
        case 3:
            afficher_supprimer_maquette();
            break;
        case 4:
            afficher_menu_principal();
            break;
        default:
            break;
    }
}

void interface::afficher_menu_formations()
{

}

void interface::afficher_menu_UEs()
{

}

void interface::afficher_menu_ECUEs()
{

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
