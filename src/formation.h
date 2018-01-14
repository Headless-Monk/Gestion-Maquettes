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
  formation(std::vector <maquette*> &maquettes, std::string mention);
  formation(formation &f);

  ~formation();

  void afficher(std::ostream &os) const;
  void modifier_maquette(std::vector<maquette*> maq);

  std::string mention() const;
  unsigned int nombre_maquettes() const;

private:
  std::vector <maquette*> d_maquettes;
  std::string d_mention;
};

#endif
