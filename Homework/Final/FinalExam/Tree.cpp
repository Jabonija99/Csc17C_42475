/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: K99
 * 
 * Created on May 24, 2018, 12:14 AM
 */

#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

Tree::Tree(int val) {
    root = newNode(val);
}

Tree::~Tree() {
    delete root;
}

void Tree::insert(int val){
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node *temp = q.front();
        q.pop();
       
        //If value is less than data
        if(val <= temp->data){
            //Move value left
            if(temp->left == NULL){
                temp->left = newNode(val);
                break;
            }
            else{
                q.push(temp->left);
            }
        }
        else{
            //Move value right
            if(temp->right == NULL){
                temp->right = newNode(val);
                break;
            }
            else{
                q.push(temp->right);
            }
        }
    }
}

void Tree::delData(int val){
    //deletes value and stores new root
    root = recDel(root,val);
}


node* Tree::findVal(int val){
    node*n = root;
    queue<node*> q;
    q.push(root);
    
    if(n->data == val){
        return n;
    }
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp->left->data == val){
            return temp->left;
        }
        else{
            q.push(temp->left);
        }
        
        if(temp->right->data == val){
            return temp->right; 
        }
        else{
            q.push(temp->right);
        }
    }
    
    //Null if not found
    return NULL;
}

void Tree::outPst(){
    cout <<"\nPostorder Traversal of tree:\n"; 
    recPst(root);
}

void Tree::outIn(){
    cout <<"\nInorder Traversal of tree:\n";
    recIn(root);
}

void Tree::outPre(){
    cout <<"\nPreorder Traversal of tree:\n";
    recPre(root);
}

void Tree::outLvl(){
    if(root == NULL)
        return;
    
    //Queue root
    cout <<"\nLevel order Traversal of tree:\n";
    queue<node*> q;
    q.push(root);
    
    
    while(!q.empty()){
        node*temp = q.front();
        
        //Print data
        cout <<temp->data <<" ";
        q.pop();
        
        //Queue children
        if(temp->left != NULL){
            q.push(temp->left);
        }
        
        if(temp->right != NULL){
            q.push(temp->right);
        }
    } 
}

node* Tree::newNode(int val){
    node *n;
    n = new node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void Tree::recPst(node* n){
    if(n==NULL)
        return;
    
    recPst(n->left);
    recPst(n->right);
    
    cout <<n->data <<" ";
}

void Tree::recIn(node* n){
    if(n==NULL)
        return;
    
    recIn(n->left);
    cout <<n->data <<" ";
    recIn(n->right);
}

void Tree::recPre(node* n){
    if(n==NULL)
        return;
    
    cout <<n->data <<" ";
    recPre(n->left);
    recPre(n->right);
}


node* Tree::recDel(node* n, int val){
    if(n == NULL)
        return n;
    
    if(val < n->data){
        n->left = recDel(n->left, val);
    }
    else if(val > n->data){
        n->right = recDel(n->right, val);
    }
    else{
        if(n->left == NULL){
            node* temp = n->right;
            delete n;
            return temp;
        }
        else if(n->right == NULL){
            node* temp = n->left;
            delete n;
            return temp;
        }
        
        node* temp = minN(n->right);
        
        n->data = temp->data;
        
        n->right = recDel(n->right, temp->data);
        
    }
    
    return n;
}

node* Tree::minN(node* n){
    node* temp = n;
    
    while(temp->left != NULL){
        temp = temp->left;
    }
    
    return temp;
}
