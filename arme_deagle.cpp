#include <bits/stdc++.h>
#include "arme.h"
#include "arme_deagle.h";

///Deagle-ul va avea un damage intre 1-15
using namespace std;

Deagle :: Deagle() : Arme()
{
    int damage1;
    damage1= rand() % 15 + 1;

    Arme :: damage = damage1;
    Arme :: denumireArma = "Deagle";

}

Deagle :: ~Deagle()
{

}

int Deagle::getDamage() const
{
    return damage;
}

string Deagle::getDenumire() const
{
    return denumireArma;
}


