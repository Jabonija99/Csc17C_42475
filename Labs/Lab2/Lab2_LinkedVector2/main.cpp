/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on March 18, 2018, 4:29 PM
 */

#include <cstdlib>
#include <iostream>

#include "LinkedVector.h"
#include "LinkTest.h"

using namespace std;

/*
 * 
 */


void output(LinkedVector<int>);
void fill(LinkTest<int>*,int);

int main(int argc, char** argv) {
    /*
    //Create simple vector
    LinkedVector<int> v(10);
    
    //Output the vector
    cout <<"Original vector: (Array Max Size: " <<v.maxSz() <<")\n"; 
    output(v);
    
    
    //"Push" a value and output vector
    int num = 12;
    v.push(num);
    cout <<"\nPush vector: (Array Max Size: " <<v.maxSz() <<")\n";
    output(v);
    */
    
    int size=10;
    
    //Create linked list vector
    LinkTest<int> *lnkList = new LinkTest<int>(0,size);
    cout <<"Original list: (List max size: " <<lnkList->maxSz() <<")\n";
    lnkList->prntLst();

    //Pushing 10 values into link
    fill(lnkList,10);
    
    cout <<"Pushed list: (List max size: " <<lnkList->maxSz() <<")\n";
    lnkList->prntLst();
    
    delete lnkList;
    return 0;
}


void output(LinkedVector<int> v){
    //Output vector
    for(int i = 0; i < v.size(); i++){
        cout <<i <<": " <<v.getElementAt(i) <<endl;
    }
}

void fill(LinkTest<int> *ptr, int size){
    for(int i = 0; i < size; i++){
        ptr->push(i+1);
    }
}
