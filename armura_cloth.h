#ifndef ARMURA_CLOTH_H_
#define ARMURA_CLOTH_H_

class Cloth : public Armura
{
    public:
        Cloth();
        ~Cloth();

        int getDefence() const;
        std :: string getArmorType() const;

};

#endif // ARMURA_CLOTH_H_
