/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:23 PM
 */

#include "Table.h"
#include <cstdlib>

template <class T>
Table<T>::Table(unsigned int row, unsigned int col){
    if(row > 0 && col > 0){
        this->szRow = row;
        this->szCol = col;
    }
    else{
        this->szRow = 0;
        this->szCol = 0;
    }
    
    this->columns = new RowAray<T>*[this->szRow];
    
    for(int i = 0; i < this->szRow; i++){
        this->columns[i] = new RowAray<T>(this->szCol);
    }
    
    //Assign values
    for(int i = 0; i < this->szRow; i++){
        for(int j = 0 ; j < this->szCol; j++){
            this->columns[i]->setData(j,rand()%90+10);
        }
    }
    
}

template <class T>
Table<T>::Table(const Table& obj){
    //Copy table object
    this->szRow = obj.getSzRow();
    this->szCol = obj.getSzCol();
    
    this->columns = new RowAray<T>*[this->szRow];
    
    for(int i = 0; i < this->szRow; i++){
        this->columns[i] = new RowAray<T>(this->szCol);
    }
    
    //Copy contents
    for(int i = 0; i < this->szRow; i++){
        for(int j = 0 ; j < this->szCol; j++){
            this->columns[i]->setData(j,obj.getData(i,j));
        }
    }
    
}

template <class T>
Table<T>::~Table(){
    for(int i = 0; i < this->szRow; i++){
        delete this->columns[i];
    }
    delete []this->columns;
    
}

template <class T>
T Table<T>::getData(int row, int col) const{
    return this->columns[row]->getData(col);
}

template <class T>
void Table<T>::setData(int row, int col, T val){
    if(row > 0 && row < this->szRow && col > 0 && col < this->szCol){
        this->columns[row]->setData(col, val);
    }
}