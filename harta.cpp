#include <bits/stdc++.h>
#include "harta.h"
#include "agent.h"
#include "arme.h"
#include "arme_deagle.h"
#include "arme_m4a1.h"
#include "arme_awp.h"
#include "armura.h"
#include "armura_cloth.h"
#include "armura_leather.h"
#include "armura_plate.h"
#include "ptLupta.h"

using namespace std;
///voi lucra cu 4 agenti: eu si 3 boti
Agent eu,bot1,bot2,bot3;

Harta::Harta():gameOver(false)
{///initializez matricea(harta) cu 0 in margini si ' ' in rest
    int i,j,k=4,xRand,yRand;

    a = new char*[26];
    for(i = 0; i <= 26;i++)
        a[i] = new char[26];

    for(i=0;i<=26;i++)
    {
        for(j=0;j<=26;j++)
        {
            if(i==0||j==0||i==26||j==26)
            {
                a[i][j]='0';
            }
            else
                a[i][j]=' ';
        }
    }
///voi pune agentii in cele 4 colturi, astfel gameplay-ul va fi mai lung
    a[1][1] = 'A';
    xH=1;
    yH=1;
    eu.setX(xH);
    eu.setY(yH);

    a[1][25] = 'A';
    i=1;
    j=25;
    bot1.setX(i);
    bot1.setY(j);

    a[25][1] = 'A';
    i=25;
    j=1;
    bot2.setX(i);
    bot2.setY(j);
    a[25][25] = 'A';
    i=25;
    j=25;
    bot3.setX(i);
    bot3.setY(j);

///pun cate 4 arme de fiecare fel, pentru ca am 4 agenti
    int nrArme = 4;
    while(nrArme)
    {
        do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand] = 'D';

                do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand] = 'M';

                do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand] = 'S';

        nrArme--;

    }
///la fel pt armuri
    int nrArmuri = 4;
    while(nrArmuri)
    {
        do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand]='C';

          do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand]='L';

          do
        {
            xRand = rand()%25 +1;
            yRand = rand()%25 +1;
        }
        while(a[xRand][yRand]!=' ');
        a[xRand][yRand]='P';
        nrArmuri--;
    }

//    /// afisare matrice
//
//    for (int i = 1; i <= 25; ++i)
//    {
//        for (int j = 1; j <= 25; ++j)
//            cout << a[i][j] << " ";
//        cout << "\n";
//    }
}

Harta :: ~Harta()
{
//    int i;
    fisier = "";
//    for(i=0;i<=26;i++)
//        delete a[i];
//    delete []a;

}

string Harta::getFisier()const
{
    return fisier;
}

bool Harta ::endGame()const
{
    return gameOver;
}

///supraincarc operatorul care afiseaza de fiecare data harta
ostream &operator<<(ostream &afis, Harta M)
{
    for (int i = -1; i <= 1; ++i)
    {
        afis << "\t\t";

        for (int j = -1; j <= 1; ++j)
            afis << "|-------";
        afis << "|\n";

        afis << "\t\t";
        for (int j = -1; j <= 1; ++j)
            afis << "|       ";
        afis << "|\n";

        afis << "\t\t";
        for (int j = -1; j <= 1; ++j)
        {
            afis << "|   ";
            afis <<M.a[M.xH+i][M.yH+j] << "   ";
        }
        afis << "|\n";

        afis << "\t\t";
        for (int j = -1; j <= 1; ++j)
            afis << "|       ";
        afis << "|\n";
    }

    afis << "\t\t";
    for (int j = -1; j <= 1; ++j)
            afis << "|-------";
    afis << "|";

    afis<<"\n\n";
    afis<<"\tHP: "<<eu.gethp()<<"\t\t\t\t\t\tPozitia ta: ("<<eu.getX()<<","<<eu.getY()<<")\n";
    afis<<"\tArma:\t"<<eu.getWeapon()->getDenumire()<<"  cu damage "<<eu.getWeapon()->getDamage()<<"\t\t\tPozitie Bot1: ("<<bot1.getX()<<","<<bot1.getY()<<")\n";
    afis<<"\tArmura:\t"<<eu.getArmor()->getArmorType()<<"  cu defence "<<eu.getArmor()->getDefence()<<"\t\t\tPozitie Bot2: ("<<bot2.getX()<<","<<bot2.getY()<<")\n";
    afis<<"\t\t\t\t\t\t\tPozitie Bot3: ("<<bot3.getX()<<","<<bot3.getY()<<")\n";

    return afis;

}
///functie pt verificarea unei pozitii
bool Harta::verifPos(int xH1,int yH2)
{
    if(a[xH1][yH2] != '0')
        return true;
    return false;
}
///functia checkFight verifica imprejurimile coordonatelor myX si myY si retine coordonatele victimei in xV si yV
bool Harta::checkFight(int myX,int myY,Agent& x,int &xV,int &yV)
{
    int i,j,vizi;

    vizi=x.getVis();

    for(i=-1*vizi;i<=vizi;i++)
        for(j=-1*vizi;j<=vizi;j++)
            if(a[myX+i][myY+j] == 'A' &&(i*i+j*j!=0))
            {
                xV=myX+i;
                yV=myY+j;
                return true;
            }
    return false;
}

void Harta::botsMove()
{///la inceput, fiecare bot incepe dintr-un colt si va avea o miscare random, la fiecare tura
    int xRand,yRand,xB=1,yB=25;
    if(bot1.getLife(bot1.hp))
    {

        do
        {
            xRand= rand()%3-1;
            yRand= rand()%3-1;
        }
        while(!verifPos(xB+xRand,yB+yRand)||(xRand*xRand+yRand*yRand==0));
        bot1.setX(xB+xRand);
        bot1.setY(yB+yRand);

        xB=xB+xRand;
        yB=yB+yRand;

///la fel ca player-ul, bot-ul poate intalni toate itemele pe harta si le poate lua daca sunt mai bune decat cele curente
        if(a[xB][yB]=='D')
        {
            Arme *d = new Deagle();
            if(d->getDamage()>bot1.getWeapon()->getDamage())
            {
                bot1.setWeapon(d);
                fisier += "Botul 1 a gasit Deagle\n";
            }
        }
        else if(a[xB][yB]=='M')
        {
            Arme *mm = new M4A1();
            if(mm->getDamage()>bot1.getWeapon()->getDamage())
            {
                bot1.setWeapon(mm);
                fisier +="Botul 1 a gasit M4A1\n";
            }
        }
        else if(a[xB][yB]=='S')
        {
            Arme *s = new AWP();
            if(s->getDamage()>bot1.getWeapon()->getDamage())
            {
                bot1.setWeapon(s);
                fisier +="Botul 1 a gasit AWP\n";
            }
        }
        else if(a[xB][yB]=='C')
        {
            Armura *c = new Cloth();
            if(c->getDefence()>bot1.getArmor()->getDefence())
            {
                bot1.setArmor(c);
                fisier +="Botul 1 a gasit o armura de tip Cloth";
            }
        }
        else if(a[xB][yB]=='L')
        {
            Armura *l = new Leather();
            {
                if(l->getDefence()>bot1.getArmor()->getDefence())
                {
                    bot1.setArmor(l);
                    fisier +="Botul 1 a gasit o armura de tip Leather";
                }
            }
        }
        else if(a[xB][yB]=='P')
        {
            Armura *p = new Plate();
            if(p->getDefence()>bot1.getArmor()->getDefence())
            {
                bot1.setArmor(p);
                fisier+="Botul 1 a gasit o armura de tip Plate";
            }
        }
        a[xB][yB]='A';
        a[xB-xRand][yB-yRand]=' ';
    }
///analog bot2
    if(bot2.getLife(bot2.hp))
    {
        xB=25;
        yB=1;
        do
        {
            xRand= rand()%3-1;
            yRand= rand()%3-1;
        }
        while(!verifPos(xB+xRand,yB+yRand)||(xRand*xRand+yRand*yRand==0));
        bot2.setX(xB+xRand);
        bot2.setY(yB+yRand);

        xB=xB+xRand;
        yB=yB+yRand;

        if(a[xB][yB]=='D')
        {
            Arme *d = new Deagle();
            if(d->getDamage()>bot2.getWeapon()->getDamage())
            {
                bot2.setWeapon(d);
                fisier += "Botul 2 a gasit Deagle\n";
            }
        }
        else if(a[xB][yB]=='M')
        {
            Arme *mm = new M4A1();
            if(mm->getDamage()>bot2.getWeapon()->getDamage())
            {
                bot2.setWeapon(mm);
                fisier +="Botul 2 a gasit M4A1\n";
            }
        }
        else if(a[xB][yB]=='S')
        {
            Arme *s = new AWP();
            if(s->getDamage()>bot2.getWeapon()->getDamage())
            {
                bot2.setWeapon(s);
                fisier +="Botul 2 a gasit AWP\n";
            }
        }
        else if(a[xB][yB]=='C')
        {
            Armura *c = new Cloth();
            if(c->getDefence()>bot2.getArmor()->getDefence())
            {
                bot2.setArmor(c);
                fisier +="Botul 2 a gasit o armura de tip Cloth";
            }
        }
        else if(a[xB][yB]=='L')
        {
            Armura *l = new Leather();
            {
                if(l->getDefence()>bot2.getArmor()->getDefence())
                {
                    bot2.setArmor(l);
                    fisier +="Botul 2 a gasit o armura de tip Leather";
                }
            }
        }
        else if(a[xB][yB]=='P')
        {
            Armura *p = new Plate();
            if(p->getDefence()>bot2.getArmor()->getDefence())
            {
                bot2.setArmor(p);
                fisier+="Botul 2 a gasit o armura de tip Plate";
            }
        }
        a[xB][yB]='A';
        a[xB-xRand][yB-yRand]=' ';

    }
///analog bot 3
    if(bot3.getLife(bot3.hp))
    {
        xB=25;
        yB=25;
        do
        {
            xRand= rand()%3-1;
            yRand= rand()%3-1;
        }
        while(!verifPos(xB+xRand,yB+yRand)||(xRand*xRand+yRand*yRand==0));
        bot3.setX(xB+xRand);
        bot3.setY(yB+yRand);

        xB=xB+xRand;
        yB=yB+yRand;

        if(a[xB][yB]=='D')
        {
            Arme *d = new Deagle();
            if(d->getDamage()>bot3.getWeapon()->getDamage())
            {
                bot3.setWeapon(d);
                fisier += "Botul 3 a gasit Deagle\n";
            }
        }
        else if(a[xB][yB]=='M')
        {
            Arme *mm = new M4A1();
            if(mm->getDamage()>bot3.getWeapon()->getDamage())
            {
                bot3.setWeapon(mm);
                fisier +="Botul 3 a gasit M4A1\n";
            }
        }
        else if(a[xB][yB]=='S')
        {
            Arme *s = new AWP();
            if(s->getDamage()>bot3.getWeapon()->getDamage())
            {
                bot3.setWeapon(s);
                fisier +="Botul 3 a gasit AWP\n";
            }
        }
        else if(a[xB][yB]=='C')
        {
            Armura *c = new Cloth();
            if(c->getDefence()>bot3.getArmor()->getDefence())
            {
                bot3.setArmor(c);
                fisier +="Botul 3 a gasit o armura de tip Cloth";
            }
        }
        else if(a[xB][yB]=='L')
        {
            Armura *l = new Leather();
            {
                if(l->getDefence()>bot1.getArmor()->getDefence())
                {
                    bot3.setArmor(l);
                    fisier +="Botul 3 a gasit o armura de tip Leather";
                }
            }
        }
        else if(a[xB][yB]=='P')
        {
            Armura *p = new Plate();
            if(p->getDefence()>bot3.getArmor()->getDefence())
            {
                bot3.setArmor(p);
                fisier+="Botul 3 a gasit o armura de tip Plate";
            }
        }
        a[xB][yB]='A';
        a[xB-xRand][yB-yRand]=' ';

    }
}
///verific pentru fiecare bot daca in raza sa de actiune se afla un alt agent, astfel, e suficient sa verific pt botul 1 daca gaseste botul 2 sau 3
///si pentru botul 2 daca il gaseste pe botul 3. Cand se lupta, pozitia pierzatorului este eliberata
void Harta::botsFight()
{
    int xV,yV;
    if(bot1.getLife(bot1.hp))
    {
        if(checkFight(bot1.xPoz,bot1.yPoz,bot1,xV,yV))
        {
            if(xV==bot2.xPoz&&yV==bot2.yPoz)
            {
                while(bot1.hp>=0&&bot2.hp>=0)
                {
                    bot1.hp=bot1.hp-bot2.getWeapon()->getDamage()+bot1.getArmor()->getDefence();
                    bot2.hp=bot2.hp-bot1.getWeapon()->getDamage()+bot2.getArmor()->getDefence();
                }
                if(bot1.hp<0)
                {
                    fisier+="Bot1 a fost omorat de Bot2\n";
                    a[bot2.xPoz][bot2.yPoz]=' ';
                    bot2.setX(bot1.xPoz);
                    bot2.setY(bot1.yPoz);
                    bot1.hp = 0;
                    return ;
                }
                else if(bot2.hp<0)
                {
                    fisier+="Bot2 a fost omorat de Bot1\n";
                    a[bot1.xPoz][bot1.yPoz]=' ';
                    bot1.setX(bot2.xPoz);
                    bot1.setY(bot2.yPoz);
                    bot2.hp = 0;
                    return ;
                }
            }
            else if(xV==bot3.xPoz&&yV==bot3.yPoz)
            {
                while(bot1.hp>=0&&bot3.hp>=0)
                {
                    bot1.hp=bot1.hp-bot3.getWeapon()->getDamage()+bot1.getArmor()->getDefence();
                    bot3.hp=bot3.hp-bot1.getWeapon()->getDamage()+bot3.getArmor()->getDefence();
                }
                if(bot1.hp<0)
                {
                    fisier+="Bot1 a fost omorat de Bot3\n";
                    a[bot3.xPoz][bot3.yPoz]=' ';
                    bot3.setX(bot1.xPoz);
                    bot3.setY(bot1.yPoz);
                    bot1.hp = 0;
                    return ;
                }
                else if(bot3.hp<0)
                {
                    fisier+="Bot3 a fost omorat de Bot1\n";
                    a[bot1.xPoz][bot1.yPoz]=' ';
                    bot1.setX(bot3.xPoz);
                    bot1.setY(bot3.yPoz);
                    bot3.hp = 0;
                    return ;
                }
            }
        }
    }
    if(bot2.getLife(bot2.hp))
    {
        if(checkFight(bot2.xPoz,bot2.yPoz,bot2,xV,yV))
        {
            if(xV==bot3.xPoz&&yV==bot3.yPoz)
            {
                while(bot2.hp>=0&&bot3.hp>=0)
                {
                    bot2.hp=bot2.hp-bot3.getWeapon()->getDamage()+bot2.getArmor()->getDefence();
                    bot3.hp=bot3.hp-bot2.getWeapon()->getDamage()+bot3.getArmor()->getDefence();
                }
                if(bot2.hp<0)
                {
                    fisier+="Bot2 a fost omorat de Bot3\n";
                    a[bot3.xPoz][bot3.yPoz]=' ';
                    bot3.setX(bot2.xPoz);
                    bot3.setY(bot2.yPoz);
                    bot2.hp = 0;
                    return ;
                }
                else if(bot3.hp<0)
                {
                    fisier+="Bot3 a fost omorat de Bot2\n";
                    a[bot2.xPoz][bot2.yPoz]=' ';
                    bot2.setX(bot3.xPoz);
                    bot2.setY(bot3.yPoz);
                    bot3.hp = 0;
                    return ;
                }
            }
        }
    }
}
///verific pentru player daca se gaseste ceva in raza sa de actiune si simulez lupta pentru toate cele 3 cazuri : bot1, bot2 sau bot3
///pentru a fi mai realistic, dupa o lupta vietile nu se regenereaza
void Harta::playerFight(int xPoz,int yPoz)
{
    int xV,yV;

    if(checkFight(eu.xPoz,eu.yPoz,eu,xV,yV))
    {
        system("cls");
        cout<<"Apasati R daca sunteti gata de lupta: ";
        char r;
        do
        {
            cin>>r;
        }
        while(r!='r'&&r!='R');
        if(xV==bot1.xPoz&&yV==bot1.yPoz)
        {
            lupta(eu.hp,bot1.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot1.getWeapon()->getDenumire(),bot1.getArmor()->getArmorType());
            while(eu.hp>=0&&bot1.hp>=0)
            {
                eu.hp=eu.hp-bot1.getWeapon()->getDamage()+eu.getArmor()->getDefence();
                bot1.hp=bot1.hp-eu.getWeapon()->getDamage()+bot1.getArmor()->getDefence();

                if(bot1.hp<=0)
                {
                    bot1.hp = 0;
                    system("cls");
                    lupta(eu.hp,bot1.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot1.getWeapon()->getDenumire(),bot1.getArmor()->getArmorType());
                    fisier+="L-ati invins pe Bot1!\n";
                    a[bot1.xPoz][bot1.yPoz]=' ';
                    cout<<"Ati invins!";
                    system("pause");
                    return;
                }
                else if(eu.hp<=0)
                {
                    eu.hp=0;
                    system("cls");
                    lupta(eu.hp,bot1.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot1.getWeapon()->getDenumire(),bot1.getArmor()->getArmorType());
                    cout<<"\nAti pierdut!";
                    fisier+="Bot1 v-a invins!\n";
                    system("pause");
                    gameOver=true;
                    break;
                }
                else
                {
                    cout<<"\n\Apasati r pentru continuarea luptei ";
                    do
                    {
                        cin>>r;
                    }
                    while(r!='r'&&r!='R');
                    system("cls");
                    lupta(eu.hp,bot1.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot1.getWeapon()->getDenumire(),bot1.getArmor()->getArmorType());
                }
            }
        }


        if(xV==bot2.xPoz&&yV==bot2.yPoz)
        {
            lupta(eu.hp,bot2.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot2.getWeapon()->getDenumire(),bot2.getArmor()->getArmorType());
            while(eu.hp>=0&&bot2.hp>=0)
            {
                eu.hp=eu.hp-bot2.getWeapon()->getDamage()+eu.getArmor()->getDefence();
                bot2.hp=bot2.hp-eu.getWeapon()->getDamage()+bot2.getArmor()->getDefence();

                if(bot2.hp<=0)
                {
                    bot2.hp = 0;
                    system("cls");
                    lupta(eu.hp,bot2.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot2.getWeapon()->getDenumire(),bot2.getArmor()->getArmorType());
                    fisier+="L-ati invins pe Bot2!\n";
                    a[bot2.xPoz][bot2.yPoz]=' ';
                    cout<<"Ati invins!";
                    system("pause");
                    return;
                }
                else if(eu.hp<=0)
                {
                    eu.hp=0;
                    system("cls");
                    lupta(eu.hp,bot2.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot2.getWeapon()->getDenumire(),bot2.getArmor()->getArmorType());
                    cout<<"\nAti pierdut!";
                    fisier+="Bot2 v-a invins!\n";
                    system("pause");
                    gameOver=true;
                    break;
                }
                else
                {
                    cout<<"\n\Apasati r pentru continuarea luptei ";
                    do
                    {
                        cin>>r;
                    }
                    while(r!='r'&&r!='R');
                    system("cls");
                    lupta(eu.hp,bot2.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot2.getWeapon()->getDenumire(),bot2.getArmor()->getArmorType());
                }
            }
        }

        if(xV==bot3.xPoz&&yV==bot3.yPoz)
        {
            lupta(eu.hp,bot3.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot3.getWeapon()->getDenumire(),bot3.getArmor()->getArmorType());
            while(eu.hp>=0&&bot3.hp>=0)
            {
                eu.hp=eu.hp-bot3.getWeapon()->getDamage()+eu.getArmor()->getDefence();
                bot3.hp=bot3.hp-eu.getWeapon()->getDamage()+bot3.getArmor()->getDefence();

                if(bot3.hp<=0)
                {
                    bot3.hp = 0;
                    system("cls");
                    lupta(eu.hp,bot3.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot3.getWeapon()->getDenumire(),bot3.getArmor()->getArmorType());
                    fisier+="L-ati invins pe Bot3!\n";
                    a[bot3.xPoz][bot3.yPoz]=' ';
                    cout<<"Ati invins!";
                    system("pause");
                    return;
                }
                else if(eu.hp<=0)
                {
                    eu.hp=0;
                    system("cls");
                    lupta(eu.hp,bot3.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot3.getWeapon()->getDenumire(),bot3.getArmor()->getArmorType());
                    cout<<"\nAti pierdut!";
                    fisier+="Bot3 v-a invins!\n";
                    system("pause");
                    gameOver=true;
                    break;
                }
                else
                {
                    cout<<"\n\Apasati r pentru continuarea luptei ";
                    do
                    {
                        cin>>r;
                    }
                    while(r!='r'&&r!='R');
                    system("cls");
                    lupta(eu.hp,bot3.hp,eu.getWeapon()->getDenumire(),eu.getArmor()->getArmorType(),bot3.getWeapon()->getDenumire(),bot3.getArmor()->getArmorType());
                }
            }
        }
    }
}

void Harta::runda(char c)
{
    int xC,yC,xC1,yC1;
    xC=xH;
    yC=yH;
    xC1=xC;
    yC1=yC;



   switch(c)
    {
    case 'q':
        eu.setX(xC--);
        xH--;
        eu.setY(yC--);
        yH--;
        break;
    case'w':
        eu.setX(xC--);
        xH--;
        break;
    case'e':
        eu.setX(xC--);
        xH--;
        eu.setY(yC++);
        yH++;
        break;
    case'a':
        eu.setY(yC--);
        yH--;
        break;
    case'd':
        eu.setY(yC++);
        yH++;
        break;
    case'z':
        eu.setX(xC++);
        eu.setY(yC--);
        xH++;
        yH--;
        break;
    case'x':
        eu.setX(xC++);
        xH++;
        break;
    case'c':
        eu.setX(xC++);
        eu.setY(yC++);
        xH++;
        yH++;
        break;
    }

    if(!verifPos(xC,yC))
    {
        eu.setX(xC1);
        eu.setY(yC1);
        cout<<*this;
        return;
    }

    else
    {


        a[xC1][yC1]=' ';
        cout << *this;
        botsMove();
        botsFight();

        fisier+="V-ati schimbat pozitia\n";
///analog ca la boti, verific fiecare item pe care il intalnesc
        if(a[xC][yC]=='D')
        {
            Arme *d = new Deagle();

            if(d->getDamage()>eu.getWeapon()->getDamage())
            {
                eu.setWeapon(d);
                fisier += "Ati gasit Deagle\n";
//                eu.setVis();
            }
        }
        else if(a[xC][yC]=='M')
        {
            Arme *mm = new M4A1();
            if(mm->getDamage()>eu.getWeapon()->getDamage())
            {
                eu.setWeapon(mm);
                fisier +="Ati gasit M4A1\n";
//                eu.setVis();
           }
        }
        else if(a[xC][yC]=='S')
        {
            Arme *s = new AWP();
            if(s->getDamage()>eu.getWeapon()->getDamage())
            {
                eu.setWeapon(s);
                fisier +="Ati gasit AWP\n";
//                eu.setVis();//
            }
        }
        else if(a[xC][yC]=='C')
        {
            Armura *c = new Cloth();
            if(c->getDefence()>eu.getArmor()->getDefence())
            {
                eu.setArmor(c);
                fisier +="Ati gasit o armura de tip Cloth";
            }
        }
        else if(a[xC][yC]=='L')
        {
            Armura *l = new Leather();
            {
                if(l->getDefence()>eu.getArmor()->getDefence())
                {
                    eu.setArmor(l);
                    fisier +="Ati gasit o armura de tip Leather";
                }
            }
        }
        else if(a[xC][yC]=='P')
        {
            Armura *p = new Plate();
            if(p->getDefence()>eu.getArmor()->getDefence())
            {
                eu.setArmor(p);
                fisier+="Ati gasit o armura de tip Plate";
            }
        }
//        a[xC-xC1][yC-yC1]=' '; ///


        if(bot1.hp<=0&&bot2.hp<=0&&bot3.hp<=0)
        {
            cout<<"Ati castigat jocul!";
            fisier+="Ati castigat jocul!";
            gameOver=true;
            system("CLS");
            cout<<"Game over!";
        }

        eu.xPoz = xC;
        eu.yPoz = yC;

        int xV=0,yV=0;

        if(checkFight(eu.xPoz,eu.yPoz,eu,xV,yV))
        {
            fisier+="Pregatiti-va de lupta!\n";

            playerFight(eu.xPoz,eu.yPoz);
            system("CLS");
            cout<<*this;

            if(gameOver)
               return;
        }
    }
}


///to do: vizibilitate ++ in cazul AWP

