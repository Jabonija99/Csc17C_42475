/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TrigFunct.h
 * Author: K99
 *
 * Created on June 2, 2018, 8:46 PM
 */

#ifndef TRIGFUNCT_H
#define TRIGFUNCT_H

float h(float);
float g(float);

float h(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h(angR/2)*g(angR/2);
}

float g(float angR){
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2);
    return 1+2*b*b;
}

#endif /* TRIGFUNCT_H */

