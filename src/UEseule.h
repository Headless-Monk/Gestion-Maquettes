#ifndef UESEULE_H
#define UESEULE_H

#include <ostream>

#include "ue.h"

class UEseule : public ue
{
public:
  UEseule();
  UEseule(unsigned int d_cm, unsigned int d_td, unsigned int d_tp, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEseule(UEseule &UEs);
  virtual ~UEseule();

  virtual void afficher(std::ostream &os) const override;


  void heures_cm(unsigned int cm);
  void heures_td(unsigned int td);
  void heures_tp(unsigned int tp);


  void heures_cm() const;
  void heures_td() const;
  void heures_tp() const;

private:
  unsigned int d_heures_cm, d_heures_td, d_heures_tp;
};

UEseule& operator<<(std::ostream &os, const UEseule &UEs);

#endif
