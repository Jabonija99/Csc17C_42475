/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:22 PM
 */

#include "RowAray.h"

template <class T>
RowAray<T>::RowAray(unsigned int size){
    if(size > 0){
        this->size = size;
        this->rowData = new T[this->size];
    }
    
}

template <class T>
RowAray<T>::~RowAray(){
    delete this->rowData;
}

template <class T>
void RowAray<T>::setData(int index, T value){
    if(index >=0 && index < this->size)
        this->rowData[index] = value;
}
