/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: K99
 *
 * Created on May 24, 2018, 12:14 AM
 */

#ifndef TREE_H
#define TREE_H


#include <vector>
#include "node.h"

class Tree {
public:
    Tree(int);
    virtual ~Tree();
    
    //Add data to tree
    void insert(int);
    void delData(int);
    node* findVal(int);
    
    //Output functions
    void outPst();
    void outIn();
    void outPre();
    void outLvl();
    
private:
    //Tree root
    node* root;
    
    //adds node
    node* newNode(int);
    
    //Recursive functions
    void recPst(node*); 
    void recIn(node*);
    void recPre(node*);
    
    //Recursive deletion
    node* recDel(node*, int);
    node* minN(node*);
    
    
};

#endif /* TREE_H */

