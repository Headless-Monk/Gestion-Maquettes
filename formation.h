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

  std::string d_libelle;

};

#endif
