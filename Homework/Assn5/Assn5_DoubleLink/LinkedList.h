/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: K99
 *
 * Created on March 29, 2018, 3:53 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>
#include <new>


using namespace std;

template <class T>
class LinkedList{
    private:
        //Link structure
        struct Link{
            T data;         //Data
            Link *linkptr;  //Link Pointer
            int rank;       //Priority rank
        };
        
        //Pointers for link
        Link *front, *next, *temp, *end, *found;
        //Points end ptr to last ptr
        void endLst();
        //Points found ptr to data ptr
        void fndLst(const T&);
        //Sort function
        void sort();
        
        
    public:
        
        
        //Constructors
        LinkedList();
        LinkedList(const T&);
        //Copy constructor
        LinkedList(const LinkedList&);
        //Destructor
        ~LinkedList();
        
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
        
        //Insert before(index, data)
        void insBef(const T&, const T&);
        //Insert after(index, data)
        void insAft(const T&, const T&);
        //Insert at beginning(data)
        void insBeg(const T&);
        
        //Delete value
        void delData(const T&);
        
        //Prioritize value
        void prioritize(const T&);
        
};

template <class T>
void LinkedList<T>::endLst(){
    temp = front;
    do{
        end = temp;
        temp = temp->linkptr;
    }while(temp!=NULL);
    
}

template <class T>
void LinkedList<T>::fndLst(const T &value){
    //Set cursor to start
    found = front;
    
    //Go through link
    while(found != NULL){
        //If link ptr has value
        if(found->data == value)
            //end function
            return;
        
        //Point to next data;
        found = found->linkptr;
    }
    //Point to null if value isn't found
    found = NULL;
}

template <class T>
void LinkedList<T>::sort(){
    bool swapped;
    
    do{
        swapped = false;
        
        //Bubble sort
        temp = front;
        
        while(temp->linkptr!=NULL){
            
            //Get next value
            next = temp->linkptr;
            
            //If the current value is greater
            if(temp->data > next->data){  
                if(temp->rank == 0){
                    //Swap
                    T dataTemp = temp->data;
                    temp->data = next->data;
                    next->data = dataTemp;
                    //Flag swap
                    swapped = true; 
                }
            }
            
            //Point to next value
            temp = next;
            
        }
        
        
    }while(swapped);
}


template <class T>
LinkedList<T>::LinkedList(){
    front = new Link;
    front->data = 0;
    front->linkptr = NULL;
    front->rank = 0;
}

template <class T>
LinkedList<T>::LinkedList(const T&value){
    front = new Link;
    front->data = value;
    front->linkptr = NULL;
    front->rank = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &obj){
    //Copy constructor
    if(obj != NULL){
        front = new Link;
        front->data = obj.front->data;
        front->linkptr = NULL;
        front->rank = 0;
        
        next = obj.front->linkptr;
        while(next != NULL){
            addLst(next->data);
            next = next->linkptr;
        }
    }
}

template <class T>
LinkedList<T>::~LinkedList(){
    while(front != NULL){
        temp = front->linkptr;
        delete front;
        front = temp;
    }
}

template <class T>
void LinkedList<T>::prntLst(){
    next = front;
    cout <<"Beginning of List\n"; 
    while(next != NULL){
        cout <<next->data <<endl;
        next = next->linkptr;
    }
    cout <<"End of List\n\n";
}

template <class T>
void LinkedList<T>::addLst(const T& value){
    //Point to last link
    endLst();
    //Create new link
    Link *add = new Link;
    add->data = value;
    add->linkptr = NULL;
    add->rank = 0;

    //Point to the new end of the list
    end->linkptr = add;
    
    sort();
}

template <class T>
int LinkedList<T>::findLst(const T& value){
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
int LinkedList<T>::cntLst(){
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
T LinkedList<T>::getObj(int index){
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
void LinkedList<T>::insBef(const T& index, const T& value){
    //Point to data
    fndLst(index);
    
    if(found != NULL){
        //Point to front
        temp = front;
        if(temp != found){
             //Create new link
            Link* add = new Link;
            add->data = value;
            add->linkptr = found;
            add->rank = 0;
            
            //Find link before found ptr
            while(temp->linkptr != found){
                temp = temp->linkptr;
            }

            //Point to other link
            temp->linkptr = add;
        }
        else{
            //Insert at beginning
            insBeg(value);
        }
    }
}

template <class T>
void LinkedList<T>::insAft(const T& index, const T& value){
    //Point to data
    fndLst(index);
    
    if(found != NULL){
        //Save next link
        next = found->linkptr;
        
        //Create new link
        Link* add = new Link;
        add->data = value;
        add->linkptr = next;
        add->rank = 0;
        
        //Point to added link
        found->linkptr = add;
    }
    
}

template <class T>
void LinkedList<T>::insBeg(const T& value){
    //Point to first value
    temp = front;
    
    //Create new link
    Link *add = new Link;
    add->data = value;
    add->linkptr = temp;
    add->rank = 0;
    
    //Point to new front
    front = add;
}

template <class T>
void LinkedList<T>::delData(const T& value){
    //Point to data
    fndLst(value);
    
    //If data was found
    if(found != NULL){
        //Point to front
        temp = front;
        
        //If found does not point to front
        if(temp != found){
            //Find link to found
            while(temp->linkptr != found){
                temp = temp->linkptr;
            }
            
            //Assign next link in chain
            next = found->linkptr;

            //Delete data ptr
            delete found;

            //Link  to next ptr
            temp->linkptr = next;
        }
        else{
            //If front is deleted
            //Point to next link
            front = found->linkptr;
            
            //Delete front
            delete found;   
        }
    }
}

template <class T>
void LinkedList<T>::prioritize(const T& val){
    fndLst(val);
    
    if(found != NULL){
        T dataTemp = found->data;
        delData(dataTemp);
        insBeg(dataTemp);
        
        //Set priority
        front->rank = 1;
        
        sort();
    }
    
}


#endif /* LINKEDLIST_H */

