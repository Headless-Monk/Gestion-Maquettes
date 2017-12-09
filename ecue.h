#ifndef ECUE_H
#define ECUE_H

#include <string>

class ecue
{
public:
  ecue();
  ecue(string d_code, string d_intitule, unsigned int cm, unsigned int td, unsigned int tp)
  ecue(ecue &e);
  ~ecue();



private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_cm, d_td, d_tp;
};

#endif
