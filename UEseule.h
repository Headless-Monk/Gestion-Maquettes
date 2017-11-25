#ifndef UESEULE_H
#define UESEULE_H

class ue;

class UEseule : public ue
{
public:
  UEseule();
  ~UEseule();


private:
  unsigned int d_cours, d_TD, d_TP;
};

#endif
