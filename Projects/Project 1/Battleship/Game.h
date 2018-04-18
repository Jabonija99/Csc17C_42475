/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: K99
 *
 * Created on April 17, 2018, 3:02 PM
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Grid.h"

class Game {
public:
    Game();
    ~Game();
    
    
    void welcome();
    void start();
    
    
    void enterCar();
    void enterBat();
    void enterCru();
    void enterSub();
    void enterDes();
    
    
private:
    Board* player;
    Board* enemy;
    
    void delay(int);
    void cls();

};

#endif /* GAME_H */

