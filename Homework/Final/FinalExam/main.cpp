/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on June 1, 2018, 5:49 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>

#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>

#include "GenStringFunct.h"
#include "TrigFunct.h"
#include "Clerk.h"
#include "Tree.h"

using namespace std;

/*
 * 
 */

void prob1();
int phnHash(const string&);
int genValue(const char&);

void prob2();

void prob3();
void store();
void showStack(list<Clerk>&);
void store2();
void store3();
void clerks1(int);

void prob4();
void sortSel(list<short int>::iterator,
        list<short int>::iterator,int);
void sortMrg(list<short int>::iterator,
        list<short int>::iterator, int);
void output(list<short int>);

void prob5();

void prob6();

void cls();

int main(int argc, char** argv) {
    srand(time(0));
    
    short int ans = 0;
    
    while(ans != -1){
        cout <<"Jabonillo Jarone Csc_17C Final\n"
                <<"==================================\n"
                <<"1] Hashing\n"
                <<"2] Stacks\n"
                <<"3] Queues\n"
                <<"4] Sorting\n"
                <<"5] Binary Trees\n"
                <<"6] Weighted Graph\n"
                <<"-1] Exit\n"
                <<"==================================\n"
                <<"Select problem: ";
        cin >> ans;

        cls();
        
        switch(ans){
            case 1:
                prob1();
                break;
            case 2:
                prob2();
                break;
            case 3:
                prob3();
                break;
            case 4:
                prob4();
                break;
            case 5:
                prob5();
                break;
            case 6:
                prob6();
                break;
            case -1:
                cout <<"Thanks for your time!\n";
                break;
            default:
                cout <<"\n\nInvalid input!\n";
                break;
        }
    }
    
    return 0;
}

void prob1(){
    cout <<"Problem 1 - Hashing\n";

    string test;
    int size = 512;
    list<string> initials;
    
    //Set counters to 0
    int* hashtree = new int[100];   //Hashes
    int* eSum = new int[100];       //Sum of elements
    for(int i = 0; i < 100; ++i){
        hashtree[i] = 0;
        eSum[i] = 0;
    }
    
    //Hash elements
    int* hashed = new int[size];
    for(int i = 0; i < size; ++i){  
        //Generate string
        test = genString(3);
        //Push initials
        initials.push_back(test);
        //Hash initials
        hashed[i] = phnHash(test);
        //Increment hashed element
        hashtree[hashed[i]]++;
    }
    
    //Output results
    /*
    for(int i = 0; i < size; ++i){
        cout <<i+1 <<"] Hashing " <<initials.front() <<": " <<hashed[i] <<endl;
        initials.pop_front();
    }*/
    
    
    for(int i = 6; i <= 27; ++i){
        cout  <<i <<" has " << hashtree[i] <<" elements" <<endl;
        //eSum[hashtree[i]]++;
    }
    cout <<endl <<endl;
    
    
    /*
    //Generate stats
    cout <<"Elements:\n";
    for(int i = 0; i < 100; ++i){
        if(eSum[i]!=0)
            cout <<eSum[i] <<" elements hashing " << i  <<endl;
    }*/
    
    delete []hashed;
    delete []hashtree;
    delete []eSum;
    
}

int phnHash(const string& data){
    //Hash data
    int hashed = 0;

    //Go through string
    for(int i = 0; i < data.size(); ++i){
        //Calculate hash
        hashed += genValue(data[i]);
    }
    
    //Return hash
    return hashed;
}

int genValue(const char& c){
    int result = 0;
    int val = c;
    
    if(val >= 65 && val <= 67){
        //(A,B,C)
        result = 2;
    }
    else if(val >= 68 && val <= 70){
        //(D,E,F)
        result = 3;
    }
    else if(val >= 71 && val <= 73){
        //(G,H,I)
        result = 4;
    }
    else if(val >= 74 && val <= 76){
        //(J,K,L)
        result = 5;
    }
    else if(val >= 77 && val <= 79){
        //(M,N,O)
        result = 6;
    }
    else if(val >= 80 && val <= 83){
        //(P,Q,R,S)
        result = 7;
    }
    else if(val >= 84 && val <= 86){
        //(T,U,V)
        result = 8;
    }
    else if(val >= 87 && val <= 90){
        //(W,X,Y,Z)
        result = 9;
    }
    
    return result;
}


void prob2(){
    cout <<"Problem 2 - Stacks\n";
    stack<float> angSin;
    stack<float> angCos;
    
    float angDeg = 0;
    float angRad;
    
    /*
    float val = 1;
    //while(val > -1){
    while(angDeg < 180){
        angRad = angDeg*atan(1)/45;
        angCos.push(angRad);
        //val -= 0.1;
        angDeg+= 5.72;
    }
    
    
    angDeg = 90;
    while(angDeg <= 270){
        angRad = angDeg*atan(1)/45;
         angSin.push(angRad);
        //val -= 0.1;
        angDeg+= 5.72;
    }*/
    
    float val = 1;
    while(val >= -1.1){
        angRad = val;
        angCos.push(angRad);
        angSin.push(angRad);
        val-=0.1;
    }
       
    
    //Sin output
    int i = 0;
    while(!angSin.empty()){
        angRad = angSin.top();
        angSin.pop();
        cout<<i <<"] Angle = "<<angRad<<" sinh = "<<sinh(angRad)<<
                " our h = "<<h(angRad)<<endl;
        ++i;
    }
    cout <<endl;
    
    i=0;
    //Cos output
    while(!angCos.empty()){
        angRad = angCos.top();
        angCos.pop();
        cout<<i <<"] Angle = "<<angRad <<" cosh = "<<cosh(angRad)<<
            " our g = "<<g(angRad)<<endl;
        ++i;
    }
    cout <<endl <<endl;
   
}


void prob3(){
    cout <<"Problem 3 - Queues\n";

    store3();
   
    cout <<"Store closed!\n\n\n";
}

void store(){
    /*
    //Start clock
    clock_t start;
    float dur;
    float totTime = 20;
    
    cout <<"Simulating " <<totTime <<" minutes...\n";
    
    int size = 10;
    Clerk* clerks = new Clerk[size];
    queue<int> line;
    
    clerks[0].setTime(1);
    clerks[1].setTime(.75);
    clerks[2].setTime(.5);
    
    int c1= 0,c2 = 0, c3 = 0;
    start = clock();
    dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    
    int maxLine = 0;
    int maxWait = 0;
    
    clock_t lineTimer;
    
    do{
        
        lineTimer = clock();
        float lineTime = (clock() - lineTimer)/ (float) CLOCKS_PER_SEC;
        if(lineTime >= 4 ){
            
            cout <<"Added customer\n";
            line.push(1);
            lineTimer = clock();
        }
        
        if(line.size() > maxLine)
            maxLine = line.size();
        
        
        if(clerks[0].isRunning()){
            //Update and count
            if(!clerks[0].update()){
                line.pop();
                c1++;
            }
        }
        else{
            //Reset time
            clerks[0].startTime();
        }
    
        if(clerks[1].isRunning()){
            //Update and count
            if(!clerks[1].update()){
                line.pop();
                c2++;
            }
        }
        else{
            //Reset time
            clerks[1].startTime();
        }
        
        if(clerks[2].isRunning()){
            //Update and count
            if(!clerks[2].update()){
                line.pop();
                c3++;
            }
        }
        else{
            //Reset time
            clerks[2].startTime();
        }
        
        dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    }while(dur < totTime);
    
    cout <<"Max line: " <<maxLine <<endl;
    cout <<"Clerk1 Dur: " <<clerks[0].getTime() <<" Serving: " <<c1 <<endl;
    cout <<"Clerk2 Dur: " <<clerks[1].getTime() <<" Serving: " <<c2 <<endl;
    cout <<"Clerk3 Dur: " <<clerks[2].getTime() <<" Serving: " <<c3 <<endl;
    cout <<"Total  Dur: " <<dur <<endl;
    
    delete [] clerks;*/
}

void store3(){
    //Time variables
    clock_t start;
    float dur;
    float totTime = 20;
    
    cout <<"Simulating " <<totTime <<" minutes...\n";
    
    //Create clerks
    int size = 10, active = 3;
    Clerk* clerks = new Clerk[size];
    
    //Default values
    for(int i = 0; i < size; ++i){
        clerks[0].setTime(1);
    }
    //Set specific times
    clerks[1].setTime(.75);
    clerks[2].setTime(.5);
    
    //Create queue
    queue<int> line;
    
    //Start clock
    start = clock();
    dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    
    //Statistic variables
    int maxLine = 0;
    float maxWait = 0;
    
    //Timers
    clock_t lineTimer = clock();
    clock_t waitTimer = clock();
    //Wait timer
    float waitTime;
    
    do{
        //Generate customers
        float lineTime = (clock() - lineTimer)/ (float) CLOCKS_PER_SEC;
        //If time reaches 4 minutes
        if(lineTime >= 4 ){
            cout <<"Customer Arrived\n";
            //Add customer
            line.push(1);
            //Reset line time
            lineTimer = clock();
            //Start wait time
            waitTimer = clock();
        }
        
        //Record wait time if line isnt empty
        if(!line.empty())
            waitTime = (clock() - waitTimer)/ (float) CLOCKS_PER_SEC;
        
        //Find max line size
        if(line.size() > maxLine)
            maxLine = line.size();
        
        //Go through active clerks
        for(int i = 0 ; i < active; ++i){
            //If the line isnt empty
            if(!line.empty()){
                //If clerk is available
                if(!clerks[i].isRunning()){
                    cout <<"Customer is helped\n";
                    //Begin timer
                    clerks[i].startTime();
                    //Take customer
                    line.pop();
                    
                    //Reset wait timer
                    waitTimer = clock();
                    
                    //Record total wait time
                    if(waitTime > maxWait)
                        maxWait = waitTime;
                }
                else{
                    //Update clerk timer and check if completed
                    if(!clerks[i].update()){
                        //cout <<"Customer departs\n";
                    }
                }
                
                //If line is big
                if(line.size() > 5){
                    int extras = line.size()-5;
                    for(int i = 0; i < extras; ++i){
                        if(extras%5==0)
                            //Add clerk
                            active++;
                    }
                }
                else{
                    //Remove clerks
                    if(active > 3){
                        active--;
                    }
                }
            }
        }
        
        dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
        
    }while(dur < totTime);
    
    cout <<endl <<endl;
    cout <<"Max line:  " <<maxLine <<endl;
    cout <<"Max wait:  " <<maxWait <<endl;
    cout <<"Total Dur: " <<dur <<endl;
    
    delete [] clerks;

}

void showStack(list<Clerk>&teller){
    /*
    for(list<Clerk>::iterator itr = teller.begin();
            itr != teller.end(); ++itr){
        //cout <<*teller->getTime() <<' ';
    }
    cout <<endl;*/
}

void store2(){
    /*
    clock_t start;
    float dur;
    float totTime = 5;
    
    int size = 10;
    Clerk* clerks = new Clerk[size];
    
    clerks[0].setTime(1);
    clerks[1].setTime(.75);
    clerks[2].setTime(.5);
    
    int c1= 0,c2 = 0, c3 = 0;
    start = clock();
    dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    
    do{
        if(clerks[0].isRunning()){
            //Update and count
            if(!clerks[0].update())
                c1++;
        }
        else{
            //Reset time
            clerks[0].startTime();
        }
    
        if(clerks[1].isRunning()){
            //Update and count
            if(!clerks[1].update())
                c2++;
        }
        else{
            //Reset time
            clerks[1].startTime();
        }
        
        if(clerks[2].isRunning()){
            //Update and count
            if(!clerks[2].update())
                c3++;
        }
        else{
            //Reset time
            clerks[2].startTime();
        }
        
        dur = (clock() - start)/ (float) CLOCKS_PER_SEC;
    }while(dur < totTime);
    
    
    cout <<"Clerk1 Dur: " <<clerks[0].getTime() <<" Serving: " <<c1 <<endl;
    cout <<"Clerk2 Dur: " <<clerks[1].getTime() <<" Serving: " <<c2 <<endl;
    cout <<"Clerk3 Dur: " <<clerks[2].getTime() <<" Serving: " <<c3 <<endl;
    cout <<"Total  Dur: " <<dur <<endl;
    */
}

void clerks1(int time){
    /*
    clock_t start;
    double duration;
    
    start = clock();
    duration = (clock() - start)/ (double) CLOCKS_PER_SEC;
    
    while(duration < time){
        duration = (clock() - start)/ (double) CLOCKS_PER_SEC;
    }
    
    cout <<"Duration Passed: " <<duration <<endl;   */
}




void prob4(){
    cout <<"Problem 4 - Sorting\n";
    //Create list
    list<short int> lRand;
    list<short int> lRand2;
    
    //Fill random ints
    int size = 100000;
    for(int i = 0 ; i < size; ++i){
        int num = rand()%100;
        lRand.push_back(num);
        lRand2.push_back(num);
    }
    
    //Time start and end
    int start, end;
    //P elements
    int p=-1;
    
    do{
        cout <<"Enter elements to sort: ";
        cin >> p;
    }while(p < 0 || p > size);
    
    
    //Record selection sort time
    start = time(0);
    //sortSel(lRand.begin(),lRand.end(),p);
    //output(lRand);
    end = time(0);
    int time1 = end - start;
    
    //Record merge sort time
    start = time(0);
    //lRand2.sort();
    sortMrg(lRand2.begin(),lRand2.end(), p);
    //output(lRand2);
    end = time(0);
    int time2 = end - start;
    
    //Output results
    cout <<"Selection Sort time: " <<time1 <<endl;
    cout <<"Merge Sort time:     " <<time2 <<endl;
}

void sortSel(list<short int>::iterator beg,
        list<short int>::iterator end, int p){
    
    //Find stopping point
    list<short int>::iterator stop = beg;
    int i = 0;
    while(stop!= end && i < p){
        ++stop;
        ++i;
    }
    
    //Selection sort
    for(list<short int>::iterator itr1 = beg; itr1 != stop; ++itr1){
        list<short int>::iterator min = itr1;
        list<short int>::iterator test = itr1;
        ++test;
        
        while(test != stop){
            if(*test < *min){
                min = test;
            }
            
            ++test;
        }
        
        if(itr1 != min){
            iter_swap(itr1, min);
        }
        
    }
}

void sortMrg(list<short int>::iterator beg,
        list<short int>::iterator end, int p){
   
    int size = p;
    if(size == 0 && beg != end){
        size = distance(beg,end);
    }

    //Base condition
    if(size <= 1)
        return;
    
    //Calculate center
    int begHalf = size/2;
    int endHalf = size - begHalf;
    
    list<short int>::iterator mid = beg;
    advance(mid, begHalf);
    
    //Sort recursively
    sortMrg(beg, mid, begHalf);
    sortMrg(mid, end, endHalf);
    
    inplace_merge(beg,mid,end);
}

void output(list<short int> lst){
    for(list<short int>::iterator itr = lst.begin();
            itr != lst.end(); ++itr){
        cout <<*itr <<" ";
    }
    cout <<endl;
}



void prob5(){
    cout <<"Problem 5 - Binary Trees\n";
    string test;
    int size = 512;
    list<string> initials;
    
    //Hash elements
    int* hashed = new int[size];
    for(int i = 0; i < size; ++i){  
        //Generate string
        test = genString(3);
        //Push initials
        initials.push_back(test);
        //Hash
        hashed[i] = phnHash(test);
    }
    
    Tree bintree(hashed[0]);
    
    for(int i = 1; i < size; ++i){
        bintree.insert(hashed[i]);
    }
    
    bintree.outLvl();
    
    cout <<endl <<endl;
}

void prob6(){
    cout <<"Problem 6 - Weighted Graph\n";

    cout <<"**** See Worksheet ****\n\n";
    
}

void cls(){
    for(int i = 0 ; i < 20; ++i)
        cout <<endl;
}
