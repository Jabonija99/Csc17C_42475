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

RowAray::RowAray(unsigned int size){
    if(size > 0){
        this->size = size;
        rowData = new int[this->size];
    }
    
}

RowAray::~RowAray(){
    delete rowData;
}

void RowAray::setData(int index, int value){
    if(index >=0 && index < size)
        rowData[index] = value;
}
