#include "BinTree.h"

Node* BinTree::Tree(int n, Node* p)
{
    if (n == 0) return NULL;
    Node* q = new Node(rand() % 10+1);
    int nL, nR;
    nL = (n - 1) / 2; nR = n - 1 - nL;
    q->left = Tree(nL, q);
    q->right = Tree(nR, q);
    q->parent = p;
    return q;
}

BinTree::BinTree(int n)
{
    root = Tree(n, NULL);
}

BinTree::BinTree(int* a, int n)
{
    Node* obj = new Node(a[0]);
    for (int i = 1; i < n; i++)
    {
        Add(a[i], obj);
    }
    root = obj;
}

void BinTree::Copy(Node* q, Node* p, int f)

{
    if (q == NULL) return;
    Node* t = new Node(q->key,NULL,NULL,p);
    t->parent = p;
    if (f == 0) p->left = t;
    if (f == 1) p->right = t;

    Copy(q->left, t, 0);
    Copy(q->right, t, 1);
}


BinTree::BinTree(const BinTree& T)
{
    if (T.root == NULL) root = NULL;
    else {
        root = new Node(T.root->key);
        Copy(T.root->left, root, 0);
        Copy(T.root->right, root, 1);
    }
}

BinTree& BinTree::operator=(const BinTree& X)
{
    if (this != &X)
    {
        Clear();
        delete root;
        if (X.root == NULL) root = NULL;
        else {
            root = new Node(X.root->key);
            Copy(X.root->left, root, 0);
            Copy(X.root->right, root, 1);
        }
    }

    return *this;
}

BinTree::~BinTree()
{
    Clear();
    DelRoot();
}

void BinTree::Clear()
{
    if (root == NULL)return;
    Node* q = root;
    while (q->left != NULL)Del(q->left);
    while (q->right!= NULL)Del(q->right);
}

void BinTree::PrintTree(int k, Node* p)
{
    if (p == NULL) return;
    PrintTree(k + 5, p->right);
      for (int i = 0; i < k; i++) cout << ' ';
    cout << p->key << endl;
    PrintTree(k + 5, p->left);
  }

void BinTree::Add(int k, Node* p)
{
    if (p->left == NULL)
    {
        Node* q = new Node(k);
        p->left = q;  q->parent = p;
        return;
    }
    if (p->right == NULL)
    {
        Node* q = new Node(k);
        p->right = q;  q->parent = p;
        return;
    }
    if (rand() % 2) Add(k, p->left);
    else Add(k, p->right);
}

void BinTree::Del(Node* p)         
{
    if (p == root) {
        DelRoot();
        return;
    }
    Node* q = p->parent;

    if (p->left == NULL && p->right == NULL)
    {
        if (q->left == p) q->left = NULL;
        else q->right = NULL;
        delete p;
        return;
    }
 
    if (p->left == NULL && p->right != NULL)
    {
        if (q->left == p) q->left = p->right;
        else q->right = p->right;
        p->right->parent = q;
        delete p;
        return;
    }

    if (p->left != NULL && p->right == NULL)
    {
        if (q->left == p) q->left = p->left;
        else q->right = p->left;
        p->left->parent = q;
        delete p;
        return;
    }

    Node* t = p;
    while (t->left != NULL) t = t->left;

    if (t->right == NULL)
        t->parent->left = NULL;
    else {
        t->parent->left = t->right;
        t->right->parent = t->parent;
    }
    t->left = p->left;
    t->right = p->right;
    t->parent = q;

    if (q->left == p) q->left = t;
    else q->right = t;

    if (p->left != NULL)
        p->left->parent = t;

    p->right->parent = t;
    delete p;
    return;
}

void BinTree::DelRoot()
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        root = NULL;
        return;
    }
    if (root->left == NULL && root->right != NULL)
    {
        Node* q = root;
        root = q->right;
        root->right->parent = NULL;
        delete q;
        return;
    }
    if (root->left != NULL && root->right == NULL)
    {
        Node* q = root;
        root = q->left;
        root->left->parent = NULL;
        delete q;
        return;
    }

    Node* t = root;
    while (t->left != NULL) t = t->left;

    if (t->right == NULL)
        t->parent->left = NULL;
    else {
        t->parent->left = t->right;
        t->right->parent = t->parent;
    }
    t->left = root->left;
    t->right = root->right;
    t->parent = NULL;

    if (root->left != NULL)
        root->left->parent = t;

    root->right->parent = t;
    delete root;
    root = t;
    return;
}

void BinTree::TreeTraversal_LCR(Node* p)
{
    if (p == NULL) return;
    TreeTraversal_LCR(p->left);
    cout << p->key << ' ';
    TreeTraversal_LCR(p->right);
}

void BinTree::TreeTraversal_CLR(Node* p)
{
    if (p == NULL) return;
    cout << p->key << " ";
    TreeTraversal_CLR(p->left);
    TreeTraversal_CLR(p->right);
}

void BinTree::TreeTraversal_RCL(Node* p)
{
    if (p == NULL) return;
    TreeTraversal_RCL(p->right);
    cout << p->key << " ";
    TreeTraversal_RCL(p->left);
}

void BinTree::WidthTraversal(Node* p)
{
    if (p == NULL) return;
    for (int i = 0; i < FindHight(p); i++)
    {
        PrintCurrentLevel(p, i);
    }

}
void BinTree::PrintCurrentLevel(Node* p, int i)
{
    if (p == NULL) return;
    if(i==0) cout << p->key << " ";
    else if (i > 0)
    {
        PrintCurrentLevel(p->left, i - 1);
        PrintCurrentLevel(p->right, i - 1);
    }
}

Node* BinTree::FindKey(int k, Node* p)
{
    if (p == NULL) return NULL;
    if (p->key == k) return p;
    return FindKey(k,p->left) ?FindKey(k,p->left) : FindKey(k,p->right);
}

Node* BinTree::FindMax(Node* p)
{
    if (p == NULL) {
        return NULL;
    }
    Node* max = p;
    Node* left = FindMax(p->left);
    Node* right = FindMax(p->right);

    if (left && left->key > max->key) max = left;
    if (right && right->key > max->key) max = right;

    return max;
}

Node* BinTree::FindMin(Node* p)
{
    if (p == NULL) {
        return NULL;
    }
    Node* min = p;
    Node* left = FindMin(p->left);
    Node* right = FindMin(p->right);

    if (left && left->key < min->key) min = left;
    if (right && right->key < min->key) min = right;

    return min;
}

int BinTree::FindHight(Node* p)
{
    if (p != NULL) {
        int l, r;
        l = FindHight(p->left);
        r = FindHight(p->right);
        if (l > r) return l + 1;
        else return r + 1;
    }
    return 0;
}

int BinTree::Count(Node* p)
{
    int l, r;
    if (p != NULL) {
        if (p->left == NULL && p->right == NULL)
            return 1;
        if (p->left != NULL)
            l = Count(p->left);
        else l = 0;
        if (p->right != NULL)
            r = Count(p->right);
        else r = 0;
        return l + r + 1;
    }
    else return 0;
}

