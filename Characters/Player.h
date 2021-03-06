#ifndef PLAYER_H
#define PLAYER_H
#include <memory>

class Ground;
class Enemy;
class Gold;
class Potion;
class Dragon;
class Dwarf;
class Elf;
class Halfling;
class Human;
class Merchant;
class Orc;
class Game;


//Invariant: hp must be between 0 and maxHealth or if maxHealth is -1 then it has no upper bound
// atk and def must be greater than or  equal to 0
class Player {
    private:
    char c = '@';
    char type;
    bool isStair = 0;
    Ground * location;
    int baseAtk, baseDef;
    int checkHp(int hp);
    int checkStat(int val);

    protected:
    int score, hp, atk, def, maxHealth;
    
    void changeAtk(int newA);
    void changeDef(int newD);
    void changeHp(int newHp);

    public:
    Player(int hp, int atk, int def, int maxHealth, char type); //inital constructor
    virtual ~Player() = 0;
    
    char getChar();
    virtual int getScore() const;
    int getHp();
    int getAtk();
    int getDef();
    int getBaseAtk();
    int getBaseDef();
    // check if player is at stairs and needs new floor
    // MUST change isStair back to 0 using setIsStair() after new floor is created
    bool getIsStair();
    Ground * getLocation(); //called by game so the game knows where the player is
    void setLocation( Ground *g ); //called whenever the player moves to a new tile
    void setIsStair(bool is);

    virtual bool onAttacked(Enemy & e);
    virtual bool attack(Enemy * e);

    void newPlayer(); //called when there is a new floor
    char getType();

    void collectGold(std::shared_ptr<Gold> g);

    friend class Potion;
    friend class Game;

};

#endif
