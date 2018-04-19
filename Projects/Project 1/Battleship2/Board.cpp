/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: K99
 * 
 * Created on April 16, 2018, 5:41 PM
 */

#include "Board.h"
#include <cstdlib>

Board::Board() {
    srand(time(0));
    
    ships = new string[5];
    ships[0] = "C"; //Carrier size 5
    ships[1] = "B"; //Battle size 4
    ships[2] = "R"; //Cruiser size 3
    ships[3] = "S"; //Submarine size 3
    ships[4] = "D"; //Submarine size 2
    
    boardAtt = new Grid(10,10);
    boardDef = new Grid(10,10);
}

Board::~Board() {
    delete boardAtt;
    delete boardDef;
    //delete ships;
}

bool Board::setCar(char alph1, int val1, char alph2, int val2){
    bool valid = true;
    
    int size = 5-1;
    
    valid = setShip(alph1, val1, alph2, val2, ships[0], size);
    
    return valid;
}

bool Board::setBat(char alph1, int val1, char alph2, int val2){
    bool valid = true;
    
    int size = 4-1;
    
    valid = setShip(alph1, val1, alph2, val2, ships[1], size);
    
    return valid;
}

bool Board::setCru(char alph1, int val1, char alph2, int val2){
    bool valid = true;
    
    int size = 3-1;
    
    valid = setShip(alph1, val1, alph2, val2, ships[2], size);
    
    return valid;
}

bool Board::setSub(char alph1, int val1, char alph2, int val2){
    bool valid = true;
    
    int size = 3-1;
    
    valid = setShip(alph1, val1, alph2, val2, ships[3], size);
    
    return valid;
}

bool Board::setDes(char alph1, int val1, char alph2, int val2){
    bool valid = true;
    
    int size = 2-1;
    
    valid = setShip(alph1, val1, alph2, val2, ships[4], size);
    
    
    return valid;
}

bool Board::setShip(char alph1, int val1, char alph2, 
        int val2, string ship, int size){
    
    bool valid = true;
    
    int y1 = boardDef->convert(alph1);
    int x1 = val1;
    
    int y2 = boardDef->convert(alph2);
    int x2 = val2;
    
    
    try{
        
        if(y1 < 0 || y1 > 9){
            throw -1;
        }
        if(y2 < 0 || y2 > 9){
            throw -1;
        }
        if(x1 < 0 || x1 > 9){
            throw -1;
        }
        if(x2 < 0 || x2 > 9){
            throw -1;
        }
        
        
        if(y1 == y2){
            if(x1 > x2){
                int d = val2+size;
                
                if(d > 9){
                    int d2 = d-9;
                    d=val2-d2;
                }
                else{
                    d=val2;
                }
                valid = boardDef->insFrom(alph1, d+size, alph2, d, ship);
            }
            else{
                int d = val1+size;
                
                if(d > 9){
                    int d2 = d-9;
                    d=val1-d2;
                }
                else{
                    d=val1;
                }
                valid = boardDef->insFrom(alph1, d, alph2, d+size, ship);
            }
            
        }
        else if(x1 == x2){
            if(y1 > y2){
                int d = y2+size;
                
                if(d > 9){
                    int d2 = d-9;
                    d=y2-d2;
                }
                else{
                    d=y2;
                }
                
                valid = boardDef->insFrom(d+size, x1, d, x2, ship);
            }
            else{
                int d = y1+size;
                
                if(d > 9){
                    int d2 = d-9;
                    d=y1-d2;
                }
                else{
                    d=y1;
                }
                valid = boardDef->insFrom(d, x1, d+size, x2, ship);
            }
            
            
        }
        else{
            throw -1;
        }
        
    }
    catch(...){
        valid = false;
    }
    
    return valid;
}

bool Board::setRand(){
    srand(time(0));
    
    bool valid = true;
    
    //Random coordinates
    int y1,x1,y2,x2;
    
    char alph1;
    char alph2;
    
    try{
        bool accepted = false;
        
        //Set carrier
        while(!accepted){
            //Get rand values
            y1 = rand()%10;
            x1 = rand()%10;
            y2 = rand()%10;
            x2 = rand()%10;

            alph1 = convert(y1);
            alph2 = convert(y2);
            
            
            //Set carrier
            accepted = setCar(alph1, x1, alph2, x2);
        }
        
        //Set Battleship
        accepted = false;
        while(!accepted){
            //Get rand values
            y1 = rand()%10;
            x1 = rand()%10;
            y2 = rand()%10;
            x2 = rand()%10;

            alph1 = convert(y1);
            alph2 = convert(y2);
            
            
            //Set battleship
            accepted = setBat(alph1, x1, alph2, x2);
        }
        
        
        //Set Cruiser
        accepted = false;
        while(!accepted){
            //Get rand values
            y1 = rand()%10;
            x1 = rand()%10;
            y2 = rand()%10;
            x2 = rand()%10;

            alph1 = convert(y1);
            alph2 = convert(y2);
            
            //Set cruiser
            accepted = setCru(alph1, x1, alph2, x2);
        }
        
        //Set submarine
        accepted = false;
        while(!accepted){
            //Get rand values
            y1 = rand()%10;
            x1 = rand()%10;
            y2 = rand()%10;
            x2 = rand()%10;

            alph1 = convert(y1);
            alph2 = convert(y2);
            
            //Set submarine
            accepted = setSub(alph1, x1, alph2, x2);
        }
        
        //Set destroyer
        accepted = false;
        while(!accepted){
            //Get rand values
            y1 = rand()%10;
            x1 = rand()%10;
            y2 = rand()%10;
            x2 = rand()%10;

            alph1 = convert(y1);
            alph2 = convert(y2);
            
            //Set destroyer
            accepted = setDes(alph1, x1, alph2, x2);
        }
    }
    catch(...){
        valid = false;
    }
    
    return valid;
}


bool Board::hit(char alph,int val){
    bool detected = false;
    if(boardAtt->isFilled(alph, val)){
        boardAtt->insAt(alph,val,"X");
        detected = true;
    }
    else{
        boardAtt->insAt(alph,val,"O");
    }
    
    return detected;
}

bool Board::hit(char alph, int val, Grid* enemy){
    bool detected = false;
    if(enemy->isFilled(alph, val)){
        boardAtt->insAt(alph,val,"X");
        enemy->insAt(alph,val,"X");
        detected = true;
    }
    else{
        boardAtt->insAt(alph,val,"O");
        enemy->insAt(alph,val,"O");
    }
    
    return detected;
}

void Board::isHit(char alph, int val){
    if(boardDef->isFilled(alph,val)){
        boardDef->insAt(alph,val, "X");
    }
    else{
        boardDef->insAt(alph, val, "O");
    }

}

string Board::gtAttAt(char alph, int val){
    return boardAtt->getAt(alph, val);
}

string Board::gtDefAt(char alph, int val){
    return boardDef->getAt(alph, val);
}


bool Board::isElim(){
    //Checks to see if any ships remain
    bool check = false;
    
    if(boardDef->isEmpty()){
        check = true;
    }
    
    return check;
}

void Board::output(){
    cout <<"=============Enemy================" <<endl;
    boardAtt->output();
    cout <<"==================================" <<endl
            <<"===============Ships=============="<<endl;
    boardDef->output();
    cout <<"==================================" <<endl;
}

char Board::convert(int val){
    if(val == 0){
        return 'a';
    }
    else if(val == 1){
        return 'b';
    }
    else if(val == 2){
        return 'c';
    }
    else if(val == 3){
        return 'd';
    }
    else if(val == 4){
        return 'e';
    }
    else if(val == 5){
        return 'f';
    }
    else if(val == 6){
        return 'g';
    }
    else if(val == 7){
        return 'h';
    }
    else if(val == 8){
        return 'i';
    }
    else if(val == 9){
        return 'j';
    }
    else{
        return 'z';
    }
}