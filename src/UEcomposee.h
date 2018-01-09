#ifndef UECOMPOSEE_H
#define UECOMPOSEE_H

#include <vector>
#include <ostream>

#include "ue.h"
#include "ecue.h"

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
    void supprimer_ecue(unsigned int ecue_a_supprimer);
    void modifier_entete(std::ostream &os, std::istream &is);

    void monter_ecue(unsigned int ecue_a_monter); //déplace de 1 dans la liste
    void descendre_ecue(unsigned int ecue_a_descendre);

    std::vector<ecue*> liste_ecue() const;

    void sauvegarde_Json(std::ofstream &os);

private:
  std::vector <ecue*> d_ecues;
};

std::ostream& operator<<(std::ostream &os, UEcomposee &UEc);

#endif
