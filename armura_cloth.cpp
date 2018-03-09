#include <bits/stdc++.h>
#include "armura.h"
#include "armura_cloth.h"

using namespace std;

///Cloth-ul va avea aparare intre 2-4
Cloth::Cloth():Armura()
{
    int defence1;
    defence1 = rand() %3 + 2;
    Cloth :: defence = defence1;
    Cloth :: ArmorType = "Cloth";
}

Cloth :: ~Cloth()
{

}

int Cloth::getDefence() const
{
    return defence;
}

string Cloth::getArmorType() const
{
    return ArmorType;
}
