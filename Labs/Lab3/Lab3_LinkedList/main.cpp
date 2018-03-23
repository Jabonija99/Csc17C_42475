/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on March 22, 2018, 4:58 PM
 */

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "SimpleVector.h"

using namespace std;

/*
 * 
 */

void output(SimpleVector<int>);

int main(int argc, char** argv) {
    
    //Create linked list vector
    LinkedList<int> *lnkList = new LinkedList<int>(0);
    //Add values
    for(int i = 0; i < 10; i++){
        lnkList->addLst(i+1);
    }
    cout <<"==========Linked List==========================\n"
            <<"Original list: (List max size: " <<lnkList->cntLst() <<")\n";
    lnkList->prntLst();

    
    //Delete contents
    lnkList->delData(5);
    lnkList->delData(0);
    lnkList->delData(10);
    
    
    //Output new list
    cout <<"Deleted 0 ,5, 10 from list: (List max size: " 
            <<lnkList->cntLst() <<")\n";
    lnkList->prntLst();
    
    //Insert values
    lnkList->insAft(3,21);
    lnkList->insBef(1,17);
    lnkList->insAft(9,42);
    
    cout <<"Inserted list: (List max size: " <<lnkList->cntLst() <<")\n";
    lnkList->prntLst();
    
    delete lnkList;
    
    
    
    //Create simple vector
    SimpleVector<int> *vector = new SimpleVector<int>(0,10);
    
    //Push values 
    for(int i = 1; i < 11; i++){
        vector->push(i);
    }
    
    //Output the vector
    cout <<"=========Simple Vector=========================\n"
            ""<<"Original vector: (Array Max Size: " <<vector->maxSz() <<")\n"; 
    vector->prntLst();
    
    //Delete contents
    vector->delData(0);
    vector->delData(7);
    vector->delData(10);
    
    //Output new vector
    cout <<"Deleted 0 ,7, 10 from list: (Array max size: " 
            <<vector->maxSz() <<")\n";
    vector->prntLst();
    
    //Insert values
    vector->insBef(1,87);
    vector->insAft(9,23);
    vector->insBef(4,55);
    
    cout <<"\nInserted vector: (Array Max Size: " <<vector->maxSz() <<")\n";
    vector->prntLst();

    delete vector;
    
    return 0;
}

void output(SimpleVector<int> v){
    //Output vector
    for(int i = 0; i < v.size(); i++){
        cout <<i <<": " <<v.getElementAt(i) <<endl;
    }
}