#ifndef ARMURA_PLATE_H_
#define ARMURA_PLATE_H_

class Plate : public Armura
{
    public:
        Plate();
        ~Plate();
        int getDefence() const;
        std::string getArmorType() const;

};

#endif // ARMURA_PLATE_H_
