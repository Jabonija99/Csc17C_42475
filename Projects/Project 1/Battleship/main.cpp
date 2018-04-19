/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on April 13, 2018, 8:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Grid.h"
#include "Board.h"
#include "Game.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    /*
    //Board game
    Board game;
    
    if(game.setCar('a',9,'a', 10)){
        cout <<"Success!\n";
    }
    
    if(game.setBat('b',10,'b', 9)){
        cout <<"Success!\n";
    }
    
    
    if(game.setCru('c',10,'c',9)){
        cout <<"Success!\n";
    }
    
    if(game.setSub('d',10,'d',9)){
        cout <<"Success!\n";
    }
    
    if(game.setDes('e',9,'e',10)){
        cout <<"Success!\n";
    }
    
    if(game.hit('a',1)){
        cout <<"Hit target!\n";
    }
    game.output();
    
    
    
    
    Board player;
    Board enemy;
    
    enemy.setCar('b', 1,'a',1);
    enemy.setBat('a',2,'a',4);
    enemy.setCru('b',2,'b',4);
    enemy.setSub('c',2,'c',4);
    enemy.setDes('d',4,'d',2);
    
    player.hit('a',1,enemy.gtBdDef());
    player.hit('f',2,enemy.gtBdDef());
    
    player.output();*/
    
    srand(time(0));
    Game game;
    game.init();
    
    
    return 0;
}

