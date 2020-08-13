#include "Observer.h"
#include "Ground.h"
#include "TextDisplay.h"
#include "Info.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(){
    rows = 15;
    cols = 79;
    for (int r=0;r<rows;r+=1){
        vector<char> v;
        for (int c=0;c<cols;c+=1){
            v.push_back(' ');
        }
        display.push_back(v);
    }
}

void TextDisplay::notify( std::shared_ptr<Tile> whoNotified ){
    Info i = whoNotified->getInfo();
    display[i.row][i.col] = whoNotified->getChar();
}

void TextDisplay::notify(){} // huh? what am i supposed to do here

std::ostream & operator<<(std::ostream & out, const TextDisplay & td){
    for (int r=0;r<td.rows;r+=1){
        for (int c=0;c<td.cols;c+=1){
            out << td.display[r][c]; 
        }
        out << endl;
    }
    return out;
}

