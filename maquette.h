#ifndef MAQUETTE_H
#define MAQUETTE_H

#include <vector>

class ue;

class maquette
{
public:
  maquette();
  ~maquette();


private:
  std::vector <ue*> d_ues;

};

#endif
