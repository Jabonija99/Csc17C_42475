/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GenStringFunct.cpp
 * Author: K99
 * 
 * Created on June 2, 2018, 5:27 PM
 */

#include "GenStringFunct.h"


std::string genString(int size){
    //Create string
    std::string result = "";
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    //"abcdefghijklmnopqrstuvwxyz";
    char *s = new char[size];
    
    //Generate string
    for(int i = 0; i < size; ++i){
        s[i] = alph[rand()%(sizeof(alph)-1)];
    }
    s[size] = 0;
    
    //Record result
    for(int i = 0; i < size; ++i){
        result +=s[i];
    }
    
    //Delete char arr
    delete[] s;

    //Return result
    return result;
}

