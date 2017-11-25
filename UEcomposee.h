#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include <vector>

class ecue;

class UEcomposee : public ue
{
public:
  UEcomposee();
  ~UEcomposee();


private:
  std::vector <ecue*> d_ecues;
};

#endif
