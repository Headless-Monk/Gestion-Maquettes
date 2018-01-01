#ifndef UE_H
#define UE_H

#include <string>
#include <ostream>

#include "UEchoix.h"

class ue : public UEchoix
{
public:
  virtual void afficher(std::ostream &os) const =0;


  void code(std::string code) override;
  void intitule(std::string intitule) override;
  void credits(unsigned int credits) override;
  void coefficient(unsigned int coefficient) override;


  std::string code() const override;
  std::string intitule() const override;
  unsigned int credits() const override;
  unsigned int coefficient() const override;

protected:
  ue();
  ue(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  ue(ue &u);
  virtual ~ue();

private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_credits;
  unsigned int d_coefficient;
};

ue& operator<<(std::ostream &os, const ue &u);

#endif
