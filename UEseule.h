#ifndef UESEULE_H
#define UESEULE_H

class ue;

class UEseule : public ue
{
public:
  UEseule();
  UEseule(unsigned int d_CM, unsigned int d_TD, unsigned int d_TP, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
  UEseule(UEseule &UEs);
  virtual ~UEseule();

  virtual afficher(ostream &os) const;

  /* set */
  void set_cm(unsigned int cm);
  void set_td(unsigned int td);
  void set_tp(unsigned int tp);

  /* get */
  void get_cm() const;
  void get_td() const;
  void get_tp() const;

private:
  unsigned int d_cm, d_td, d_tp;
};

UEseule& operator<<(ostream &os, UEseule &UEs);

#endif
