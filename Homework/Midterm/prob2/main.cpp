/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * Problem 2: Bubble vs selection sort
 */


void bubbleSort(int[], int);
void selectSort(int[],int);

int main(int argc, char** argv) {
    srand(time(0));
    int beg, end;
    
    int mod = 10000;
    int size = 5*mod;
    int array[size];
    int array2[size];
    
    cout <<"Given array size " <<size <<":\n\n";
    
    //Fill arrays
    for(int i = 0 ; i < size; i++){
        int num = rand()%20;
        array[i] = num;
        array2[i] = num;
    }
    
    beg = time(0);
    bubbleSort(array,size);
    end = time(0);
    
    /* //Output array
    cout <<"Bubble array:\n {";
    for(int i = 0; i < size; i++){
        cout <<array[i] <<" ";
        if(i%15==14)
            cout <<endl <<" ";
    }
    cout <<"}\n";
     * */
    
    cout <<"Bubble Sort time: " <<end-beg <<endl <<endl;

    beg = time(0);
    selectSort(array2,size);
    end = time(0);
    
    
    /* //Output array
    cout <<"Select array:\n {";
    for(int i = 0; i < size; i++){
        cout <<array2[i] <<" ";
        if(i%15==14)
            cout <<endl <<" ";
    }
    cout <<"}\n";
    */
    
    
    cout <<"Selection Sort time: " <<end-beg <<endl;

    
    
    
    return 0;
}

void bubbleSort(int a[], int size){
    int ops = 0;
    for(int i = 0 ; i < size-1; i++){
        ops+=4;
        for(int j = 0 ; j < size-i-1; j++){
            ops+=5;
            
            ops+=1;
            if(a[j] > a[j+1]){
                ops+=3;
                //swap
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout <<"Bubble sort operations: " <<ops <<endl;
}

void selectSort(int a[], int size){
    int ops = 0;
    
    int min;
    
    for(int i = 0; i < size-1; i++){
        ops+=4;
        
        ops+=1;
        min = i;
        for(int j = i+1; j < size; j++){
            ops+=4;
            
            ops+=1;
            if(a[j] < a[min]){
                ops+=1;
                min = j;
            }
        }
        
        ops+=3;
        //Swap
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    
    cout <<"Selection sort operations: " <<ops <<endl;
}