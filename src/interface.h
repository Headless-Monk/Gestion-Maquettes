#ifndef INTERFACE_H
#define INTERFACE_H

#include "maquette.h"
#include "formation.h"
#include "ue.h"
#include "ecue.h"
#include "UEchoix.h"
#include "UEseule.h"
#include "UEcomposee.h"
#include "afficheur_txt.h"

#include <iostream>
#include <vector>
#include <cstdlib>

class interface
{
public:
    interface();
    virtual ~interface();

    void temporaire_ecrit_maquette();

    void initialiser();
    void afficher_menu_principal();
    void afficher_menu_maquettes();
    void afficher_menu_formations();
    void afficher_menu_UEs();
    void afficher_menu_ECUEs();

    //SYLVAIN
    void afficher_creer_maquette();
    void afficher_modifier_maquette();
    void afficher_menu_modification_maquette(maquette *m);
    void afficher_supprimer_maquette();
    void afficher_liste_maquette();
    void afficher_liste_maquette_entete();
    void afficher_export_maquette();

    //OLIVIER
    void afficher_creer_formation();
    void afficher_modifier_formation();
    void afficher_supprimer_formation();
    void afficher_liste_formation();

    //TAREK
    void afficher_creer_UE();
    void afficher_modifier_UE();
    void afficher_supprimer_UE();
    void afficher_liste_UE();

    //OLIVIER
    void afficher_creer_ECUE();
    void afficher_modifier_ECUE();
    void afficher_supprimer_ECUE();
    void afficher_liste_ECUE();

    //QUAND LE RESTE SERA FINI
    void afficher_creer_UE_choix();
    void afficher_modifier_UE_choix();
    void afficher_supprimer_UE_choix();
    void afficher_liste_UE_choix();

private:
    std::vector<formation*> d_formation;
    std::vector<maquette*> d_maquette;

    std::vector<UEchoix*> d_UEchoix;
    std::vector<UEseule*> d_UEseule;
    std::vector<UEcomposee*> d_UEcomposee;

    std::vector<ecue*> d_ecue;
};

#endif
