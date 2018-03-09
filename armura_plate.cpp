#include <bits/stdc++.h>
#include "armura.h"
#include "armura_plate.h"

using namespace std;

///Plate-ul va avea aparare intre 6-8
Plate :: Plate() : Armura()
{
    int defence1;
    defence1 = rand()% 3 + 6;

    Plate :: defence = defence1;
    Plate :: ArmorType = "Plate";
}

Plate :: ~Plate()
{

}

int Plate::getDefence()const
{
    return defence;
}

string Plate::getArmorType()const
{
    return ArmorType;
}
