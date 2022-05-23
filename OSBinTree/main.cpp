#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "OSBinTree.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand((unsigned int) time(NULL));
    
    cout << "Input data: " << endl;
   
    int n = 5;
    int d[6] = {-1,    10,    20,    30,    40,    50};
    int p[6] = {-1,     2,     1,     1,     5,     3};
    int q[6] = {1,     10,     1,     4,     10,     6};
    
    cout << "d: {-1,    10,    20,    30,    40,    50}" << endl;
    cout << "p: {-1,     2,     1,     1,     5,     3}" << endl;
    cout << "q: {1,     10,     1,     4,    10,     6}" << endl;
    
    OSBinTree tree1(d,p,q,n);
    cout << "First optimal search tree:" << endl;
    tree1.PrintTree(1, tree1.GetRoot());
    
    cout << endl  << "Operator Assignment Check : " << endl;
    OSBinTree tree2;
    tree2 = tree1;
    tree2.PrintTree(1, tree2.GetRoot());
   
    cout << endl << "Copy constructor check : " << endl;
    OSBinTree tree3 = tree1;
    tree3.PrintTree(1,tree3.GetRoot());
     

}
