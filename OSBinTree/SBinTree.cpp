#include "SBinTree.h"

SBinTree::SBinTree(int n)       
{
    if (n == 0) root = NULL;
    else
    {
        root = new Node(rand() % 50);
        for (int i = 1; i < n; i++) Add(rand() % 50, root);
    }
}

SBinTree::SBinTree(int * a, int n)
{
    if (n == 0) root = NULL;
    else
    {
        root = new Node(a[0]);
        for (int i = 1; i < n; i++)    Add(a[i], root);
    }
}

SBinTree::SBinTree(const SBinTree &T)
{
    if (T.root == NULL) root = NULL;
    else
    {
        root = new Node(T.root->key);
        Copy(T.root->left, root, 0);
        Copy(T.root->right, root, 1);
    }
}

SBinTree & SBinTree::operator=(const SBinTree &T)
{
    this->BinTree::operator=(T);
    return *this;
}

void SBinTree::Add(int k, Node *p)
{
    Node *q;
    if (root == NULL)
    {
        q = new Node(k);
        root = q;
        return;
    }
    if (k < p->key)
        if (p->left == NULL)
        {
            q = new Node(k);
            p->left = q;
            q->parent = p;
        }
        else Add(k, p->left);
    else if (p->right == NULL)
    {
        q = new Node(k);
        p->right = q;
        q->parent = p;
    }
    else Add(k, p->right);
}

void SBinTree::Del(Node *p)          
{
    if (p == root) { DelRoot(); return; }
    Node *q = p->parent;
   
    if (p->left == NULL && p->right == NULL)
    {
        if (q->left == p) q->left = NULL;
        else q->right = NULL;
        delete p;
        return;
    }

    
    if (p->left == NULL)
    {
        if (q->left == p) q->left = p->right;
        else q->right = p->right;
        p->right->parent = q;
        delete p;
        return;
    }

    
    if ( p->right == NULL)
    {
        if (q->left == p) q->left = p->left;
        else q->right = p->left;
        p->left->parent = q;
        delete p;
        return;
    }

    
    Node *t = p->left;
    if (t->right == NULL)
    {
        t->parent = q;
        if (q->left == p) q->left = t;
        else q->right = t;
        t->right = p->right;
        p->right->parent = t;
    }
    else
    {
        while (t->right != NULL) t = t->right;
        t->parent->right = t->left;
        if (t->left != NULL)
            t->left->parent = t->parent;

        t->left = p->left;
        t->right = p->right;
        p->left->parent = t;
        p->right->parent = t;

        t->parent = q;
        if (q->left == p) q->left = t;
        else q->right = t;
    }

    delete p;
    return;
}

void SBinTree::DelRoot()
{
    Node *p = root;
    
    if (p->left == NULL && p->right == NULL)
    {
        delete p;
        root = NULL;
        return;
    }
    
    if (p->left == NULL)
    {
        root = p->right;
        root->parent = NULL;
        delete p;
        return;
    }
    
    if (p->right == NULL)
    {
        root = p->left;
        root->parent = NULL;
        delete p;
        return;
    }
    
    
    Node *t = p->left;
    if (t->right == NULL)
    {
        t->parent = NULL;
        t->right = p->right;
        p->right->parent = t;
    }
    else {
        while (t->right != NULL) t = t->right;
        t->parent->right = t->left;
        if (t->left != NULL)
            t->left->parent = t->parent;

        t->left = p->left;
        t->right = p->right;
        p->left->parent = t;
        p->right->parent = t;

        t->parent =NULL;
    }
    delete p;
    root = t;
    return;
}

Node * SBinTree::FindKey(int k, Node * p)
{
    if (p == NULL || p->key == k) return p;
    if (p->key != k)
    {
        return (k<p->key) ? FindKey(k,p->left) : FindKey (k,p->right);
    }
    return NULL;
}

Node * SBinTree::FindMax(Node * p)
{
    if (p == NULL)return NULL;
    while (p->right != NULL) p = p->right;
    return p;
}

Node * SBinTree::FindMin(Node * p)
{
    if (p == NULL)return NULL;
    while (p->left != NULL) p = p->left;
    return p;
}
