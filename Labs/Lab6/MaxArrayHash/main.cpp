/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 2, 2018, 7:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;


/*
 * 
 */

void hashed(int*, int, bool&);
void output(int*, int);
bool check(int*,int);

int main(int argc, char** argv) {
    srand(time(0));
    
    //Init size
    int xMin = 10;
    int xMax = 25;
    int n;
    int *arr;
    bool first;
    
    //Loop from power 10 -> 25
    while(xMin<=xMax){
        n = pow(2,xMin);
        arr = new int[n];
        first = true;
       
        cout <<"For power: " <<xMin <<endl;
        
        //Fill array with zero
        for(int i = 0 ; i < n; i++){
            arr[i] = 0;
        }
        
        //Hash 100 objects
        for(int i = 0; i < n; i++){
            hashed(arr,n,first);
        }
    
        
        output(arr,n);
        cout <<endl;

        delete arr;
        xMin++;
    }
    
    return 0;
}


void hashed(int* a, int n, bool&first){
    int index = rand()%n;
    
    if(check(a, index) && first){
        cout <<"First collision for index: " <<index <<endl;
        first = false;
    }
    
    a[index]++;
}

void output(int* a, int size){
    int max = 0;
    for(int i = 0 ; i < size; i++){
        if(a[i] > max)
            max = a[i];
    }
    cout <<"Max collisions: " <<max <<endl;
}

bool check(int *a, int index){
    bool collide = false;
    if(a[index] == 0 ){
        collide = true;
    }
        
    return collide;    
}