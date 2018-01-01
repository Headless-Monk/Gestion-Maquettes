#ifndef UECHOIX_H
#define UECHOIX_H

#include <string>

class UEchoix
{
    public:
        virtual void afficher(std::ostream &os) const =0;


        virtual void code(std::string code) =0;
        virtual void intitule(std::string intitule) =0;
        virtual void credits(unsigned int credits) =0;
        virtual void coefficient(unsigned int coefficient) =0;


        virtual std::string code() const =0;
        virtual std::string intitule() const =0;
        virtual unsigned int credits() const =0;
        virtual unsigned int coefficient() const =0;

    protected:
        UEchoix();
        UEchoix(std::string code, std::string intitule, unsigned int credits, unsigned int coefficient);
        UEchoix(UEchoix &u);
        virtual ~UEchoix();

    private:
};

#endif // UECHOIX_H
