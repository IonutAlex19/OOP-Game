#ifndef ARMURA_H_
#define ARMURA_H_

class Armura
{
    protected:
        int defence;
        std :: string ArmorType;
    public :
        Armura();
        ~Armura();

        virtual int getDefence() const = 0;
        virtual std ::string getArmorType() const = 0;

};

#endif // ARMURA_H_
