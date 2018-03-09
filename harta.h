#ifndef HARTA_H_
#define HARTA_H_

using namespace std;
class Agent;
class Harta
{
    char **a;
    std::string fisier;
    int xH,yH;
    bool gameOver;

    Harta();
    ~Harta();

    void afiseazaJoc();
    void botsMove();
    void playerFight(int,int);
    void botsFight();
    void runda(char);

    std::string getFisier()const;

    bool checkFight(int,int,Agent&,int&,int&);
    bool verifPos(int,int);
    bool endGame()const;

    friend ostream& operator <<(ostream&, Harta);

    public:

        friend class Game;

};

#endif // HARTA_H_
