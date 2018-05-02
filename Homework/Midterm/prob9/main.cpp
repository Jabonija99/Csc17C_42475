/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

/*
 * Problem 9: Vector probability
 */
int main(int argc, char** argv) {
    //Possible vectors
    vector<int> vec1 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec2 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec3 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec4 = {0,1,2,3,4,5,6,7,8,9};
    vector<int> vec5 = {0,1,2,3,4,5,6,7,8,9};
    
    int total = 0;
    int event = 0;
    
    //Iterate through each combination of vectors
    for(vector<int>::iterator itr1 = vec1.begin();
            itr1 != vec1.end(); itr1++){
        for(vector<int>::iterator itr2 = vec2.begin();
                itr2 != vec2.end(); itr2++){
            for(vector<int>::iterator itr3 = vec3.begin();
                    itr3 != vec3.end(); itr3++){
                for(vector<int>::iterator itr4 = vec4.begin();
                        itr4 != vec4.end(); itr4++){
                    for(vector<int>::iterator itr5 = vec5.begin();
                            itr5 != vec5.end(); itr5++){
                           
                        
                        //If value is in range(0~2)
                        if(*itr1 < 3 && *itr1 > -1){
                            if(*itr2 < 3 && *itr2 > -1){
                                if(*itr3 < 3 && *itr3 > -1){
                                    if(*itr4 < 3 && *itr4 > -1){
                                        if(*itr5 < 3 && *itr5 > -1){
                                            //Increment event of filled
                                            event++;
                                        }
                                    }
                                }
                            }
                        }
                        //Increment total events
                        total++;
                        
                    }
                }
            }
        }
    }
        
    //Output results
    float chance = static_cast<float>(event) / total;
    cout <<"Total probabilities: " <<total <<endl
            <<"Chances of filled vector: "<<event <<endl;
    cout <<"Percent: " <<chance*100 <<"%" <<endl;
    

    
    return 0;
}

