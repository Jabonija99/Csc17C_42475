/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleVector.h
 * Author: K99
 *
 * Created on March 22, 2018, 7:12 PM
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
    //Link structure
    struct Link{
        T data;
        Link *linkptr;
    };
    //Pointers for links
    Link *front, *next, *temp, *end, *found;
    //Point end ptr to last tptr
    void endLst();
    //Points found ptr tp data ptr
    void fndLst(const T&);
    //Fill linked list (size)
    void fill(int);
    //Double size when vector exceeds max
    void incSize();
    
    int arraySize;    // Number of elements in the array
    int maxSize;      // Maximum size of aray
    
    void memError();  // Handles memory allocation errors
    void subError();  // Handles subscripts out of range

public:
    //Constructors
    SimpleVector();
    SimpleVector(const T&);
    SimpleVector(const T&,int);

    // Copy constructor declaration
    SimpleVector(const SimpleVector &);

    // Destructor declaration
    ~SimpleVector();

    // Accessor to return the array size
    int size() const
       { return arraySize; }

    // Accessor to return max size
    int maxSz() const {return maxSize;}

    // Accessor to return a specific element
    T getElementAt(int position);

    // Overloaded [] operator declaration
    T &operator[](const int &);
   
   
   
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
    
    //Insert before(index, data)
    void insBef(const T&, const T&);
    //Insert after(index, data)
    void insAft(const T&, const T&);
    //Insert at beginning(data)
    void insBeg(const T&);

    //Delete value
    void delData(const T&);
   
   
};


template <class T>
void SimpleVector<T>::endLst(){
    //Point to last link
    temp = front;
    do{
        end = temp;
        temp = temp->linkptr;
    }while(temp != NULL);
}


template <class T>
void SimpleVector<T>::fndLst(const T &value){
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
void SimpleVector<T>::fill(int size){
    for(int i = 0; i < size; i++){
        addLst(-1);
    }
}

template <class T>
void SimpleVector<T>::incSize(){
    //If contents exceed size
    if (cntLst() >= maxSize){
        //Double size
        int newSize = maxSize*2;
        fill(maxSize);
        maxSize = newSize;
    }
}






//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(){
   maxSize = 10;
   arraySize = 0;
   // Allocate memory for the array.
   try
   {
        front = new Link;
        front->data = 0;
        front->linkptr = NULL;
        fill(maxSize-1);
        arraySize = cntLst();
   }
   catch (bad_alloc)
   {
      memError();
   }
}

template <class T>
SimpleVector<T>::SimpleVector(const T&value){
    maxSize = 10;
    arraySize = 0;
    // Allocate memory for the array.
    try
    {
         front = new Link;
         front->data = value;
         front->linkptr = NULL;
         fill(maxSize-1);
         arraySize = cntLst();
    }
    catch (bad_alloc)
    {
       memError();
    }
}

template <class T>
SimpleVector<T>::SimpleVector(const T&value, int s)
{
    //Set size
    maxSize = s;

    // Allocate memory for the array.
    try
    {
        front = new Link;
        front->data = value;
        front->linkptr = NULL;
        fill(maxSize-1);
        arraySize = cntLst();
    }
    catch (bad_alloc)
    {
       memError();
    }
   
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    // Copy the array size.
    arraySize = obj.size();
    maxSize = obj.maxSz();

    // Allocate memory for the array.
    try
    {
        front = new Link;
        front->data = obj.front->data;
        front->linkptr = NULL;
        fill(maxSize-1);
    }
    catch (bad_alloc)
    {
       memError();
    }
    

    // Copy the elements of obj's array.
    for(int i = 1; i < arraySize; i++){
        push(obj.getElementAt(i));
    }
   
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    while(front!=NULL){
        temp = front->linkptr;
        delete front;
        front = temp;
    }
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   
   
   return getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   
   return getObj(sub);
}

template <class T>
void SimpleVector<T>::prntLst(){
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
void SimpleVector<T>::addLst(const T& value){
    //Point to last link
    endLst();
    //Create new link
    Link *add = new Link;
    add->data = value;
    add->linkptr = NULL;

    //Point to the new end of the list
    end->linkptr = add;
    //Update size
    arraySize=cntLst();
}

template <class T>
int SimpleVector<T>::findLst(const T& value){
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
int SimpleVector<T>::cntLst(){
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
T SimpleVector<T>::getObj(int index){
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
void SimpleVector<T>::push(const T& value){
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
    arraySize=cntLst();
}


template <class T>
void SimpleVector<T>::insBef(const T& index, const T& value){
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
void SimpleVector<T>::insAft(const T& index, const T& value){
    //Point to data
    fndLst(index);
    
    if(found != NULL){
        //Save next link
        next = found->linkptr;
        
        //Create new link
        Link* add = new Link;
        add->data = value;
        add->linkptr = next;
        
        //Point to added link
        found->linkptr = add;
    }
    
}

template <class T>
void SimpleVector<T>::insBeg(const T& value){
    //Point to first value
    temp = front;
    
    //Create new link
    Link *add = new Link;
    add->data = value;
    add->linkptr = temp;
    
    //Point to new front
    front = add;
}

template <class T>
void SimpleVector<T>::delData(const T& value){
    //Point to data
    fndLst(value);
    
    //If data was found
    if(found != NULL){
        //Point to front
        temp = front;
        
        //Find found does not point to front
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


#endif /* SIMPLEVECTOR_H */

