#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

class interface
{
public:
    interface();
    virtual ~interface();

    void initialiser();
    void afficher_menu_principal();
    void afficher_menu_maquettes();
    void afficher_menu_formations();
    void afficher_menu_UEs();
    void afficher_menu_ECUEs();

    void afficher_creer_maquette();
    void afficher_modifier_maquette();
    void afficher_supprimer_maquette();

    void afficher_creer_formation();
    void afficher_modifier_formation();
    void afficher_supprimer_formation();

    void afficher_creer_UE();
    void afficher_modifier_UE();
    void afficher_supprimer_UE();

    void afficher_creer_ECUE();
    void afficher_modifier_ECUE();
    void afficher_supprimer_ECUE();
};

#endif
