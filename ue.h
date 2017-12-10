#ifndef UE_H
#define UE_H

#include <string>

class ue
{
public:
  virtual void afficher() const =0;

  /* set */
  void set_code(std::strind code);
  void set_intitule(std::string intitule);
  void set_credits(unsigned int credits);
  void set_coefficient(unsigned int coefficient);

  /* get */
  std::string get_code() const;
  std::string get_intitule() const;
  unsigned int get_credits() const;
  unsigned int get_coefficient() const;

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

ue& operator<<(ostream &os, ue &u) const;

#endif
