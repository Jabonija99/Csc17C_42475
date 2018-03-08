/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 7, 2018, 7:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"

using namespace std;

/*
 * 
 */

void output(SimpleVector<int>);

int main(int argc, char** argv) {
    SimpleVector<int> vector(10);
    
    cout <<"Original vector:\n";
    output(vector);
    
    cout <<"\nPush vector:\n";
    int num = 1;
    vector.push(num);
    output(vector);
            
    

    return 0;
}



void output(SimpleVector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout <<v.getElementAt(i) <<endl;
    }
}