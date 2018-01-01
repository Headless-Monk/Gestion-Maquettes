#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include <vector>
#include <ostream>

#include "ue.h"

class ecue;

class UEcomposee : public ue
{
public:
  UEcomposee();
  UEcomposee(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEcomposee(std::vector <ecue*> &ecues, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEcomposee(UEcomposee &UEc);
  virtual ~UEcomposee();

  virtual void afficher(std::ostream &os) const override;
  void ajouter_ecue(ecue *e);
  void supprimer_ecue(ecue *e);
  void echanger_position(ecue *e1, ecue *e2);

private:
  std::vector <ecue*> d_ecues;
};

UEcomposee& operator<<(std::ostream &os, UEcomposee &UEc);

#endif
