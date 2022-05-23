#include "OSBinTree.h"

void OSBinTree::CreateMatrix (int *p, int *q, int n, int **W, int **C, int **R)
    {int i, j, t;
     for (i=0; i<n+1; i++)
        for(j=0; j<n+1; j++)
        {
            W[i][j] = -1;
            C[i][j] = -1;
            R[i][j] = -1;
        }
   
    for(i=0; i<n+1; i++)
        W[i][i]=C[i][i]=q[i];
    
    
    for(i=0; i<n+1; i++)
        {j=i+1;
         W[i][j]=W[i][i]+p[j]+q[j];
         C[i][j]=W[i][j]+C[i][i]+C[j][j];
         R[i][j]=j;
        }

    int min, k, k_min;
   
    for(t=2; t<n+1; t++)
        for(i=0; i<n+1-t; i++)
            {j=i+t;
             W[i][j]=W[i][j-1]+p[j]+q[j];
         
             min=C[i][i]+C[i+1][j]; k_min=i+1;
             for(k=i+2; k<=j; k++)
                if(C[i][k-1]+C[k][j]<min)
                    {min=C[i][k-1]+C[k][j]; k_min=k;}
        
            C[i][j]=W[i][j]+min;
            R[i][j]=k_min;
            }
        
        cout <<"Matrix:" << endl;
        cout <<"W:" << endl;
        for (int a = 0; a < n+1; a++) {
            for (int b = 0; b < n+1; b++)
            {cout << W[a][b] <<"\t";}
            cout << endl;}
        
        cout <<"C:" << endl;
        for (int a = 0; a < n+1; a++) {
            for (int b = 0; b < n+1; b++)
            {cout << C[a][b] << "\t";}
            cout << endl;}
        
        cout <<"R:" << endl;
        
        for (int a = 0; a < n+1; a++) {
            for (int b = 0; b < n+1; b++)
            {cout << R[a][b] <<"\t";}
            cout << endl;}
        
    }

Node* OSBinTree::OTree(int *d,int i, int j, int **R, Node *p)
{
    if(i>=j) return NULL;
    int k = R[i][j];
    Node *q = new Node(d[k]);
    q->left = OTree(d, i, k-1, R, q);
    q->right = OTree(d, k, j, R, q);
    q->parent = p;
    return q;
}

OSBinTree::OSBinTree (int *d, int *p, int *q, int n)
{
    int **W, **C, **R;
    W = new int *[n+1];
    C = new int *[n+1];
    R = new int *[n+1];
    for (int i = 0; i<n+1; i++)
    {
        W[i] = new int[n+1];
        C[i] = new int[n+1];
        R[i] = new int[n+1];
    }
    CreateMatrix(p, q, n, W, C, R);
    int i=0, j=n;
    root = OTree(d, i, j, R, NULL);
    for(int i =0; i<n+1; i++)
    {
        delete[] W[i];
        delete[] C[i];
        delete[] R[i];
    }
    delete[] W;
    delete[] C;
    delete[] R;
    
}

OSBinTree & OSBinTree::operator=(const OSBinTree &T)
{
    this->BinTree::operator=(T);
    return *this;
}

OSBinTree::OSBinTree(const OSBinTree &T)
{
    if (T.root == NULL) root = NULL;
    else
    {
        root = new Node(T.root->key);
        Copy(T.root->left, root, 0);
        Copy(T.root->right, root, 1);
    }
}
