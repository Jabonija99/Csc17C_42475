/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on March 29, 2018, 2:28 PM
 */

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "DblLnkList.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
      
    //Create linked list vector
    LinkedList<int> *lnkList = new LinkedList<int>(0);
    //Add values
    for(int i = 0; i < 10; i++){
        lnkList->addLst(i+1);
    }
    
    //Delete contents
    lnkList->delData(5);
    lnkList->delData(0);
    lnkList->delData(10);
    
    //Insert values
    lnkList->insAft(3,17);
    lnkList->insBef(1,42);
    lnkList->insAft(9,13);
    
    //Add values
    lnkList->addLst(99);
    lnkList->addLst(0);
    lnkList->addLst(10);
    
    
    //Output list
    cout <<"==========Linked List==========================\n"
            <<"Original list: (List max size: " <<lnkList->cntLst() <<")\n";
    lnkList->prntLst();
    
    //Prioritize value
    lnkList->prioritize(99);
    
    //Output list
    cout <<"Priority list: (List max size: " <<lnkList->cntLst() <<")\n";
    lnkList->prntLst();
    
    //Delete list
    delete lnkList;
    
      
    //Create linked list vector
    DblLnkList<int> *lnkList2 = new DblLnkList<int>(0);
    //Add values
    for(int i = 0; i < 10; i++){
        lnkList2->addLst(i+1);
    }
    
    //Delete contents
    lnkList2->delData(5);
    lnkList2->delData(0);
    lnkList2->delData(10);
    
    //Insert values
    lnkList2->insAft(3,17);
    lnkList2->insBef(1,42);
    lnkList2->insAft(9,13);
    
    //Add values
    lnkList2->addLst(99);
    lnkList2->addLst(0);
    lnkList2->addLst(10);
    
    //Output double list
    cout <<"==========Double Linked List=======================\n"
            <<"Original list: (List max size: " <<lnkList2->cntLst() <<")\n";
    lnkList2->prntLst();
    
    //Prioritize values
    lnkList2->prioritize(42);
    lnkList2->prioritize(17);
    
    //Output priority list
    cout <<"Priority list: (List max size: " <<lnkList2->cntLst() <<")\n";
    lnkList2->prntLst();
    
    //Delete double linked list
    delete lnkList2;
    
    return 0;
}

