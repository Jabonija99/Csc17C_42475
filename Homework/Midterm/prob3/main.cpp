/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include "LinkedVector.h"   //Linked vector
#include "SimpleVector(1).h" //Simple vector
#include "SimpleVecOpt.h" //Optimized vector


using namespace std;

/*
 * Problem 3: Simple vector, Optimized simple vector, Linked vector
 */


int main(int argc, char** argv) {
    int beg, end;
    
    //Create data
    //SimpleVector<int> vSimp;    //Simple vector
    SimpleVecOpt<int> vOptm;    //Optimized vector
    //LinkedVector<int> vLink;    //Linked vector
    
    int mod = 10000;
    int size = 1*mod;
    
    cout <<"Given size of " <<size <<":\n\n";
    
    beg = time(0);
    for(int i = 0; i < size/mod; i++){
        //vSimp.push(i);
    }
    end = time(0);
    
    cout <<"Simple Vector push time: " <<end-beg <<endl<<endl;
    
    beg = time(0);
    for(int i = 0; i < size; i++){
        vOptm.push(i);
    }
    end = time(0);
    
    cout <<"Optimized Vector push time: " <<end-beg <<endl<<endl;
    
    beg = time(0);
    for(int i = 0; i < size/mod; i++){
        //vLink.push(i);
    }
    end = time(0);
    
    cout <<"Linked Vector push time: " <<end-beg <<endl<<endl;
    
    return 0;
}

