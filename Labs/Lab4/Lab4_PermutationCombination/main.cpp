/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on March 28, 2018, 10:08 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


float nPrm(int,int); //Permutations repeatable
float nPm(int,int);  //Permutations non-repeatable
float nCrm(int,int); //Combination repeatable
float nCm(int,int);  //Combination non-repeatable
long int fact(long int); //Factorial 


/*
 * 
 */
int main(int argc, char** argv){
    //Init variables for permutations and combinations
    float pRep, pNonrep, cRep, cNonrep;
    
    int n = 5, m = 3;
    
    //Compute permutations
    pRep = nPrm(n,m);
    pNonrep = nPm(n,m);
    
    //Compute combinations
    cRep = nCrm(n,m);
    cNonrep = nCm(n,m);
    
    //Output results
    cout <<"When N = " <<n  <<" and M = " <<m <<endl;
    cout <<"Repeatable permutations: " <<pRep <<endl; 
    cout <<"Non-repeatable permutations: " <<pNonrep <<endl;
    cout <<"Repeatable combinations: " <<cRep <<endl;
    cout <<"Non-repeatable combinations: " <<cNonrep <<endl;


    return 0;
}

float nPrm(int n, int m){
    //Init answer
    float ans = 0.0;
    
    //If number of permutations is greater than 0
    if(n > 0){
        //Set answer to one
        ans = 1.0;
        
        //Multiply for each repeat
        for(int i=0; i < m; i ++){
            ans *= static_cast<float>(n);
        }
    }

    //Return answer
    return ans;
}

float nPm(int n, int m){
    //Init answer
    float ans = 0.0;
    
    //If number of permutations is greater than 0
    if(n > 0){
        //Compute permutations
        ans = static_cast<float>(fact(n)/fact(n-m));
        
    }
    
    //Return answer
    return ans;
}

float nCrm(int n, int m){
    //init ans
    float ans = 0.0;
    
    //If number of combinations is greater than 0
    if (n > 0){
        //Compute combinations
        ans = static_cast<float>(fact(m+n-1)/(fact(m)*fact(n-1)));
    }
    
    //Return answer
    return ans;
}

float nCm(int n, int m){
    //Init answer
    float ans = 0.0;
    
    //If number of combinations is greater than 0
    if(n > 0){
        //Compute combinations
        ans = static_cast<float>(fact(n)/(fact(m)*fact(n-m)));
    }
    
    //return answer
    return ans;
}



long int fact(long int n){
    //Compute factorial through recursion
    if(n>1)
        return n*fact(n-1);
    else
        return 1;
}