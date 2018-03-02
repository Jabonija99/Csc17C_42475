/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RowAray.h"
#include <cstdlib>

RowAray::RowAray(int size){
    if(size > 0){
        //Update size
        this->size = size;
        
        //Create dynamic array
        rowData = new int[this->size];
    
        //Fill array
        for(int i = 0; i < this->size; i++){
            rowData[i] = rand()% 90 + 10;
        }
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}
