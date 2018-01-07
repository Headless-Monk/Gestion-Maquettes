#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <string>
#include <iostream>

#include "maquette.h"

class formation
{
public:
  formation() = delete;
  formation(std::string mention);

  /* à faire */
  formation(std::vector <maquette*> &maquettes, std::string mention);
  formation(formation &f);
  void afficher(std::ostream &os) const;
  /* ------- */
  ~formation();

  //pour l'instant classe inutile
  //elle sert à trier les maquettes

private:
  std::vector <maquette*> d_maquettes;
  std::string d_mention; //peut changer en fonction de ce qu'on veut stocker dans une formation
};

#endif
