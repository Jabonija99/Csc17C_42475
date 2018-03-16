/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.h
 * Author: K99
 *
 * Created on March 8, 2018, 3:22 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

#include "AbsRow.h"

template <class T>
class RowAray:public AbsRow<T>{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return this->size;}
        T getData(int i)const{
            if(i>=0&&i<this->size)return this->rowData[i];
            else return 0;}
        void setData(int,T);
};

#endif /* ROWARAY_H */

