/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.h
 * Author: rcc
 *
 * Created on February 28, 2018, 6:01 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

class RowAray{
    private:
        int size;
        int *rowData;

    public:
        RowAray(int);
        ~RowAray();
        int getSize(){return size;}
        int getData(int i){return rowData[i];}

};



#endif /* ROWARAY_H */

