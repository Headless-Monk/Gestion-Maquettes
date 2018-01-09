#ifndef UESEULE_H
#define UESEULE_H

#include <ostream>

#include "ue.h"

class UEseule : public ue
{
public:
    UEseule() = delete;
    UEseule(unsigned int cm, unsigned int td, unsigned int tp, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
    UEseule(UEseule &u);
    virtual ~UEseule();

    virtual void afficher(std::ostream &os) const override;
    unsigned int duree_totale() const;

    void heures_cm(unsigned int cm);
    void heures_td(unsigned int td);
    void heures_tp(unsigned int tp);

    void modifier_completement_ue(unsigned int cm, unsigned int td, unsigned int tp, std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);


    unsigned int heures_cm() const;
    unsigned int heures_td() const;
    unsigned int heures_tp() const;

    void sauvegarde_Json(std::ofstream &os);

private:
    unsigned int d_heures_cm, d_heures_td, d_heures_tp;
};

std::ostream& operator<<(std::ostream &os, const UEseule &UEs);

#endif
