/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on May 24, 2018, 12:08 AM
 */

#include <cstdlib>
#include <iostream>
#include "Tree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    srand(time(0));
    
    //Generate random values
    int size = 10;
    int ary[size];
    for(int i = 0 ; i < size; i++){
        ary[i] = rand()%20;
    }
    
    //Create tree
    Tree bintree(ary[0]);
    
    //Insert values
    for(int i = 1; i < size; i++){
        bintree.insert(ary[i]);
    }
    
    //Output data
    cout <<"Data: ";
    for(int i = 0; i < size; i++){
        cout <<ary[i] <<" ";
    }
    cout <<endl;
    
    //Output tree
    cout <<"\nBefore deletion:\n";
    bintree.outPst();
    bintree.outIn();
    bintree.outPre();
    bintree.outLvl();
    
    
    //Delete from tree
    int num1 = ary[3];
    int num2 = ary[4];
    cout <<"\n\nDeleting: " <<num1 <<" " <<num2 <<endl;
    bintree.delData(num1);
    bintree.delData(num2);
    
    //Output results
    cout <<"\nAfter deletion:\n";
    bintree.outPst();
    bintree.outIn();
    bintree.outPre();
    bintree.outLvl();

    return 0;
}

