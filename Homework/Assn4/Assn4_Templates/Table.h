/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: K99
 *
 * Created on March 8, 2018, 3:23 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "AbsTabl.h"

template <class T>
class Table:public AbsTabl<T>{
    public:
        Table(unsigned int,unsigned int);
        Table(const Table &);
        virtual ~Table();
        int getSzRow()const {return this->szRow;}
        int getSzCol()const {return this->szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
};

#endif /* TABLE_H */

