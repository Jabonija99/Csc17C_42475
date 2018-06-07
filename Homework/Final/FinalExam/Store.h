/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Store.h
 * Author: K99
 *
 * Created on June 4, 2018, 9:44 PM
 */

#ifndef STORE_H
#define STORE_H


#include <cstdlib>
#include <ctime>
#include <queue>
#include "Clerk.h"

class Store {
public:
    Store();
    Store(float);
    ~Store();
    
    void init();
    void setTime(float);
    
private:
    clock_t start;
    float duration, time;
    
    Clerk* clerks;
    std::queue<int> line;
    
};

#endif /* STORE_H */

