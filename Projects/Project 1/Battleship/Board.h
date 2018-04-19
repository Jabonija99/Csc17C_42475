/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: K99
 *
 * Created on April 16, 2018, 5:41 PM
 */

#ifndef BOARD_H
#define BOARD_H


#include <string>
#include "Grid.h"

using namespace std;

class Board {
public:
    Board();
    ~Board();
    
    bool setCar(char, int, char, int);
    bool setBat(char, int, char, int);
    bool setCru(char, int, char, int);
    bool setSub(char, int, char, int);
    bool setDes(char, int, char, int);
    bool setShip(char, int, char, int, string,int);
    
    bool setRand();
    
    bool hit(char, int);
    bool hit(char, int, Grid*);
    void isHit(char, int);
    
    string gtAttAt(char, int);
    string gtDefAt(char, int);
    
    Grid* gtBdDef(){return boardDef;}
    Grid* gtBdAtt(){return boardAtt;}
    
    bool isElim();
    
    void output();
    
    char convert(int);
    
private:
    Grid* boardAtt;
    Grid* boardDef;
    
    string* ships;
    

};

#endif /* BOARD_H */

