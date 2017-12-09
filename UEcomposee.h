#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include <vector>

class ecue;

class UEcomposee : public ue
{
public:
  UEcomposee();
  UEcomposee(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEcomposee(std::vector <ecue*> &ecues, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient); //vraiment nécessaire ?
  UEcomposee(UEcomposee &UEc);
  ~UEcomposee();


private:
  std::vector <ecue*> d_ecues;
};

#endif
