/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on February 14, 2018, 7:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Struct2D.h"

using namespace std;

/*
 * 
 */
Array2D *filStrc(int,int);
void prtStruc(Array2D*);
void destroy(Array2D*);
void mrkSort(Array2D*, int);

int main(int argc, char** argv) {
    //Generate random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and init the 2d strcuture
    Array2D *x= filStrc(10,15);
    
    //Display the contents of the 2D structure
    prtStruc(x);
    
    //Sort column of array
    mrkSort(x,0);
    
    //Display the contents of the 2D structure
    prtStruc(x);
    
    //Destroy allocated memory
    destroy(x);

    return 0;
}


void mrkSort(Array2D *a, int col){
    //Scan through array
    for(int i=0; i < a->rows-1; i++){
        for(int j =i+1; j < a->rows;j++ ){
            if(a->data[i][col] > a->data[j][col]){
                for(int k=0; k<a->cols; k++){
                    //Swap
                    int temp = a->data[i][k];
                    a->data[i][k] = a->data[j][k];
                    a->data[j][k] = temp;
                
                } 
            }
        }
    }
}

void destroy(Array2D *a){
    //Deallocate memory for the 2d array structure
    for(int i=0;i<a->rows;i++){
        delete []a->data[i];;
    }
    delete []a->data;
    delete a;
}

void prtStruc(Array2D *a){
    //Display the Structure
    cout <<"Structure data array size => rows: " <<a->rows
            <<" cols: " <<a->cols <<endl <<endl;
    for(int i=0; i < a->rows; i++){
        for(int j=0; j < a->cols; j++){
            cout << a->data[i][j] <<" ";
        }
        cout <<endl;
    }
    cout <<endl<<endl;
}

Array2D* filStrc(int row, int col){
    //Declare variables
    Array2D *array = new Array2D;
    
    //Fill 2d array struct
    array->rows=row;
    array->cols=col;
    
    //Allocate memory for the 2d array structure
    array->data=new int*[array->rows];
    for(int i=0;i<array->rows;i++){
        array->data[i]=new int[col];
    }
    
    //Fill memory array
    for(int i=0; i < array->rows; i++){
        for(int j=0; j < array->cols; j++){
            array->data[i][j]=rand()%90+10;
        }
    }
    
    return array;
}
