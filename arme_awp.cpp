#include <bits/stdc++.h>
#include "arme.h";
#include "arme_awp.h"

using namespace std;
///AWP-ul va avea un damage intre 50-100
AWP :: AWP() : Arme()
{
    int damage1;
    damage1 = rand()%51 + 50;

    AWP :: damage = damage1;
    AWP :: denumireArma = "AWP";
}

AWP :: ~AWP()
{

}

int AWP::getDamage() const
{
    return damage;
}

string AWP::getDenumire() const
{
    return denumireArma;
}
