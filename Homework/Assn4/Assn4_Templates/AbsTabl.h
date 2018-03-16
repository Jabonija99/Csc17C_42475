/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsTabl.h
 * Author: K99
 *
 * Created on March 8, 2018, 3:21 PM
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h"

template <class T>
class AbsTabl{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        virtual int getSzRow()const = 0;
        virtual int getSzCol()const = 0;
        virtual T getData(int,int)const = 0;
};

#endif /* ABSTABL_H */

