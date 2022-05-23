#include <iostream>
#include "Graph.h"
int main(){
    setlocale(LC_ALL, "RU");
    cout << "Вход:(2, 1), (4, 5), (5, 1), (5, 3), (6, 2), (6, 3), (6, 5), (7, 1), (0,0)" << endl;
    
    Graph A, B;
    int n, i=0;
    
    n = A.FormGraph();
    A.SortGraph(B);
    int *a = new int[n];
    
    Lider *L = B.head->next;
    while (L != NULL) {
        a[i] = L->key;
        L = L->next;
        i++;
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {cout << a[i] << " ";}
    
    cout << endl;
    cout << "Решение: {7 6 4 5 3 2 1}" << endl;
    return 0;
}
