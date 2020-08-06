#ifndef READ_FILE_H
#define READ_FILE_H
#include <memory>
#include <iostream>

class Floor; 
class TextDisplay;
class Tile;
class Player;
class Potion;
class Enemy;
class Gold;
class Ground;

class ReadFile{
    public:
    void makeFloor( Floor & f ); //default version

    void makeFloor( Floor & f, std::shared_ptr<Player> p, std::istream & in ); //from file
};

void addTile( Floor & f, int row, int col, char c, std::shared_ptr<Player> p = nullptr ); 

std::shared_ptr<Potion> getPotion( char c );
std::shared_ptr<Gold> getGold( char c );
std::shared_ptr<Enemy> getEnemy( char c );

std::shared_ptr<Ground> getGround( int row, int col, char c );

#endif
