#ifndef MAQUETTE_H
#define MAQUETTE_H

#include <vector>
#include <string>
#include <ostream>
#include <iostream>

#include "ue.h"
#include "UEchoix.h"

class maquette
{
public:
    maquette();
    maquette(std::string mention, std::string parcours, unsigned int annee, unsigned int semestre);
    maquette(std::vector <ue*> &ues, std::vector <UEchoix*> &ues_choix, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre);
    maquette(maquette &m);
    ~maquette();

    void afficher(std::ostream &os) const;
    void afficher_entete(std::ostream &os) const;
    void ajouter_ue(ue *u);
    void ajouter_ue(UEchoix *uc);
    void supprimer_ue(ue *u);
    void supprimer_ue(UEchoix *uc);
    void saisir_maquette(std::ostream &os, std::istream &is);

    void monter_ue(ue *u); //déplace de 1 dans la liste
    void monter_ue(UEchoix *uc);
    void monter_ue(unsigned int numero_ue);
    void descendre_ue(ue *u);
    void descendre_ue(UEchoix *uc);
    void descendre_ue(unsigned int numero_ue);

    void domaine(std::string domaine);
    void mention(std::string mention);
    void parcours(std::string parcours);
    void annee(unsigned int annee);
    void semestre(unsigned int semestre);
    void position_ue_choix_dans_ue(unsigned int position);

    std::vector <ue*> liste_ues() const;
    std::vector <UEchoix*> liste_ues_choix() const;
    unsigned int position_ue_choix_dans_ue() const;
    std::string domaine() const;
    std::string mention() const;
    std::string parcours() const;
    unsigned int annee() const;
    unsigned int semestre() const;
    unsigned int nombre_ue_choix() const;
    unsigned int nombre_ue() const;

private:
    std::vector <ue*> d_ues;
    std::vector <UEchoix*> d_ues_choix;
    unsigned int d_position_ue_choix_dans_ue;

    std::string d_domaine; //défaut = "SCIENCES ET TECHNOLOGIE, SANTE"
    std::string d_mention;
    std::string d_parcours;
    unsigned int d_annee;
    unsigned int d_semestre;

};

std::ostream& operator<<(std::ostream &os, maquette &m);

#endif
