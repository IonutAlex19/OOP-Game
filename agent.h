#ifndef AGENT_H_
#define AGENT_H_

#include "arme.h"
#include "armura.h"
#include "harta.h"

class Agent
{
    int xPoz,yPoz,hp,vizibilitate;
    std :: string AgentName;
    Arme *Weapon;
    Armura *Armor;

    public :
        Agent();
        ~Agent();

        void setX(int );
        void setY(int );
        void setVis();
        int getX()const ;
        int getY()const ;
        int getVis()const;
        bool getLife(int )const;
        int gethp();

        void setWeapon(Arme* );
        void setArmor(Armura* );
        Arme* getWeapon()const;
        Armura* getArmor()const;

        friend class Harta;



};

#endif // AGENT_H_
