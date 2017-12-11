#ifndef MAQUETTE_H
#define MAQUETTE_H

#include <vector>
#include <string>

class ue;

class maquette
{
public:
  maquette();
  maquette(std::string mention, std::string parcours, unsigned int annee, unsigned int semestre);
  maquette(std::vector <ue*> &ues, std::string mention, std::string parcours, unsigned int annee, unsigned int semestre); //vraiment nécessaire ?
  maquette(maquette &m);
  ~maquette();
  //ajout d'un constructeur avec d_domaine ? plus logique pour implémentation en c++ mais inutile pour utilisation du programme


private:
  std::vector <ue*> d_ues;
  std::vector <bool> d_ue_option;

  std::string d_domaine; //défaut = "SCIENCES ET TECHNOLOGIE, SANTE"
  std::string d_mention;
  std::string d_parcours;
  unsigned int d_annee;
  unsigned int d_semestre;

};

#endif
