/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on April 18, 2018, 1:15 AM
 */

#include <cstdlib>

#include "Grid.h"
#include "Board.h"
#include "Game.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    srand(time(0));
    
    //Initialize game
    Game game;
    game.init();
   
    
    return 0;
}

