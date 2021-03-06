#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <iostream>

class Floor;
class TextDisplay;
class Player;

class Game{
    
    private:
    std::shared_ptr<Floor> f;
    std::shared_ptr<TextDisplay> td;
    std::shared_ptr<Player> p;
    std::istream & infile;
    bool hasFile;
    bool moveEnemies;
    int level;
    int difficulty;

    int checkPlayerState(); // 0 for normal, 1 if player got to stairs, 2 if player died

    public:
    Game(std::shared_ptr<Player> py, std::istream & input, bool hasFile, int difficulty = 0 );
    ~Game();
    std::string tick();
    void print();
    void newFloor();
    void setMoveEnemies();
    bool getMoveEnemies();
    int getLevel();
    std::string endGame( bool showScore );
    std::string moveCharacter( int dir );
    
};

#endif
