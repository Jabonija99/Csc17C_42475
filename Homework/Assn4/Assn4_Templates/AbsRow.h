/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbsRow.h
 * Author: K99
 *
 * Created on March 8, 2018, 3:18 PM
 */

#ifndef ABSROW_H
#define ABSROW_H

template <class T>
class AbsRow{
    protected:
        int size;
        T *rowData;
    public:
        virtual int getSize()const = 0;
        virtual T getData(int)const = 0;
};

#endif /* ABSROW_H */

