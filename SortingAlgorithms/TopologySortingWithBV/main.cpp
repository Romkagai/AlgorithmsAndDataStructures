#include <iostream>
#include "ClassBooleanVectorMatrix.h"
#include <string.h>
#include <cstring>

using namespace std;

int main() {
    /*  v0 = ( 0000 0000 0)
        d = disj all rows
        w = инверсия d
        v1 = d
        arr = {n - 1 - i, ...}
        SetUp0(arr[n1-1]), SetUp0{arr[n2-1]}
        ...
        v0 = ...
        d = ...
        w = inverted d
        v1 = v0 xor d
        add arr{....}
        ...
        
        
     */
    
    setlocale(LC_ALL, "russian");
        int n = 9, i = 0;
        char** s;
        s = new char* [n];
        for (int i = 0; i < n; i++)
        {
            s[i] = new char[n+1];
        }
        strcpy(s[0], "000101000");
        strcpy(s[1], "101000100");
        strcpy(s[2], "000100000");
        strcpy(s[3], "000000000");
        strcpy(s[4], "001000000");
        strcpy(s[5], "000010000");
        strcpy(s[6], "000000010");
        strcpy(s[7], "000010000");
        strcpy(s[8], "000111000");
        BoolMatrix bm(s, n);
        BoolVector v0(n), v1(n), d(n), w(n);
        int* arr;
        arr = new int[n];

        cout << "Исходная матрица: " << endl;
        cout << bm;

        while (i < n)
        {
            d = bm.Disj();
            w = ~d;
            v1 = v0 ^ w;

            for (int j = 0; j < n; j++)
            {
                if (v1[n - j - 1])
                {
                    arr[i] = j + 1;
                    i++;
                    bm.SetUp0(j, n, 0);
                }
            }
            v0 = w;
        }
        cout << "Результат сортировки: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        delete[] s;
        delete[] arr;
        return 0;
}
