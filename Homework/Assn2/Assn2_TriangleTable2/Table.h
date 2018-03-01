/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: rcc
 *
 * Created on February 28, 2018, 6:10 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

class Table{
private:
    int szRow;
    int szCol;
    RowAray **records;
    
public:
    Table(int,int);
    ~Table();
    int getSzRow(){return szRow;}
    int getSzCol(){return szCol;}
    int getData(int,int);
    
};



#endif /* TABLE_H */

