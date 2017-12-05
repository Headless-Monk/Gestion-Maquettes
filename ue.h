#ifndef UE_H
#define UE_H

#include <string>

class ue
{
public:
  ue();
  ~ue();

private:
  string d_code;
  string d_intitule;
  unsigned int d_credits;
  unsigned int d_coefficient;
};

#endif
