/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: K99
 * 
 * Created on April 17, 2018, 3:02 PM
 */

#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

Game::Game() {
    srand(time(0));
    player = new Board();
    enemy = new Board();
}


Game::~Game() {
    delete player;
    delete enemy;
}



void Game::init(){
    bool quit = false;
    do{
        //Enter ships
        enterCar();
        enterBat();
        enterCru();
        enterSub();
        enterDes();

        //Start game
        start();
 
        
        //Prompt exit
        cout <<"Would you like to exit (y/n)?"; 
        string ans;
        cin >> ans;
        if(ans[0] == 'y' || ans[0] == 'Y'){
            quit = true;
        }
        else{
            player->gtBdDef()->clear();
            player->gtBdAtt()->clear();
            
            enemy->gtBdDef()->clear();
            enemy->gtBdAtt()->clear();
        }

    
    }while(!quit);
    
    cls();
    cout <<"Thanks for playing!\n";
}

void Game::start(){
    bool gameover = false;
    string ans;
    char alph1;
    int val1;
    
    //Set enemy board
    enemy->setRand();
    
    //Begin game
    do{
        cls();
        //Output player
        cout <<"Player board\n";
        player->output();
        
        bool valid;
        do{
            valid = true;
            
            //Prompt attack
            cout <<"Enter a target(ex. A0):";
            cin >> ans;

            //Receive input
            alph1 = ans[0];
            val1 = ans[1]-'0';
            
            //Validate input
            int val2 = player->gtBdAtt()->convert(alph1);
            if(val1 < 0 || val1 > 9 ||
                    val2 < 0 || val2 > 9){
                cout << "\nError: Bad range!\n";
                valid = false;
            }
        }while(!valid);
        
        //Set attack and prompt
        if(player->hit(alph1,val1,enemy->gtBdDef())){
            cls();
            cout <<"Target Hit!\n";
            delay(4);
            cls();
        }
        else{
            cls();
            cout <<"Missed!\n";
            delay(4);
            cls();
        }
        
        //Enemy turn
        if(!enemy->isElim()){
            //Enemy attacks random point
            int y1 = rand()%10;
            int x1 = rand()%10;
            
            char alph = enemy->convert(y1);
            if(enemy->hit(alph,x1,player->gtBdDef())){
                cls();
                cout <<"Enemy Hit!\n";
                delay(4);
                cls();
            }
            else{
                cls();
                cout <<"Enemy missed!\n";
                delay(4);
                cls();
            }
            
            if(player->isElim()){
                cls();
                player->output();
                cout <<"You Lose!\n";
                delay(6);
                cls();
                gameover = true;
            }
        }
        else{
            cls();
            cout <<"You Win!\n";
            delay(6);
            cls();
            gameover = true;
        }
       
        
    }while(!gameover);
}

void Game::enterCar(){
    string input1, input2;
    
    bool valid = false;
    
    do{
        cout <<"Enter coordinates for Carrier:(ex. A2) \n";
        cout <<"Start:";
        cin >> input1;
        cout <<"Towards:";
        cin >> input2;
        
        char alph1 = input1[0];
        int val1 = input1[1]-'0';
        
        char alph2 = input2[0];
        int val2 = input2[1]-'0';
        
        valid = player->setCar(alph1, val1, alph2, val2);
        
        if(!valid){
            cls();
            cout <<"Invalid range!\n";
        }
    
    }while(!valid);
}

void Game::enterBat(){
    string input1, input2;
    
    bool valid = false;
    
    do{
        cout <<"Enter coordinates for Battleship:(ex. A2) \n";
        cout <<"Start:";
        cin >> input1;
        cout <<"Towards:";
        cin >> input2;
        
        char alph1 = input1[0];
        int val1 = input1[1]-'0';
        
        char alph2 = input2[0];
        int val2 = input2[1]-'0';
        
        valid = player->setBat(alph1, val1, alph2, val2);
        
        if(!valid){
            cls();
            cout <<"Invalid range!\n";
        }
    
    }while(!valid);

}

void Game::enterCru(){
    string input1, input2;
    
    bool valid = false;
    
    do{
        cout <<"Enter coordinates for Cruiser:(ex. A2) \n";
        cout <<"Start:";
        cin >> input1;
        cout <<"Towards:";
        cin >> input2;
        
        char alph1 = input1[0];
        int val1 = input1[1]-'0';
        
        char alph2 = input2[0];
        int val2 = input2[1]-'0';
        
        valid = player->setCru(alph1, val1, alph2, val2);
        
        if(!valid){
            cls();
            cout <<"Invalid range!\n";
        }
    
    }while(!valid);

}

void Game::enterSub(){
    string input1, input2;
    
    bool valid = false;
    
    do{
        cout <<"Enter coordinates for Submarine:(ex. A2) \n";
        cout <<"Start:";
        cin >> input1;
        cout <<"Towards:";
        cin >> input2;
        
        char alph1 = input1[0];
        int val1 = input1[1]-'0';
        
        char alph2 = input2[0];
        int val2 = input2[1]-'0';
        
        valid = player->setSub(alph1, val1, alph2, val2);
        
        if(!valid){
            cls();
            cout <<"Invalid range!\n";
        }
    
    }while(!valid);

}

void Game::enterDes(){
    string input1, input2;
    
    bool valid = false;
    
    do{
        cout <<"Enter coordinates for Destroyer:(ex. A2) \n";
        cout <<"Start:";
        cin >> input1;
        cout <<"Towards:";
        cin >> input2;
        
        char alph1 = input1[0];
        int val1 = input1[1]-'0';
        
        char alph2 = input2[0];
        int val2 = input2[1]-'0';
        
        valid = player->setDes(alph1, val1, alph2, val2);
        
        if(!valid){
            cls();
            cout <<"Invalid range!\n";
        }
    
    }while(!valid);

}

void Game::delay(int time){
    //Delay screen
    time *= 100000000;
    for(int i = 0; i < time; ++i){}
}

void Game::cls(){
    for(int i = 0; i < 20; ++i){
        cout <<endl;
    }
}