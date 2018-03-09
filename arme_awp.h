#ifndef ARME_AWP_H_
#define ARME_AWP_H_

class AWP:public Arme
{
    public:
        AWP();
        ~AWP();

        int getDamage() const;
        std::string getDenumire() const;

};

#endif // ARME_AWP_H_
