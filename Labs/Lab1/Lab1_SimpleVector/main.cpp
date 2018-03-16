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
    //Create simple vector
    SimpleVector<int> v(10);
    
    //Output the vector
    cout <<"Original vector: (Array Max Size: " <<v.maxSz() <<")\n"; 
    output(v);
    
    
    //"Push" a value and output vector
    int num = 12;
    v.push(num);
    cout <<"\nPush vector: (Array Max Size: " <<v.maxSz() <<")\n";
    output(v);
    

    return 0;
}



void output(SimpleVector<int> v){
    //Output vector
    for(int i = 0; i < v.size(); i++){
        cout <<i <<": " <<v.getElementAt(i) <<endl;
    }
}