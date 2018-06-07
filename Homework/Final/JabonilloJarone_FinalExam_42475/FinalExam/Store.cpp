/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Store.cpp
 * Author: K99
 * 
 * Created on June 4, 2018, 9:44 PM
 */

#include "Store.h"

using namespace std;

Store::Store() {
    time = 0;
    clerks = new Clerk[10];
}


Store::Store(float time){
    this->time = time;
    clerks = new Clerk[10];
}

Store::~Store() {
    delete clerks;
}

void Store::init(){
    start = clock();
    duration = (clock() - start)/ (float) CLOCKS_PER_SEC;
    
    while(duration < time){
        int dur = duration;
        if(dur%4 == 0){
            line.push(1);
        }
        
        
        duration = (clock() - start)/ (float) CLOCKS_PER_SEC;
    }
}

void Store::setTime(float time){
    this->time = time;
}