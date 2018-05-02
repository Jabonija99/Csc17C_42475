/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Problem 10: Power function
 *
 */

int power(int,unsigned int);

int main(int argc, char** argv) {
    int num = 2, pow = 4;
    
    int res = power(num,pow);
    
    cout <<res <<endl;
    
    
    return 0;
}

int power(int base,unsigned int exp){
    if(exp==0){
        //If exp = 0
        return 1;
    }
    else if(exp%2 == 0){
        //If exp is even
        int ans = power(base, exp/2);
        return ans*ans;
    }
    else{
        //If exp is odd
        return base*(power(base, exp-1));
    }
}