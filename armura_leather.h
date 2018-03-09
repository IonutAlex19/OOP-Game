#ifndef ARMURA_LEATHER_H_
#define ARMURA_LEATHER_H_

class Leather : public Armura
{
    public:
        Leather();
        ~Leather();
        int getDefence() const;
        std :: string getArmorType()const;


};

#endif // ARMURA_LEATHER_H_
