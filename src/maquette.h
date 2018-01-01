#ifndef MAQUETTE_H
#define MAQUETTE_H

#include <vector>
#include <string>

class UEchoix;

class maquette
{
public:
    maquette();
    maquette(std::string mention, std::string parcours, unsigned int annee, unsigned int semestre);
    maquette(std::vector <UEchoix*> &ues, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre);
    maquette(maquette &m);
    ~maquette();

    void afficher(std::ostream &os) const;
    void ajouter_ue(UEchoix *u);
    void supprimer_ue(UEchoix *u);
    void echanger_position(UEchoix *u1, UEchoix *u2);


    void domaine(std::string domaine);
    void mention(std::string mention);
    void parcours(std::string parcours);
    void annee(unsigned int annee);
    void semestre(unsigned int semestre);


    std::string domaine() const;
    std::string mention() const;
    std::string parcours() const;
    unsigned int annee() const;
    unsigned int smestre() const;

private:
    std::vector <UEchoix*> d_ues;

    std::string d_domaine; //défaut = "SCIENCES ET TECHNOLOGIE, SANTE"
    std::string d_mention;
    std::string d_parcours;
    unsigned int d_annee;
    unsigned int d_semestre;

};

maquette& operator<<(std::ostream &os, maquette &m);

#endif
