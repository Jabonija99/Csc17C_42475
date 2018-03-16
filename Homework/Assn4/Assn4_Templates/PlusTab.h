/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlusTab.h
 * Author: K99
 *
 * Created on March 8, 2018, 3:21 PM
 */

#ifndef PLUSTAB_H
#define PLUSTAB_H

#include "Table.h"

template <class T>
class PlusTab:public Table<T>{
    public:
        PlusTab(unsigned int r,unsigned int c):Table<T>(r,c){};
        PlusTab<T> operator+(const PlusTab<T> &);
};

#endif /* PLUSTAB_H */

