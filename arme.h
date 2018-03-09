#ifndef ARME_H_
#define ARME_H_

class Arme
{
    protected:
        std::string denumireArma;
        int damage;

    public:
        Arme();
        ~Arme();
        virtual std::string getDenumire() const = 0;
        virtual int getDamage() const = 0;

};

#endif // ARME_H_
