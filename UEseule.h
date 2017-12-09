#ifndef UESEULE_H
#define UESEULE_H

class ue;

class UEseule : public ue
{
public:
  UEseule();
  UEseule(unsigned int d_CM, unsigned int d_TD, unsigned int d_TP, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEseule(UEseule &UEs);
  ~UEseule();


private:
  unsigned int d_CM, d_TD, d_TP;
};

#endif
