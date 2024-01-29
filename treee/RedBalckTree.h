#pragma once
#include <iostream>
#include "RedBalckTreeNode.h"


using namespace std;
//tree itself
class RedBlackTree
{  

    // root of the tree
    RedBlackTreeNode* rut;
    
    //left rotate
    void rotL(RedBlackTreeNode* x);

    //right rotate
    void rotR(RedBlackTreeNode* x); 

    //this returns found node
    RedBlackTreeNode* searcher(int val);


    // preorder
    void preord(RedBlackTreeNode* cur)const {
        if (cur == nullptr)return;
        cout << cur->getValue() << "  "; if (cur->getColor() == RED) cout << "red" << endl; else cout << " black" <<endl;
        //cout << cur->parent << endl;
        preord(cur->getL());
        preord(cur->getR());
    }
    // inorder
    void inord(RedBlackTreeNode* cur)const {
        if (cur == nullptr)return;
        inord(cur->getL());
        cout << cur->getValue() << "  "; if (cur->getColor() == RED) cout << "red" << endl; else cout << " black" << endl;
        inord(cur->getR());
    }
    //post order
    void postord(RedBlackTreeNode* cur)const {
        if (cur == nullptr)return;
        postord(cur->getL());
        postord(cur->getR());
        cout << cur->getValue() << "  "; if (cur->getColor() == RED) cout << "red" << endl; else cout << " black" << endl;
    }
    //helps destructor recursively
    void delrecursive(RedBlackTreeNode* a);
    //copy function that also uses recursion
    RedBlackTreeNode* recser(RedBlackTreeNode* a);
    //recursive search function
    bool serch(int val, RedBlackTreeNode* par);
    //this is called in actual delete function
    void deletor(RedBlackTreeNode* nod);
    //its in the name what this does lol
    void fixDoubleBlack(RedBlackTreeNode* nod);
    //finds successor
    RedBlackTreeNode* successor(RedBlackTreeNode* x);


public:
    RedBlackTree(){};
    //copy constructor
    RedBlackTree(RedBlackTree &a) {
        rut = recser(a.rut);
   
    }
    //destructor
    ~RedBlackTree() {
        delrecursive(rut);
    }
    //you can use = to basically copy the tree
    void operator=(RedBlackTree &a) {
        this->rut = recser(a.rut);
    }
    //adding new element
    void insert(int val);
    //checks if element exists
    bool realsearch(int val) {
        return serch(val, rut);
    }
    //printing with preorder
    void display() {
        preord(rut);
        cout << endl;
    }
    //deleting member function
    void realdeletor(int val);









};

