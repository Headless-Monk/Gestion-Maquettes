#ifndef ECUE_H
#define ECUE_H

#include <string>

class ecue
{
public:
  ecue();
  ~ecue();


private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_cours, d_TD, d_TP;
};

#endif
