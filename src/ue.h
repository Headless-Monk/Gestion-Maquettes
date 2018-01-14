#ifndef UE_H
#define UE_H

#include <string>
#include <ostream>

#include "UEchoix.h"

class ue
{
public:
    ue() = delete;
    ue(std::string code, std::string intitule,
    unsigned int credits, unsigned int coefficient);
    ue(ue &u);
    virtual ~ue();

    virtual void afficher(std::ostream &os) const =0;


    void code(std::string code);
    void intitule(std::string intitule);
    void credits(unsigned int credits);
    void coefficient(unsigned int coefficient);


    std::string code() const;
    std::string intitule() const;
    unsigned int credits() const;
    unsigned int coefficient() const;

protected:


private:
  std::string d_code;
  std::string d_intitule;
  unsigned int d_credits;
  unsigned int d_coefficient;
};

std::ostream& operator<<(std::ostream &os, const ue &u);

#endif
