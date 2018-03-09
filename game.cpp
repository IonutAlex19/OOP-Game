#include <bits/stdc++.h>
#include "harta.h"
#include "game.h"

using namespace std;

void Game::firstScreen()
{
    cout<<"\n\n\t\t\tTHE SHOOTOUT GAME\n\n";
    cout<<"\t\t\t\tRealizat de Cobuz Ionut-Alexandru\n\n";

    cout<<"\tBine ati venit!\n\n";
    cout<<"\tTipul jocului: LAST MAN STANDING\n\n";
    cout<<"\tRegulile acestui joc sunt foarte simple: Hunt or be Hunted.Esti un agent secret si te afli blocat pe o insula cu alti 3 agenti.";
    cout<<"\tFoloseste-te de itemele ascunse pe harta,arme(*) si armuri (x) pentru a-ti creste sansele de castig!\n\n";

    cout<<"\t(*)\n";
    cout<<"\t\tD-Deagle cu damage 1-15 \n";
    cout<<"\t\tM-M4A1 cu damage 15-50 \n";
    cout<<"\t\tS-AWP cu damage 50-100 \n";

    cout<<"\t(x)\n";
    cout<<"\t\tC-Cloth cu defence 2-4\n";
    cout<<"\t\tL-Leather cu defence 4-6\n";
    cout<<"\t\tP-Plate cu defence 6-8\n";

    cout<<"\n\n\t\t\t\t\tMULT SUCCES!\n\n";

    system("pause");
    system ("cls");

}

void Game::theGame()
{
    cout<<M;
    char c;
    while(c!='p')
    {
        if(M.endGame())
            break;
        cout<<"\n\nAlegeti directia: ";
        cin>>c;
        system("cls");
        M.runda(c);
    }
}

void Game::fisierul()
{
    string fis=M.getFisier();
    ofstream out("fisier.txt");
    out<<fis;
    out.close();
}
