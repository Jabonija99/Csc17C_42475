/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsTabl.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:21 PM
 */

#include "AbsTabl.h"

int AbsTabl::getSzRow() const{
    return szRow;
}

int AbsTabl::getSzCol() const{
    return szCol;
}

int AbsTabl::getData(int row, int col) const{
    return columns[row]->getData(col);
}
