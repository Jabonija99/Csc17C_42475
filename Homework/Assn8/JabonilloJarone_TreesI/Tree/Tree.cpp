/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: K99
 * 
 * Created on May 22, 2018, 4:18 PM
 */

#include "Tree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Tree::Tree(){
    //Binary tree
    int m = 2;
    //Create root
    root = newNode(8);
    
    //Fill branches
    root->left = newNode(4);
    root->right = newNode(12);
    
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);
    root->left->right->left = newNode(5);
    root->left->right->right = newNode(7);     
    root->right->left->left = newNode(9);
    root->right->left->right = newNode(11);
    root->right->right->left = newNode(13);
    root->right->right->right = newNode(15); 
}

Tree::~Tree(){
    
}

node* Tree::newNode(int data){
    node *n;
    n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Tree::outPst(){
    cout <<"\nPostorder Traversal of tree:\n"; 
    prntPst(root);
}

void Tree::outIn(){
    cout <<"\nInorder Traversal of tree:\n";
    prntIn(root);
}

void Tree::outPre(){
    cout <<"\nPreorder Traversal of tree:\n";
    prntPre(root);
}

void Tree::outLvl(){
    cout <<"\nLevelorder Traversal of tree:\n";
    prntLvl(root);
}



void Tree::prntPst(node* n){
    if(n==NULL)
        return;
    
    prntPst(n->left);
    prntPst(n->right);
            
    cout <<n->data <<" ";
}

void Tree::prntIn(node* n){
    if(n==NULL)
        return;
    
    prntIn(n->left);
    
    cout <<n->data <<" ";
    
    prntIn(n->right);
}

void Tree::prntPre(node* n){
    if(n==NULL)
        return;
    
    cout <<n->data <<" ";
    
    prntPre(n->left);
    prntPre(n->right);
}

void Tree::prntLvl(node* n){
    if(n==NULL)
        return;
    cout <<n->data <<endl;
    if(n->left != NULL)
        cout <<n->left->data <<" ";
    if(n->right != NULL)
        cout <<n->right->data <<" ";
    prntLvl(n->left);
    prntLvl(n->right);
}

