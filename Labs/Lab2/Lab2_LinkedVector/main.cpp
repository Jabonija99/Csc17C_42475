/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on March 19, 2018, 11:31 PM
 */

#include <cstdlib>
#include <iostream>

#include "LinkedVector.h"

using namespace std;

/*
 * 
 */
void fill(LinkedVector<int>*,int);


int main(int argc, char** argv) {
    //Size of link vector
    int size=10;
    
    //Create linked list vector
    LinkedVector<int> *lnkList = new LinkedVector<int>(0,size);
    cout <<"Original list: (List max size: " <<lnkList->maxSz() <<")\n";
    lnkList->prntLst();

    //Pushing 10 values into link
    fill(lnkList,10);
    
    cout <<"Pushed list: (List max size: " <<lnkList->maxSz() <<")\n";
    lnkList->prntLst();
    
    delete lnkList;

    return 0;
}

void fill(LinkedVector<int> *ptr, int size){
    for(int i = 0; i < size; i++){
        ptr->push(i+1);
    }
}