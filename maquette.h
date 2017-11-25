#ifndef MAQUETTE_H
#define MAQUETTE_H

#include <vector>
#include <string>

class ue;

class maquette
{
public:
  maquette();
  ~maquette();


private:
  std::vector <ue*> d_ues;

  unsigned int d_num_semestre; //1 à 6 pour une licence
  string d_libelle;

};

#endif
