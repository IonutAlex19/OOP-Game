#include <bits/stdc++.h>
#include "armura.h"
#include "armura_leather.h"

using namespace std;

///Leather-ul va avae aparare intre 4-6
Leather :: Leather():Armura()
{
    int defence1;
    defence1 = rand()%3 + 4;

    Leather :: defence = defence1;
    Leather :: ArmorType = "Leather";
}

Leather :: ~Leather()
{

}

int Leather::getDefence()const
{
    return defence;
}

string Leather::getArmorType() const
{
    return ArmorType;
}
