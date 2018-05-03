/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef SIMPLEVECOPT_H
#define SIMPLEVECOPT_H


#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVecOpt
{
  private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int maxSize;      // Maximum size of aray
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   void incSize();   // Doubles size when array reaches max

public:
   // Default constructor
   SimpleVecOpt()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVecOpt(int);
   
   // Copy constructor declaration
   SimpleVecOpt(const SimpleVecOpt &);
   
   // Destructor declaration
   ~SimpleVecOpt();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }
   
   // Accessor to return max size
   int maxSz() const {return maxSize;}

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   // Adds value to end of array
   void push(int);
   
};


//***********************************************************
// Constructor for SimpleVecOpt class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVecOpt<T>::SimpleVecOpt(int s)
{
   maxSize = s;
   arraySize = 0;
   
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < maxSize; count++){
      *(aptr + count) = 0;
      arraySize++;
   }
}

//*******************************************
// Copy Constructor for SimpleVecOpt class. *
//*******************************************

template <class T>
SimpleVecOpt<T>::SimpleVecOpt(const SimpleVecOpt &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVecOpt class.  *
//**************************************

template <class T>
SimpleVecOpt<T>::~SimpleVecOpt()
{
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVecOpt<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVecOpt<T>::subError()
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
T SimpleVecOpt<T>::getElementAt(int sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVecOpt<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

template <class T>
void SimpleVecOpt<T>::push(int number){
    //Create temporary copy array
    SimpleVecOpt<T> vTemp(arraySize+1);
    
    //Copy original array
    for (int i = 0; i < arraySize; i++){
        vTemp.aptr[i] = aptr[i];
        vTemp.arraySize++;
    }
    
    //Increase size
    arraySize++;
    incSize();
    
    
    //Delete pointer
    delete []aptr;
    
    // Allocate memory for the array.
    try
    {
       aptr = new T [maxSize];
    }
    catch (bad_alloc)
    {
       memError();
    }
    
    //Copy contents of old array
    for(int i = 0 ; i < vTemp.size() ; i++){
        aptr[i] = vTemp.getElementAt(i);
    }
    
    //Push new number
    aptr[arraySize-1] = number;
    
}

template <class T>
void SimpleVecOpt<T>::incSize(){
    //Doubles max size if array size reaches cap
    if(arraySize >= maxSize){
        int newSize = maxSize*2;
        
        //Create temporary copy array
        SimpleVecOpt<T> vTemp(newSize);

        //Copy original array
        for (int i = 0; i < arraySize; i++){
            vTemp.aptr[i] = aptr[i];
            vTemp.arraySize++;
        }

        //Delete pointer
        delete []aptr;

        //Increase size
        maxSize = newSize;

        // Allocate memory for the array.
        try
        {
           aptr = new T [newSize];
        }
        catch (bad_alloc)
        {
           memError();
        }

        //Copy contents of old array
        for(int i = 0 ; i < arraySize ; i++){
            aptr[i] = vTemp.getElementAt(i);
        }
       
    }
}



#endif /* SIMPLEVECOPT_H */

