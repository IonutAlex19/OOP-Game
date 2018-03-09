#include <bits/stdc++.h>
#include "agent.h"
#include "arme.h"
#include "armura.h"
#include "arme_deagle.h"
#include "arme_awp.h"
#include "arme_m4a1.h"
#include "armura_cloth.h"

using namespace std;


/// la inceput fiecare agent are un Deagle si o armura de tip Cloth  + vizibilitate 1 (vizibilitatea creste doar cand iau AWP

Agent :: Agent():xPoz(0),yPoz(0),hp(100),AgentName(""),vizibilitate(1)
{
    Weapon = new Deagle();
    Armor = new Cloth();
}

Agent :: ~Agent()
{

}
///Settere pentru pozitia agentului
void Agent::setX(int x)
{
    xPoz = x;
}

void Agent::setY(int y)
{
    yPoz = y;

}

///Gettere pentru pozitia agentului
int Agent::getX()const
{
    return xPoz;

}

int Agent::getY()const
{
    return yPoz;
}

void Agent::setWeapon(Arme *arma)
{
    Weapon = arma;
}

/*void Agent::setVis()
{
    string nume;
    nume = Weapon->getDenumire();
    if(nume=="AWP")
        vizibilitate = 2;
    else
        vizibilitate = 1;
*/

int Agent::gethp()
{
    return hp;
}

int Agent::getVis()const
{
    return vizibilitate;
}
bool Agent::getLife(int hp)const
{
    if(hp<=0)return false;
    return true;
}

void Agent::setArmor(Armura *armura1)
{
    Armor = armura1;
}

Arme* Agent::getWeapon()const
{
    return Weapon;
}

Armura* Agent::getArmor()const
{
    return Armor;
}



