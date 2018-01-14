#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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

  void sauvegarde_json(std::ofstream &os);

private:
  std::vector <maquette*> d_maquettes;
  std::string d_mention;
};

std::ostream& operator<<(std::ostream &os, formation &f);

#endif
