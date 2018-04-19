/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.h
 * Author: K99
 *
 * Created on April 16, 2018, 5:09 PM
 */

#ifndef GRID_H
#define GRID_H


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Grid {
    
public:
    Grid();
    Grid(int, int);
    ~Grid();
    
    void insAt(char, int, string);  //Grid Insert
    void insAt(int, int, string);   //Exact Insert
    bool insFrom(char, int, char, int, string); //Grid  ranged insert
    bool insFrom(int,int,int,int, string);      //Exact ranged insert
    
    string  getAt(char, int);
    
    bool isFilled(char, int);   //Grid check
    bool isFilled(int, int);     //Exact check
    
    int getL(){return length;}
    int getW(){return width;}
    
    void output();
    void clear();
    bool isEmpty();
    
    int convert(char);
    
private:
    unsigned short int length, width;
    string **grid;
    

};

#endif /* GRID_H */

