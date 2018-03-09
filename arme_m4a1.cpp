#include <bits/stdc++.h>
#include "arme.h"
#include "arme_M4A1.h"

///M4A1 va avea un damage intre 15-50
using namespace std;

M4A1 :: M4A1() : Arme()
{
    int damage1;
    damage1 = rand()%35 + 15;

    M4A1::damage = damage1;
    M4A1::denumireArma = "M4A1";

}

M4A1 :: ~M4A1()
{

}

int M4A1::getDamage() const
{
    return damage;
}

string M4A1::getDenumire() const
{
    return denumireArma;
}

