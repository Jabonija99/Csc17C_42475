/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Table.h"

Table::Table(int row, int col){
    if(row > 0 && col > 0){
        szRow = row;
        szCol = col;
    
        records = new RowAray*[szRow];
        
        for(int i = 0; i < szRow; i++){
            records[i] = new RowAray(szCol);
        }
    }
}

Table::~Table(){
    for(int i = 0; i < szRow; i++){
        delete[] records[i];
    }
    delete[] records;
}

int Table::getData(int row, int col){
    if(row >=0 && col >=0){
        return records[row]->getData(col);
    }
}