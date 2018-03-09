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

Table::Table(unsigned int row, unsigned int col){
    if(row > 0 && col > 0){
        szRow = row;
        szCol = col;
    }
    else{
        szRow = 0;
        szCol = 0;
    }
    
    columns = new RowAray*[szRow];
    
    for(int i = 0; i < szRow; i++){
        columns[i] = new RowAray(szCol);
    }
    
    //Assign values
    for(int i = 0; i < szRow; i++){
        for(int j = 0 ; j < szCol; j++){
            columns[i]->setData(j,rand()%90+10);
        }
    }
    
}

Table::Table(const Table& obj){
    //Copy table object
    szRow = obj.getSzRow();
    szCol = obj.getSzCol();
    
    columns = new RowAray*[szRow];
    
    for(int i = 0; i < szRow; i++){
        columns[i] = new RowAray(szCol);
    }
    
    //Copy contents
    for(int i = 0; i < szRow; i++){
        for(int j = 0 ; j < szCol; j++){
            columns[i]->setData(j,obj.getData(i,j));
        }
    }
    
}

Table::~Table(){
    for(int i = 0; i < szRow; i++){
        delete []columns[i];
    }
    delete []columns;
    
}

int Table::getData(int row, int col) const{
    return columns[row]->getData(col);
}

void Table::setData(int row, int col, int val){
    if(row > 0 && row < szRow && col > 0 && col < szCol){
        columns[row]->setData(col, val);
    }
}