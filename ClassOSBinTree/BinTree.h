#pragma once
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node
{
    int key;
    Node* left, * right, * parent;

public:
    Node(int k = 0, Node* L = NULL, Node* R = NULL, Node* P = NULL)
    {
        key = k; left = L; right = R; parent = P;
    }
    int GetKey() { return key; }
    friend class BinTree;
    friend class SBinTree;
    friend class OSBinTree;
};
class BinTree
{
protected:
    Node* root;
    Node* Tree(int n, Node* p);
    void Copy(Node* q, Node* p, int f);
    
public:
    BinTree() { root = NULL; }
    BinTree(int n);        
    BinTree(int* a, int n);    
    BinTree(const BinTree&);
    BinTree& operator=(const BinTree& X);
    virtual ~BinTree();

    virtual void Add(int k, Node* p);   
    virtual void Del(Node* p);            
    virtual void DelRoot();            

    void TreeTraversal_LCR(Node* p);   
    void TreeTraversal_CLR(Node* p);    
    void TreeTraversal_RCL(Node* p);   
    void WidthTraversal(Node* p);       
    void PrintCurrentLevel(Node* p, int i); 

    virtual Node* FindKey(int k, Node* p);  
    virtual Node* FindMax(Node* p);     
    virtual Node* FindMin(Node* p);       
    int FindHight(Node* p);      
    int Count(Node* p);           

    Node* GetRoot() { return root; }

    void Clear();                     
    void PrintTree(int k, Node* p);   
};
