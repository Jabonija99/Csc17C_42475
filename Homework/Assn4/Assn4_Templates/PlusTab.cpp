/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlusTab.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:21 PM
 */

#include "PlusTab.h"


template <class T>
PlusTab<T> PlusTab<T>::operator+(const PlusTab<T> &obj){
    PlusTab<T> sumTab(obj.szRow, obj.szCol);
    
    for(int i = 0; i < this->szRow; i++){
        for(int j = 0 ; j < this->szCol; j++){
            //Get sum of objects
            T sum = obj.getData(i,j)+this->columns[i]->getData(j);
            
            //Set sum
            sumTab.columns[i]->setData(j, sum);
        }
    }
    return sumTab;
}


