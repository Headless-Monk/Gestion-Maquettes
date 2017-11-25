#ifndef UE_H
#define UE_H

#include <vector>
#include <string>

class ecue;

class ue
{
public:
  ue();
  ~ue();


private:
  std::vector <ecue*> d_ecues;
  string d_code;
  string d_intitule;
  unsigned int d_credits;
};

#endif
