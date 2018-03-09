#ifndef ARME_DEAGLE_H_
#define ARME_DEAGLE_H_

class Deagle : public Arme
{
    public:

        Deagle();
        ~Deagle();

        int getDamage() const ;
        std :: string getDenumire()const ;

};

#endif // ARME_DEAGLE_H_
