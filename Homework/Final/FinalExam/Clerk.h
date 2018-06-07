/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clerk.h
 * Author: K99
 *
 * Created on June 4, 2018, 9:10 PM
 */

#ifndef CLERK_H
#define CLERK_H

#include <cstdlib>
#include <ctime>

class Clerk {
public:
    Clerk();
    Clerk(float);
    ~Clerk();
    
    void startTime();
    void setDur(float);
    bool update();
    
    void setTime(float);
    float getDur(){return duration;}
    float getTime(){return time;}
    
    bool isRunning(){return running;}
    
private:
    clock_t start;
    float time, duration;
    bool running;

};

#endif /* CLERK_H */

