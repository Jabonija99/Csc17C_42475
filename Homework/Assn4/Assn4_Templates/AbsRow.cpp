/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsRow.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:18 PM
 */

#include "AbsRow.h"

int AbsRow::getSize()const{
    return size;
}

int AbsRow::getData(int index)const{
    return rowData[index];
}

