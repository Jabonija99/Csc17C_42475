/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Triangle.h"

Triangle::Triangle(int rows){
    if(rows > 0){
        szRow = rows;
        records = new RowAray*[szRow];
        
        for(int i = 0; i < szRow; i++){
            records[i] = new RowAray(i+1);
        }
        
    }
}

Triangle::~Triangle(){
    for(int i = 0; i < szRow; i++){
        delete[] records[i];
    }
    delete[] records;
}

int Triangle::getData(int row,int col){
    if(row >= 0 && col >= 0){
        return records[row]->getData(col);
    }
}