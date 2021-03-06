#ifndef ECUE_H
#define ECUE_H

#include <string>
#include <iostream>
#include <ostream>

class ecue
{
public:
    ecue();
    ecue(unsigned int coeff, std::string code, std::string intitule, unsigned int cm, unsigned int td, unsigned int tp);
    ecue(ecue &e);
    ~ecue();

    void afficher(std::ostream &os) const;
    unsigned int duree_totale() const;

    void coefficent(unsigned int coeff);
    void code(std::string code);
    void intitule(std::string intitule);
    void heures_cm(unsigned int cm);
    void heures_td(unsigned int td);
    void heures_tp(unsigned int tp);

    unsigned int coefficient() const;
    std::string code() const;
    std::string intitule() const;
    unsigned int heures_cm() const;
    unsigned int heures_td() const;
    unsigned int heures_tp() const;

private:
    unsigned int d_coefficient;
    std::string d_code;
    std::string d_intitule;
    unsigned int d_heures_cm, d_heures_td, d_heures_tp;
};

std::ostream& operator<<(std::ostream &os, const ecue &e);

#endif
