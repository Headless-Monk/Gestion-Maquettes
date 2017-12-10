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
  virtual ~UEcomposee();

  virtual void afficher(ostream &os) const;
  void ajouter_ecue(ecue *e);
  void supprimer_ecue(ecue *e);
  void echanger(ecue *e1, ecue *e2);

private:
  std::vector <ecue*> d_ecues;
};

UEcomposee& operator<<(ostream &os, UEcomposee &UEc) const;

#endif
