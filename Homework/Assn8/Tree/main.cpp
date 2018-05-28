/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: K99
 *
 * Created on May 22, 2018, 4:14 PM
 */

#include <cstdlib>
#include "tree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tree binTree;
    
    binTree.outPre();
    binTree.outIn();
    binTree.outPst();
    
    
    return 0;
}

