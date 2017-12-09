#ifndef UE_H
#define UE_H

#include <string>

class ue
{
public:
  ue();
  ue(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  ue(ue &u);
  ~ue();

private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_credits;
  unsigned int d_coefficient;
};

#endif
