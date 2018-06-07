/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clerk.cpp
 * Author: K99
 * 
 * Created on June 4, 2018, 9:10 PM
 */

#include "Clerk.h"
#include <cstdlib>

using namespace std;

Clerk::Clerk() {
    start = clock();
    time = 0;
    duration = 0;
    running = true;
}

Clerk::Clerk(float time){
    start = clock();
    this->time = time;
    duration = 0;
    running = true;
}

Clerk::~Clerk() {
    
}

void Clerk::startTime(){
    start = clock();
    running = true;
    //duration = (clock() - start)/ (float) CLOCKS_PER_SEC;
    
    
    /*
    clock_t start;
    double dur;
    
    start = clock();
    dur = (clock() - start)/ (double) CLOCKS_PER_SEC;
    
    while(dur < time){
        dur = (clock() - start)/ (double) CLOCKS_PER_SEC;
        running = true;
    }
    this->duration = dur;
    
    running = false;
    */
}

void Clerk::setDur(float dur){
    duration = dur;
    if(duration < time){
        running = true; 
    }
    else{
        running = false;
    }
}

bool Clerk::update(){
    float dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    setDur(dur);
    
    if(this->isRunning()){
        return true;
    }
    return false;
}

void Clerk::setTime(float time){
    if(time > 0)
        this->time = time;
}
