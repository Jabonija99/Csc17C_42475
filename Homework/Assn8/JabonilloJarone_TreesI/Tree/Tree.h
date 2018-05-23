/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: K99
 *
 * Created on May 22, 2018, 4:18 PM
 */

#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree{
public:
    Tree();
    virtual ~Tree();
    
    node* newNode(int);
    
    void outPst();
    void outIn();
    void outPre();
    void outLvl();
    
private:
    node* root;
    int m;
    
    void prntPst(node*);
    void prntIn(node*);
    void prntPre(node*);
    void prntLvl(node*);

};

#endif /* TREE_H */

