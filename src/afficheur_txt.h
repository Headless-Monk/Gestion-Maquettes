#ifndef AFFICHEUR_TXT_H
#define AFFICHEUR_TXT_H

#include "afficheur.h"

class afficheur_txt : public afficheur
{
    public:
        afficheur_txt();
        virtual ~afficheur_txt();

        void exporter_maquette(const maquette &m) override;

    protected:
        std::string nom(const maquette &m) override;
        void ecrire_details_maquette(const maquette &m) override;
        void ecrire_ue(ue *u) override;
        void ecrire_ue_choix(const UEchoix *UEc) override;
        void ecrire_ue_seule(const UEseule *UEs) override;
        void ecrire_ue_composee(const UEcomposee *UEc) override;
        void ecrire_ecue(const ecue &ec) override;

    private:
        std::ofstream d_fichier;
};

#endif // AFFICHEUR_TXT_H
