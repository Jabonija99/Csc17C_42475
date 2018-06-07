/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.cpp
 * Author: K99
 * 
 * Created on April 16, 2018, 5:09 PM
 */

#include "Grid.h"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>

Grid::Grid(){
    length = 10;
    width = 10;
    
    
    //Resize grid to length
    grid.resize(length);
    
    //Create vector
    for(vector<vector<string>>::iterator row = grid.begin();
            row != grid.end(); ++row){
        
        *row = vector<string>(width);
        for(vector<string>::iterator col = row->begin();
                col != row->end(); ++col){
            
            //Set blocks
            *col = "[ ]";
        }
    }
}

Grid::Grid(int l, int w) {
    //Check length and width
    if(l > 0 && w > 0){
        //Set Length and width
        length = l;
        width = w;
        
        //Resize grid to length
        grid.resize(length);

        //Create vector
        for(vector<vector<string>>::iterator row = grid.begin();
                row != grid.end(); ++row){

            *row = vector<string>(width);
            for(vector<string>::iterator col = row->begin();
                    col != row->end(); ++col){

                //Set blocks
                *col = "[ ]";
            }
        }
    }
    else{
        //Default length and width
        length = 0;
        width = 0;
    }
    
}

Grid::~Grid() {
    
}

void Grid::insAt(char alph, int val, string letter){
    int y = convert(alph);
    int x = val;
    
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < width; ++j){
            if(i == y && j == x){
                grid[i][j] = "[" +letter +"]";
            }
        }
    }
}

void Grid::insAt(int y, int x, string letter){
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < width; ++j){
            if(i == y && j == x){
                grid[i][j] = "[" +letter +"]";
            }
        }
    }
}

bool Grid::insFrom(char alph1, int val1, char alph2, int val2, string letter){
    bool valid = true;
    
    int y1 = convert(alph1);
    int x1 = val1;
    
    int y2 = convert(alph2);
    int x2 = val2;
    
    try{
        if(y1 == y2){
            if(x1 < x2){
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(i == y1 && j >= x1 && j <= x2){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(i == y1 && j >= x2 && j <= x1){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
        }
        else if(x1 == x2){
            if(y1 < y2){
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(j == x1 && i >= y1 && i <= y2){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(j == x1 && i >= y2 && i <= y1){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
        }
        else{
            throw -1;
        }
    }
    catch(...){
        cout <<"Error: "<<letter <<" has invalid range!\n";
        valid = false;
    }
    
    return valid;
}

bool Grid::insFrom(int y1, int x1, int y2, int x2, string letter){
    bool valid = true;
    
    try{
        if(y1 == y2){
             if(x1 < x2){
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(i == y1 && j >= x1 && j <= x2){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(i == y1 && j >= x2 && j <= x1){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
        }
        else if(x1 == x2){
            if(y1 < y2){
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(j == x1 && i >= y1 && i <= y2){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
            else{
                for(int i = 0; i < length; ++i){
                    for(int j = 0; j < width; ++j){
                        if(j == x1 && i >= y2 && i <= y1){
                            if(!isFilled(i,j)){
                                grid[i][j] = "[" +letter +"]";
                            }
                            else{
                                throw -1;
                            }
                        }
                    }
                }
            }
        }
        else{
            throw -1;
        }
    }
    catch(...){
        cout <<"Error: "<<letter <<" has invalid range!\n";
        valid = false;
    }
    
    return valid;
}

bool Grid::isFilled(char alph, int val){
    bool filled = false;
    
    int y = convert(alph);
    int x = val;
    
    for(int i = 0 ; i < length; ++i){
        for(int j = 0 ; j < width; ++j){
            if(grid[y][x] != "[ ]" && grid[y][x] != "[X]"
                    && grid[y][x] != "[O]" ){
                filled = true;
            }
        }
    }
    
    return filled;
}

bool Grid::isFilled(int y, int x){
    bool filled = false;
    
    
    if(grid[y][x] != "[ ]" && grid[y][x] != "[X]"
                    && grid[y][x] != "[O]" ){
        filled = true;
    }
       
    
    return filled;

}

string Grid::getAt(char alph, int val){
    string letter = "[ ]";
    
    int y = convert(alph);
    int x = val-1;
    
    for(int i = 0; i < length; ++i){
        for(int j = 0; j < width; ++j){
            if(i == y && j == x){
                letter = grid[i][j];
            }
        }
    }
    
    return letter;
}

void Grid::output(){
    //Create Alphabetical index
    string alph[length] = {" A]", " B]", " C]", " D]",
                        " E]", " F]", " G]", " H]", " I]", " J]"};
    
    
    //Output numeric index
    for(int i = 0; i < length; i++){
        if(i < 1){
            for(int j = 0; j < width+1; j++){
                if(j>0){
                    cout <<"[" <<j-1 <<"]";
                }
                else{
                    cout <<"[ ]";
                }
            }
            cout <<endl;
        }
    }
    
    //Output grid
    int i = 0;
    for(vector<vector<string>>::iterator itr = grid.begin();
            itr != grid.end(); ++itr){
        
        //Output alpha index
        cout <<alph[i];
        
        //Output data
        for(vector<string>::iterator itr2 = itr->begin();
                itr2 != itr->end(); ++itr2){
            cout <<*itr2;
        }
        cout <<endl;
        ++i;
    }
    

}

void Grid::clear(){
    //Set blocks
    for(int i = 0; i < length; ++i){
        for(int j = 0 ; j < width; ++j){
            grid[i][j] = "[ ]";
        }
    }
}

bool Grid::isEmpty(){
    bool empty = true;
    for(int i = 0; i < length; ++i){
        for(int j = 0 ; j < width; ++j){
            if(grid[i][j] != "[ ]" && 
                    grid[i][j] !="[X]" && grid[i][j] != "[O]"){
                empty = false;
            }
        }
    }
    
    return empty;
}

int Grid::convert(char alph){
    if(alph == 'A' || alph == 'a'){
        return 0;
    }
    else if(alph == 'B' || alph == 'b'){
        return 1;
    }
    else if(alph == 'C' || alph == 'c'){
        return 2;
    }
    else if(alph == 'D' || alph == 'd'){
        return 3;
    }
    else if(alph == 'E' || alph == 'e'){
        return 4;
    }
    else if(alph == 'F' || alph == 'f'){
        return 5;
    }
    else if(alph == 'G' || alph == 'g'){
        return 6;
    }
    else if(alph == 'H' || alph == 'h'){
        return 7;
    }
    else if(alph == 'I' || alph == 'i'){
        return 8;
    }
    else if(alph == 'J' || alph == 'j'){
        return 9;
    }
    else{
        return -1;
    }
}
