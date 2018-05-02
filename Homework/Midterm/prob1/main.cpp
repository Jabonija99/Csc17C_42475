/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <cstdlib>
#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <algorithm>


using namespace std;

/*
 * Problem 1: Linear vs Binary search
 */

int linFnd(vector<int>,int);    //linear search
int binFnd(vector<int>, int);   //binary search

int main(int argc, char** argv) {
    int beg, end;
    vector<int> linear;
    int mod = 10000000;
    int size = 20*mod;
    //int size = 400;
    
    cout <<"Given vector size " <<size <<":\n";
    
    for(int i = 0 ; i < size; i++){
        linear.push_back(i);
    }
    
    //Linear search
    beg = time(0);
    int val = linFnd(linear,size-1);
    end = time(0);
    
    if(val != -1){
        cout <<"Found: " <<val <<endl;
        cout <<"Linear search time: " <<end - beg <<endl<<endl;
    }
    else{
        cout <<"Number not found!\n";
    }
    
    
    //Binary search
    beg = time(0);
    int val2 = binFnd(linear, size-1);
    end = time(0);
   
    if(val2 != -1){
        cout <<"Found: " <<val2 <<endl;
        cout <<"Binary search time: " <<end - beg <<endl;
    }
    else{
        cout <<"Number not found!\n";
    }
    
    
    return 0;
}

int linFnd(vector<int> vec, int val){
    int found = -1;
    
    //Operation counter
    int ops = 0;
    
    for(vector<int>::iterator itr = vec.begin();
            itr!=vec.end(); itr++){
        //For loop
        ops+=3;
        
        //If comparison
        ops+=1;
        if(*itr == val){
            //Assigning ops
            ops+=2;
            found = *itr;
    
            //End loop
            itr = vec.end()-1;
        }
    }
    
    cout <<"Linear operations: " <<ops <<endl;
    return found;
}

int binFnd(vector<int> vec, int val){
    int ops = 0;
    
    vector<int>::iterator itr1 = vec.begin();
    vector<int>::iterator itr2 = vec.end()-1;
    
    
    int start = *itr1;
    int stop = *itr2;
    
    //Assignment ops
    ops+=4;
    
    while(start <= stop){
        //While op
        ops+=1;
        
        //Mid computation
        ops+=4;
        int mid = start + (stop-start)/2;
        
        //If ops
        ops+=1;
        if(vec[mid]==val){
            cout <<"Binary operations: " <<ops <<endl;
            return vec[mid];
        }
        
        //If ops
        ops+=1;
        if(vec[mid] < val){
            start = mid+1;
            //Start op
            ops+=2;
        }
        else{
            stop=mid-1;
            //Stop op
            ops+=2;
        }
    }
    
    cout <<"Binary operations: " <<ops <<endl;
    
    return -1;
}