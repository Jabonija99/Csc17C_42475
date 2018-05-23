/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 16, 2018, 7:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <cmath>


#include "node.h"

using namespace std;



//Prototypes
node * newNode(int);
void prntPst(node*);//Post order left-right-root
void prntIn(node*); //left-root-right
void prntPre(node*);//root-left-right
void prntLvl(node*); 
/* level order method:
 * 1 Queue
 * 2 root->print
 * 3 queue->children
 * =========
 * 4 Pull from queue
 * 5 print val
 * 6 queue children
 * 7 repeat from 4 until null
 */


/*
 * 
 */
int main(int argc, char** argv) {
    node *root                = newNode(8);
    
    root->left                = newNode(4);
    root->right               = newNode(12);
    
    root->left->left          = newNode(2);
    root->left->right         = newNode(6);
    root->right->left         = newNode(10);
    root->right->right        = newNode(14);
    
    root->left->left->left    = newNode(1);
    root->left->left->right   = newNode(3);
    root->left->right->left   = newNode(5);
    root->left->right->right  = newNode(7);     
    root->right->left->left   = newNode(9);
    root->right->left->right  = newNode(11);
    root->right->right->left  = newNode(13);
    root->right->right->right = newNode(15);     

    cout<<endl<<"Preorder traversal of binary tree is "<<endl;
    prntPre(root);

    cout<<endl<<"Inorder traversal of binary tree is "<<endl;
    prntIn(root);  

    cout<<endl<<"Postorder traversal of binary tree is "<<endl;
    prntPst(root);
    
    cout <<endl <<"Levelorder traversal of binary tree is: " <<endl;
    prntLvl(root);
            

    return 0;
}


/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node* newNode(int data){
     node *n;
     n=new node;
     n->data = data;
     n->left = NULL;
     n->right = NULL;
     return n;
}
 
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void prntPst(node* n){
     if (n == NULL)
        return;
     // first recur on left subtree
     prntPst(n->left);
     // then recur on right subtree
     prntPst(n->right);
     // now deal with the node
     cout<<n->data<<" ";
}
 
/* Given a binary tree, print its nodes in inorder*/
void prntIn(node* n){
     if (n == NULL)
          return;
     /* first recur on left child */
     prntIn(n->left);
     /* then print the data of node */
     cout<<n->data<<" ";  
     /* now recur on right child */
     prntIn(n->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void prntPre(node* node){
     if (node == NULL)
          return;
     /* first print data of node */
     cout<<node->data<<" ";  
     /* then recur on left subtree */
     prntPre(node->left);  
     /* now recur on right subtree */
     prntPre(node->right);
} 

void prntLvl(node* n){
    bool end = false;
    int h = 3;
    int branches = (pow(2,h+1))-1;
    queue<int> treeQue;
    
    //cout <<branches <<endl;
    cout <<n->data <<" ";
    
    node* index = n;
    
    while(!end){
        for(int i = 0; i < 3; ++i){
            
        }
        end = true;
    }
    
    

}