/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedVector.h
 * Author: K99
 *
 * Created on March 18, 2018, 4:17 PM
 */

#ifndef LINKEDVECTOR_H
#define LINKEDVECTOR_H


template <class T>
class LinkedVector {

private:
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   int maxSize;      // Maximum size of aray
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   void incSize();   // Doubles size when array reaches max

public:
   // Default constructor
   LinkedVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   LinkedVector(int);
   
   // Copy constructor declaration
   LinkedVector(const LinkedVector &);
   
   // Destructor declaration
   ~LinkedVector();
   
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

#endif /* LINKEDVECTOR_H */

