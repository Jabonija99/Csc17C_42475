/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on April 21, 2018, 8:01 PM
 */

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> filled = {0,1,2};
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    
    int total = 0;
    
    for(vector<int>::iterator itr = vec.begin();
            itr != vec.end(); itr++){
        for(vector<int>::iterator itr2 = filled.begin();
                itr2 != filled.end(); itr2++){
            if(*itr == *itr2){
            
            }
        }
    }
    
    
    return 0;
}

