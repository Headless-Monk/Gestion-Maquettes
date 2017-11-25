#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <string>

class maquette;

class formation
{
public:
  formation();
  ~formation();


private:
  std::vector <maquette> d_maquettes;

  string d_libelle;

};

#endif
