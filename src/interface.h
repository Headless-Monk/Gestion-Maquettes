#ifndef INTERFACE_H
#define INTERFACE_H

#include "maquette.h"
#include "formation.h"
#include "ue.h"
#include "ecue.h"
#include "UEchoix.h"

#include <iostream>
#include <vector>
#include <cstdlib>

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
    void afficher_liste_maquette();

    void afficher_creer_formation();
    void afficher_modifier_formation();
    void afficher_supprimer_formation();
    void afficher_liste_formation();

    void afficher_creer_UE();
    void afficher_modifier_UE();
    void afficher_supprimer_UE();
    void afficher_liste_UE();

    void afficher_creer_ECUE();
    void afficher_modifier_ECUE();
    void afficher_supprimer_ECUE();
    void afficher_liste_ECUE();

    void afficher_creer_UE_choix();
    void afficher_modifier_UE_choix();
    void afficher_supprimer_UE_choix();
    void afficher_liste_UE_choix();

private:
    std::vector<maquette*> d_maquette;
    std::vector<formation*> d_formation;
    std::vector<ue*> d_ue;
    std::vector<ecue*> d_ecue;
    std::vector<UEchoix*> d_UEchoix;
};

#endif
