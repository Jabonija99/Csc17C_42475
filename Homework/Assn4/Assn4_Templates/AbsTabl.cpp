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

template <class T>
int AbsTabl<T>::getSzRow() const{
    return szRow;
}

template <class T>
int AbsTabl<T>::getSzCol() const{
    return szCol;
}

template <class T>
T AbsTabl<T>::getData(int row, int col) const{
    return columns[row]->getData(col);
}
