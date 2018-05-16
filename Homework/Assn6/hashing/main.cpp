/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on May 15, 2018, 12:44 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "GeneralHashFunctions.h"

using namespace std;

/*
 * 
 */

string genString(int);
void hashed(int*, int, bool&);
int hashType(int, string, int);
void outMax(int*, int);
void outString(int);
bool check(int*, int);

int main(int argc, char** argv) {
    srand(time(0)); //Set random seed
    
    int size = 10;  //Size of string
    int numHash = 11; //Number of hashes
    
    int *arr;       //Array of collisions
    bool first;     //Bool for first collision
    
    int n = 10000;
    arr = new int[n];
    
    //Iterate through each hash type
    for(int i = 1; i <= numHash; ++i){
        outString(i);
        first = true;
        
        
        //Fill array with zeros
        for(int j = 0; j < n; ++j){
            arr[j] = 0;
        }
        
        //Hash n times
        for(int j = 0; j < n; ++j){
            //Generate string
            string s = genString(size);
            //Get hash
            int key = (hashType(i,s,n));
            //Index hash
            hashed(arr, key, first);
        }
        
        //Output max collisions
        outMax(arr,n);
        cout <<endl;
    
    }
    
    //Clear memory
    delete arr;
    
    return 0;
}

string genString(int length){
    //Create string
    string result = "";
    char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";
    char *s = new char[length];
    
    //Generate string
    for(int i = 0; i < length; ++i){
        s[i] = alph[rand()%(sizeof(alph)-1)];
    }
    s[length] = 0;
    
    //Record result
    for(int i = 0; i < length; ++i){
        result +=s[i];
    }
    
    //Delete char arr
    delete[] s;

    //Return result
    return result;
}

int hashType(int type, string s, int n){
    unsigned int val = 0;
    switch(type){
        case 1:
            val = RSHash(s);
            break;
        case 2:
            val = JSHash(s);
            break;
        case 3:
            val = PJWHash(s);
            break;
        case 4:
            val = ELFHash(s);
            break;
        case 5:
            val = BKDRHash(s);
            break;
        case 6:
            val = SDBMHash(s);
            break;
        case 7:
            val = DJBHash(s);
            break;
        case 8:
            val = DEKHash(s);
            break;
        case 9:
            val = FNVHash(s);
            break;
        case 10:
            val = BPHash(s);
            break;
        case 11:
            val = APHash(s);
            break;
        default:
            val = 0;
            break;
    }
    
    int key = val%n;
    
    return key;
}

void hashed(int* a, int n, bool& first){
    unsigned int index = n;
    
    if(check(a, index) && first){
        cout <<"First collision at index: " <<index <<endl;
        first = false;
    }
    
    a[index]++;
}

void outMax(int *a, int size){
    int max = 0;
    for(int i = 0 ; i < size; i++){
        if(a[i] > max)
            max = a[i];
    }
    cout <<"Max collisions: " <<max <<endl;
}

void outString(int type){
    switch(type){
        case 1:
            cout <<"RSHash: \n";
            break;
        case 2:
            cout <<"JSHash: \n";
            break;
        case 3:
            cout <<"PJWHash: \n";
            break;
        case 4:
            cout <<"ELFHash: \n";
            break;
        case 5:
            cout <<"BKDRHash: \n";
            break;
        case 6:
            cout <<"SDBMHash: \n";
            break;
        case 7:
            cout <<"DJBHash: \n";
            break;
        case 8:
            cout <<"DEKHash: \n";
            break;
        case 9:
            cout <<"FNVHash: \n";
            break;
        case 10:
            cout <<"BPHash: \n";
            break;
        case 11:
            cout <<"APHash: \n";
            break;
        default:
            cout <<"No hash type found!\n";
            break;
    }
}

bool check(int *a, int index){
    bool collide = false;
    if(a[index] == 0 ){
        collide = true;
    }
        
    return collide;    
}