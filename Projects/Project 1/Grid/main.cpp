/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on April 10, 2018, 6:01 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */

struct Grid{
    int height, width;
    string**a;
};

class ShipCarr{
    private:
        int size;
        string carrier;
        string *array;
    public:
        ShipCarr();
        ~ShipCarr();
        
        string get(int i)
            {return array[i];}
};

ShipCarr::ShipCarr(){
    size = 5;
    carrier = "[C]";
    array = new string[size];
    for(int i = 0; i < size; ++i){
        array[i] = carrier;
    }
}

ShipCarr::~ShipCarr(){
    delete array;
}



int main(int argc, char** argv) {
    
    //String constants
    const string block = "[ ]", shipCar = "[C]",
            shipBat = "[B]", shipCru = "[R]",
            shipSub = "[S]", shipDes = "[D]";
    
    
    //Create grid
    Grid grid;
    grid.height = 10;
    grid.width = 10;
    
    //Create array
    grid.a = new string*[grid.height];
    for(int i = 0; i < grid.height; i++){
        grid.a[i] = new string[grid.width];
    }
    
    //Set blocks
    for(int i = 0; i < grid.height; i++){
        for(int j = 0; j < grid.width; j++){
            grid.a[i][j] = block;
        }
    }

    //Create Alphabetical index
    string alph[grid.height] = {" A]", " B]", " C]", " D]",
                        " E]", " F]", " G]", " H]", " I]", " J]"};
    
    
    //Modify grid
    for(int i = 0; i < grid.height; ++i){
        for(int j = 0 ; j < grid.width; ++j){
            if(j == 8){
                if(i > 1 && i < 7){
                    grid.a[i][j] = shipCar;
                }
            }
        }
    }
    
    
    //Output grid
    for(int i = 0; i < grid.height; i++){
        if(i < 1){
            for(int j = 0; j < grid.width+1; j++){
                cout <<"[" <<j <<"]";
            }
            cout <<endl;
        }
        
        cout <<alph[i];
        for(int j = 0; j < grid.width; j++){
            cout << grid.a[i][j];
        }
        cout <<endl;
    }
    
    
    return 0;
}
