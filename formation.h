#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <string>

class maquette;

class formation
{
public:
  formation();
  formation(d_libelle);
  formation(std::vector <maquette> &maquettes, std::string mention); //vraiment nécéssaire ?
  formation(formation &f);

  ~formation();


private:
  std::vector <maquette> d_maquettes;
  std::string d_mention; //peut changer en fonction de ce qu'on veut stocker dans une formation
};

#endif
