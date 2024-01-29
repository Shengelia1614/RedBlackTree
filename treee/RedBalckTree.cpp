#include "RedBalckTree.h"

void RedBlackTree::delrecursive(RedBlackTreeNode* a)//deleting all elements
{
   
        if (a != nullptr) { 
            if (a->getL() != nullptr && a->getR() != nullptr) { 
                delrecursive(a->left);
                delrecursive(a->right);
            }
            else {
                if (a->getL() != nullptr) { 
                    delrecursive(a->getL());
                }
                else {
                    delrecursive(a->getR());
                }
            }

            delete a;
        
    }
}

RedBlackTreeNode* RedBlackTree::recser(RedBlackTreeNode* a)//recusrsively copying
{
   
    if (a == nullptr) { 
        return nullptr;
    }

    RedBlackTreeNode* nw = new RedBlackTreeNode(a->getValue(), a->getColor());

    
    nw->setL(recser(a->getL()));
    nw->setR(recser(a->getR()));

 
    return nw;

}

void RedBlackTree::insert(int val) //self explanatory
{
    if (serch(val, rut)) { 
        cout << "already exists " << endl;
        return;
    }
    

    RedBlackTreeNode* par, * qur;
    RedBlackTreeNode* t = new RedBlackTreeNode(val, RED, NULL, NULL, NULL);
    par = rut; 
    qur = NULL; 
    if (rut == NULL)
    {
        t->setColor(BLACK);
        rut = t;
        t->setpar(NULL);
    }
    else
    {
        while (par != NULL) 
        {
            qur = par; //i think... i think i messed up the naming : )
            if (par->getValue() < t->getValue())
                par = par->getR();
            else
                par = par->getL();
        }
        
       
        t->setpar(qur); 
        
        if (qur->getValue() < t->getValue())
            qur->setR(t);
        else
            qur->setL(t);
    }
   
    RedBlackTreeNode* u; //this is for uncle

   
        while (t->getpar() != NULL && t->getpar()->getColor() == RED)
        {
            
            RedBlackTreeNode* g = t->getpar()->getpar(); 
            if (g->getL() == t->getpar()) 
            {
                if (g->getR() != NULL)
                {
                    u = g->getR();
                    if (u->getColor() == RED)
                    {
                        t->getpar()->setColor(BLACK);
                        u->setColor(BLACK);
     
                        g->setColor(RED);
     
                    }
                    t = g;
                }
                else
                {
                    if (t->getpar()->getR() == t)
                    {
                        t = t->getpar();
                        rotL(t); 
                    }
                    t->getpar()->setColor(BLACK);
                    g->setColor(RED);
                    rotR(g);
                }
            }
            else
            {
               
                    if (g->getL() != NULL)
                    {
                        u = g->getL();
                        if (u->getColor() == RED)
                        {
                            t->getpar()->setColor(BLACK);
                            u->setColor(BLACK);
                            g->setColor(RED);
                           
                        }
                        t = g;
                    }
                
                else
                {
                    if (t->getpar()->getL() == t)
                    {

                        t = t->getpar();
                        rotR(t);
                        
                    }

                    t->getpar()->setColor(BLACK);
                    g->setColor(RED);
                    rotL(g);
                }
            }
            rut->setColor(BLACK);
        }
    






  
        
}

void RedBlackTree::realdeletor(int val)//this is what i call in main to actually delete member
{
    RedBlackTreeNode* tobedel = NULL; 
    
    tobedel = searcher(val); 

    
    if (serch(val, rut) == 0) { 
        cout << "this element doesnt exist" << endl;
        return;
    }
  
    deletor(tobedel);
}

RedBlackTreeNode* RedBlackTree::successor(RedBlackTreeNode* x)
{
    RedBlackTreeNode* temp = x;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

void RedBlackTree::deletor(RedBlackTreeNode* nod)//deleting function that balances things
{
    RedBlackTreeNode* u;

    if (nod->left != NULL && nod->right != NULL) u = successor(nod->right);

 
    if (nod->left == NULL && nod->right == NULL) u = NULL;


    if (nod->left != NULL) u = nod->left;
    else
        u = nod->right;

    
    


    if (u == NULL) {
        
        if (nod == rut) {
            
            rut = NULL;
        }
        else {
            if ((u == NULL || u->Color == BLACK) && (nod->Color == BLACK)) {
            
                
                
                
                fixDoubleBlack(nod);
            }
            else {
                
                if (nod == nod->parent->left && nod->parent->right != NULL)
                    
                    nod->parent->right->Color = RED;
                if (nod == nod->parent->right && nod->parent->left != NULL) 
                    nod->parent->left->Color = RED;
            }

            
            if (nod == nod->parent->left) {
                nod->parent->left = NULL;
            }
            else {
                nod->parent->right = NULL;
            }
        }
        delete nod; 
        return;
    }

    if (nod->left == NULL || nod->right == NULL) {
       
        if (nod == rut) {
           
           
            nod->value = u->value;
            nod->left = nod->right = NULL;
            delete u;
        }
        else {
          
            if (nod == nod->parent->left) {
                nod->parent->left = u;
            }
            else {
                nod->parent->right = u;
            }
            RedBlackTreeNode* par_rem = nod->parent; 
            
            delete nod;
            
            u->parent = par_rem;
            if ((u == NULL || u->Color == BLACK) && (nod->Color == BLACK)) {
 
                fixDoubleBlack(u);
            }
            else {
                
                u->Color = BLACK;
            }
        }
        return;
    }

   
    int temp = u->value;
    u->value = nod->value;
    nod->value = temp;
    deletor(u);
}

void RedBlackTree::fixDoubleBlack(RedBlackTreeNode* nod)// the "dont you love when you spend 4 hours troubleshooting only to find out you had misplaced single pointer" function
{


    if (nod == rut)
       
        return;
    RedBlackTreeNode* sibling;
  
    if (nod == nod->parent->left) sibling = nod->parent->right; 
    else sibling = nod->parent->left;


    if (sibling == NULL) { 
        
        fixDoubleBlack(nod->parent);
    }
    else {
        if (sibling->Color == RED) { 
            
           
            nod->parent->Color = RED; 
            sibling->Color = BLACK;
            if (sibling = sibling->parent->left) {
               
                rotR(nod->parent);
            }
            else {
                
                rotL(nod->parent);
            }
            fixDoubleBlack(nod);
        }
        else {
         
            if ((sibling->left != NULL && sibling->left->Color == RED) || (sibling->right != NULL && sibling->right->Color == RED)) { 
                
                if (sibling->left != NULL && sibling->left->Color == RED) { 
                    if (sibling == sibling->parent->left) {
                        
                        sibling->left->Color = sibling->Color;
                        sibling->Color = nod->parent->Color;
                        rotR(nod->parent);
                       
                    }
                    else {
                  
                        sibling->left->Color = nod->parent->Color;
                        rotR(sibling);
                        rotL(nod->parent);
                        
                    }
                }
                else {
                    if (sibling == sibling->parent->left) {

                        sibling->right->Color = nod->parent->Color;
                        rotL(sibling);
                        rotR(nod->parent);
                        
                    }
                    else {

                        
                        sibling->right->Color = sibling->Color;
                        sibling->Color = nod->parent->Color;
                        rotL(nod->parent);
                    }
                }
                nod->parent->Color = BLACK;
            }
            else {
                
                sibling->Color = RED;
                if (nod->parent->Color == BLACK)
                    fixDoubleBlack(nod->parent);
                else
                    nod->parent->Color = BLACK;
            }
        }
    }
}



bool RedBlackTree::serch(int val, RedBlackTreeNode* cur) //search function, recursive
{
    if (cur == nullptr) {
        return false;
    }
    else if (val < cur->getValue()) {
        return serch(val, cur->getL());
    }
    else if (val > cur->getValue()) {
        return serch(val, cur->getR());
    }
    else {
        
        return true;
    }
};

void RedBlackTree::rotL(RedBlackTreeNode* x)  //left rotation
{


    RedBlackTreeNode* y = x->getR();
    x->setR(y->getL());

    
    if (y->getL() != NULL) {
        y->getL()->setpar(x);
    }

    y->setpar(x->getpar());

    if (x->getpar() == nullptr) {
        rut = y;
    }
    else if (x == x->getpar()->getR()) {
        x->getpar()->setR(y);
    }
    else {
        x->getpar()->setL(y);
     
    }
    y->setL(x);
   
    x->setpar(y);
   

}

void RedBlackTree::rotR(RedBlackTreeNode* x) //Right rotation
{

  
    RedBlackTreeNode* y = x->getL();
    x->setL(y->getR());

   
    if (y->getR() != NULL) {
        y->getR()->setpar(x);
    }

   
    y->setpar(x->getpar());


    if (x->getpar() == nullptr) {
        rut = y;
    }
    else if (x == x->getpar()->getL()) {
        x->getpar()->setL(y);
    }
    else {
        x->getpar()->setR(y);
        
    }
    y->setR(x);

    x->setpar(y);

}

RedBlackTreeNode* RedBlackTree::searcher(int val) //another search function lol, this one actually returns node that was found
{
    RedBlackTreeNode* trav = rut;
    while (trav != NULL && trav->getValue() != val) {
        if (trav->getValue() > val)
        {
            trav = trav->getL();
        }
        else {
            trav = trav->getR();
        }
    }
    
    return trav;
}
