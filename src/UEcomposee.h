#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include <vector>
#include <ostream>

#include "ue.h"

class ecue;

class UEcomposee : public ue
{
public:
    UEcomposee() = delete;
    UEcomposee(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
    UEcomposee(std::vector <ecue*> &ecues, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
    UEcomposee(UEcomposee &UEc);
    virtual ~UEcomposee();

    virtual void afficher(std::ostream &os) const override;
    void ajouter_ecue(ecue *e);
    void supprimer_ecue(ecue *e);

    /* a faire */
    void monter_ecue(ecue *ec); //déplace de 1 dans la liste
    void descendre_ecue(ecue *ec);
    /* ------- */

    std::vector<ecue*> liste_ecue() const;

private:
  std::vector <ecue*> d_ecues;
};

std::ostream& operator<<(std::ostream &os, UEcomposee &UEc);

#endif
