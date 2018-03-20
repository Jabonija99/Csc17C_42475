/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkTest.h
 * Author: K99
 *
 * Created on March 19, 2018, 6:38 PM
 */

#ifndef LINKTEST_H
#define LINKTEST_H

#include <cstdlib>
#include <iostream>
#include <new>

using namespace std;

template <class T>
class LinkTest{
    private:
        //Link structure
        struct Link{
            T data;
            Link *linkptr;
        };
        
        //Max size for link list
        int maxSize;
        //Pointers for link
        Link *front, *next, *temp, *end, *found;
        //Points end ptr to last ptr
        void endLst();
        //Points found ptr to data ptr
        void fndLst(const T&);
        //Fill linked list (size, starting at given value)
        void fill(int);
        //Double size when array reaches max
        void incSize(); 
        
        
    public:
        //Constructors
        LinkTest();
        LinkTest(const T&);
        LinkTest(const T&,int); //Constructor with size
        //Destructor
        ~LinkTest();
        
        //Output list
        void prntLst();
        //Add to list
        void addLst(const T&);
        //Determine which link contains data
        int findLst(const T&);
        //Return linked list size
        int cntLst();
        //Return data from linked list (index)
        T getObj(int);
        
        //Push value to available link
        void push(const T&);
        //Return max size
        int maxSz()const{return maxSize;}
        
};

template <class T>
void LinkTest<T>::endLst(){
    temp = front;
    do{
        end = temp;
        temp = temp->linkptr;
    }while(temp!=NULL);
    
}

template <class T>
void LinkTest<T>::fndLst(const T &value){
    //Set cursor to start
    found = front;
    
    //Go through link
    while(found != NULL){
        //If link ptr has value
        if(found->data == value)
            //end function
            return found;
        
        //Point to next data;
        found = found->linkptr;
    }
    //Point to null if value isn't found
    found = NULL;
}

template <class T>
void LinkTest<T>::fill(int size){
    for(int i = 0; i < size; i++){
        addLst(-1);
    }
}

template <class T>
void LinkTest<T>::incSize(){
    //If contents exceed size
    if (cntLst() >= maxSize){
        //Double size
        int newSize = maxSize*2;
        fill(maxSize);
        maxSize = newSize;
    }
}


template <class T>
LinkTest<T>::LinkTest(){
    front = new Link;
    front->data = 0;
    front->linkptr = NULL;
    maxSize = 10;
    fill(maxSize-1);
}

template <class T>
LinkTest<T>::LinkTest(const T&value){
    front = new Link;
    front->data = value;
    front->linkptr = NULL;
    
    maxSize = 10;
    fill(maxSize-1);
}

template <class T>
LinkTest<T>::LinkTest(const T&value, int size){
    front = new Link;
    front->data = value;
    front->linkptr = NULL;
    
    maxSize = size;
    //Fill list to max size
    fill(size-1);
}

template <class T>
LinkTest<T>::~LinkTest(){
    while(front != NULL){
        temp = front->linkptr;
        delete front;
        front = temp;
    }
}

template <class T>
void LinkTest<T>::prntLst(){
    next = front;
    cout <<"Beginning of List\n"; 
    while(next != NULL){
        if(next->data != -1)
            cout <<next->data <<endl;
        next = next->linkptr;
    }
    cout <<"End of List\n\n";
}

template <class T>
void LinkTest<T>::addLst(const T& value){
    //Point to last link
    endLst();
    //Create new link
    Link *add = new Link;
    add->data = value;
    add->linkptr = NULL;

    //Point to the new end of the list
    end->linkptr = add;
    
}

template <class T>
int LinkTest<T>::findLst(const T& value){
    //Initialize index counter
    int i = 0;
    
    //Point to front of list
    temp = front;
    while(temp!=NULL){
        //Increment counter
        i++;
        
        //If value is found
        if(temp->data == value)
            //Return index of data
            return i;
        //Move to next link
        temp=temp->linkptr;
    }
    
    //Return -1 if value isnt found
    return -1;
}

template <class T>
int LinkTest<T>::cntLst(){
    //Init index counter
    int i=0;
    
    //Point to front of list
    temp = front;
    
    while(temp!=NULL){
        //If data is null, decrement counter
        if(temp->data==-1)
            i--;
            
        //Increment counter
        i++;
        temp = temp->linkptr;
    }
    
    return i;
}

template <class T>
T LinkTest<T>::getObj(int index){
    //Init counter
    int i = 0;
    
    //Point to front of list
    temp = front;
    
    while(temp != NULL){
        if(i == index)
            return temp->data;
        
        //Increment counter
        i++;
        
        //Move to next link
        temp = temp->linkptr;
        
    }
    
    //Return front value
    return front->data;
}

template <class T>
void LinkTest<T>::push(const T& value){
    //Point to front index
    temp = front;
    //Loop until empty slot is found
    while(temp != NULL && temp->data != -1){
        temp = temp->linkptr;
    }
    
    //If slot is confirmed empty
    if(temp->data == -1)
        //Assign value
        temp->data = value;
    
    //Check and increase size
    incSize();
    
}

#endif /* LINKTEST_H */

