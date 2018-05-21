/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on May 19, 2018, 8:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <set>
#include <iterator>

#include "GeneralHashFunctions.h"

using namespace std;

/*
 * 
 */

string genString(int);
int srchLine(string*,int, string);
int srchBin(string*,int, string);
int srchHash(int*,int, string);
void outAry(string*, int);

int main(int argc, char** argv) {
    //Start random
    srand(time(0));
    
    //Array size
    int mod = 10000000;
    int aSize = 9*mod;
    
    //Create array  s  
    string* ary = new string[aSize];
    string* ary2 = new string[aSize];
    int* ary3 = new int[aSize];     
    set<string> aryOrder;
    
    //String size
    int sSize = 20;
    //Generate string
    for(int i = 0; i < aSize; ++i){
        string val = genString(sSize);
        
        ary[i] = val;
        aryOrder.insert(val);
    }
    
    
    //Record ordered set
    int k = 0;
    for(set<string>::iterator itr = aryOrder.begin();
            itr != aryOrder.end(); ++itr){
        ary2[k] = *itr;
        ++k;
    }
    
    //Hashed set
    for(int i = 0 ; i < aSize; ++i){
        ary3[i] = RSHash(ary[i]);
    }
    
    //Record existing and non existing string
    string strGood = ary[aSize/2];
    string strBad = genString(sSize);
    
    //Output results
    cout <<"Size of array: " <<aSize <<endl;
    
    cout <<"Existing Linear search time:    " 
            <<srchLine(ary,aSize,strGood) <<endl;
    cout <<"Nonexisting Linear search time: " 
            <<srchLine(ary,aSize,strBad) <<endl <<endl;
    
    cout <<"Existing Binary search time:    " 
            <<srchBin(ary2,aSize,strGood) <<endl;
    cout <<"Nonexisting Binary search time: "
            <<srchBin(ary2,aSize,strBad) <<endl <<endl;
    
    cout <<"Existing Hash search time:      " 
            <<srchHash(ary3,aSize,strGood) <<endl;
    cout <<"Nonexisting Hash search time:   "
            <<srchHash(ary3,aSize,strBad) <<endl <<endl;
    
    
    //Clear memory
    delete[] ary;
    delete[] ary2;
    delete[] ary3;
    
    //End program
    return 0;
}

string genString(int size){
    //Create string
    string result = "";
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";
    char *s = new char[size];
    
    //Generate string
    for(int i = 0; i < size; ++i){
        s[i] = alph[rand()%(sizeof(alph)-1)];
    }
    s[size] = 0;
    
    //Record result
    for(int i = 0; i < size; ++i){
        result +=s[i];
    }
    
    //Delete char arr
    delete[] s;

    //Return result
    return result;
}

int srchLine(string* a, int n, string s){
    //Time variables
    int end,beg;
    
    //Start time
    beg = time(0);
    
    //Linear search
    for(int i = 0; i < n; ++i){
        //If found
        if(a[i] == s){
            //End loop
            i = n;
        }
    }
    
    //End time
    end = time(0);
    
    //Return time
    return end-beg;
}

int srchBin(string* a, int n, string s){
    //Time variables
    int end, beg;
    
    //Start time
    beg = time(0);
    
    //Binary search
    int start = 0;
    int stop = n;
    
    while(start <= stop){
        //Calculate middle
        int mid = start+(stop-start)/2;
        
        if(a[mid] == s){
            //End loop
            start = stop+1;
        }
        
        if(a[mid] < s){
            start = mid+1;
        }
        else{
            stop = mid-1;
        }
    }

    //End time
    end = time(0);

    //Return time
    return end-beg;
}

int srchHash(int* a, int n, string s){
    //Time variables
    int end, beg;
    
    //Start time
    beg = time(0);
    
    int key = RSHash(s);
    
    //Hash
    for(int i = 0 ; i < n; ++i){
        if(a[i] == key){
            //End loop
            i = n;
        }
    }
    
    //End time
    end = time(0);
    
    //Return time
    return end-beg;
}

void outAry(string* a, int n){
    for(int i = 0 ; i < n; ++i){
        cout <<a[i] <<endl;
    }
    cout <<endl;
}