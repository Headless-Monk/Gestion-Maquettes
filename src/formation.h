#ifndef FORMATION_H
#define FORMATION_H

#include <vector>
#include <string>

class maquette;

class formation
{
public:
  formation();
  formation(std::string mention);
  formation(std::vector <maquette> &maquettes, std::string mention);
  formation(formation &f);
  ~formation();

  //pour l'instant classe inutile
  //elle sert à trier les maquettes

private:
  std::vector <maquette> d_maquettes;
  std::string d_mention; //peut changer en fonction de ce qu'on veut stocker dans une formation
};

#endif
