/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on April 21, 2018, 5:43 PM
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
    
    vector<int> dice1 = {1,2,3,4,5,6};
    vector<int> dice2 = {1,2,3,4,5,6};
    vector<int> dice3 = {1,2,3,4,5,6};
    vector<int> dice4 = {1,2,3,4,5,6};
    
    int total = 0;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int p4 = 0;
    
    //Iterator through all dice
    for(vector<int>::iterator itr = dice1.begin();
            itr != dice1.end(); itr++){
        for(vector<int>::iterator itr2 = dice2.begin();
                itr2 != dice2.end(); itr2++){
            for(vector<int>::iterator itr3 = dice3.begin();
                    itr3 != dice3.end(); itr3++){
                for(vector<int>::iterator itr4 = dice4.begin();
                        itr4 != dice4.end(); itr4++){
                    
                    //Calc probability of 4 pair
                    if(*itr == *itr2 && *itr == *itr3 && *itr == *itr4){
                        p4++;
                    }
                    
                    //Calc probability of 3 pair
                    if(*itr == *itr2 && *itr == *itr3 && *itr != *itr4){
                        p3++;
                    }
                    
                    //Calc probability of 2 pair
                    if(*itr == *itr2 && *itr != *itr3 && *itr3 == *itr4){
                        p2++;
                    }
                   
                    //Calc probability of 1 pair
                    if(*itr == *itr2 && *itr != *itr3 && 
                            *itr != *itr4 && *itr3 != *itr4){
                        p1++;
                    }
                    
                    
                    //Calculate total
                    total++;
                }
            }
        }
    }
    
    //Calculate percents
    float chancep1 = static_cast<float>(p1)/total;
    float chancep2 = static_cast<float>(p2)/total;
    float chancep3 = static_cast<float>(p3)/total;
    float chancep4 = static_cast<float>(p4)/total;
    
    
    //Output results
    cout <<"Total probability:  " <<total <<endl;
    cout <<"P(1 pair):          " <<p1 <<" or " << chancep1*100 <<"%" <<endl;
    cout <<"P(2 pair):          " <<p2 <<" or " << chancep2*100 <<"%" <<endl;
    cout <<"P(3 of a kind):     " <<p3 <<" or " << chancep3*100 <<"%" <<endl;
    cout <<"P(4 of a kind):     " <<p4 <<" or " << chancep4*100 <<"%" <<endl;
    
    
    return 0;
}

