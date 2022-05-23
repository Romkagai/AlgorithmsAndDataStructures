#pragma once
#include "BoolVector.h"

class BoolMatrix
{   BoolVector *BM;
    int m, n;                           
    int Max(char **s, int m);           
    
public:
    BoolMatrix();
    BoolMatrix(int, int);
    BoolMatrix (char **, int);
    BoolMatrix(const BoolMatrix &);
    BoolMatrix & operator= (const BoolMatrix &);
    ~BoolMatrix();
    
    void Scan(int, int);                
    void Print();
    
    BoolVector  & operator[] (int);
    bool operator== (BoolMatrix &);
    bool operator!= (BoolMatrix &);
    
  
    BoolMatrix SetUp1 (int, int);          
    BoolMatrix SetUp0 (int, int);           
    BoolMatrix Invert (int, int);          
    BoolMatrix SetUp1 (int i, int pos, int kol);  
    BoolMatrix SetUp0 (int i, int pos, int kol);
    BoolMatrix Invert (int i, int pos, int kol);
    
    
    BoolMatrix operator &(BoolMatrix &X);
    BoolMatrix & operator &=(BoolMatrix &x);
    BoolMatrix operator |(BoolMatrix &X);
    BoolMatrix & operator |=(BoolMatrix &x);
    BoolMatrix operator ^(BoolMatrix &X);
    BoolMatrix & operator ^=(BoolMatrix &x);
    BoolMatrix operator ~();                  
    BoolMatrix ShiftRight (int i,int k);
    BoolMatrix ShiftLeft (int i,int k);
    BoolMatrix & ShiftRightEq (int i,int k);
    BoolMatrix & ShiftLeftEq (int i,int k);
    
    
    BoolVector Conj ();             
    BoolVector Disj ();            
    BoolVector Xor ();              
    
    friend ostream & operator << (ostream &r, BoolMatrix &x);
    friend istream & operator >> (istream &r, BoolMatrix &x);
};


