/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlusTab.cpp
 * Author: K99
 * 
 * Created on March 8, 2018, 3:21 PM
 */

#include "PlusTab.h"



PlusTab PlusTab::operator+(const PlusTab &obj){
    PlusTab sumTab(obj.szRow, obj.szCol);
    
    for(int i = 0; i < szRow; i++){
        for(int j = 0 ; j < szCol; j++){
            //Get sum of objects
            int sum = obj.getData(i,j)+columns[i]->getData(j);
            
            //Set sum
            sumTab.columns[i]->setData(j, sum);
        }
    }
    return sumTab;
}


