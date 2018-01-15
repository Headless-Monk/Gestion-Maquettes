#ifndef INTERFACE_H
#define INTERFACE_H

#include "maquette.h"
#include "formation.h"
#include "UEseule.h"
#include "UEcomposee.h"
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
    void afficher_menu_UEseuls();
    void afficher_menu_UEcomposees();
    void afficher_menu_ECUEs();
    void afficher_menu_UEchoix();

    void afficher_creer_maquette();
    void afficher_modifier_maquette();
    void afficher_menu_modification_maquette(maquette *m);
    void afficher_supprimer_maquette();
    void afficher_liste_maquette();
    void afficher_liste_maquette_entete();
    void afficher_export_maquette();
    void afficher_monter_ue(maquette *m);
    void afficher_descendre_ue(maquette *m);

    void afficher_creer_formation();
    void afficher_modifier_formation();
    void afficher_supprimer_formation();
    void afficher_liste_formation();

    void afficher_creer_UEcomposee();
    void afficher_modifier_UEcomposee();
    void afficher_menu_modification_UEcomposee(UEcomposee *UEc);
    void afficher_supprimer_UEcomposee();
    void afficher_liste_UEcomposee();

    void afficher_creer_UEseule();
    void afficher_modifier_UEseule();
    void afficher_supprimer_UEseule();
    void afficher_liste_UEseule();

    void afficher_creer_ECUE();
    void afficher_modifier_ECUE();
    void afficher_supprimer_ECUE();
    void afficher_liste_ECUE();

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
