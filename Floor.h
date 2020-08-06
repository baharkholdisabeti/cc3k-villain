#ifndef FLOOR_H
#define FLOOR_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Subject;
class Observer;
class Tile;
class TextDisplay;
class Enemy;
class Potion;
class Gold;

class Floor{
  private:
    std::vector<std::shared_ptr<Tile>> tiles;
    void spawnEnemies();
    void spawnItems();
    void spawnStairs();

    void addNeighbours( Subject & s );
    void addTextDisplay( Subject & s );

    int randomInt(int low, int high);
    int getRow(int index);
    int getCol(int index);

    std::shared_ptr<Enemy> getEnemy();
    std::shared_ptr<Potion> getPotion();
    std::shared_ptr<Gold> getGold();

  public:

    Floor( std::shared_ptr<TextDisplay> td );
    Floor( std::shared_ptr<TextDisplay> td, std::istream in );

    //functions for tick 
    void calculate(); // this makes the tiles calculate their booleans according to what pointer is on them
    void notify(); // calls notify on all the tiles

    void print();
    void clear(); //clears the enemies and potions and gold and stairs
    
    void generate (); // randomly generates the enemies and gold and potions. 
    void floorPlan(std::istream &in);
    void defaultPlan();
    void moveChar(int dir);
    void moveEnemies();
    void attack(int row, int col, int dir);
    std::string usePotion(int row, int col, int dir);

};

#endif