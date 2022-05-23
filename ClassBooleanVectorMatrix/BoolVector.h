typedef unsigned char UC;
#include <iostream>
using namespace std;
#include <locale.h>
#include <string.h>
class BoolVector
{
    UC *bv;
    int n, m;
    //n - length of bv
    //m - number of elements in bv
    //n and m ratio : m=n/8 if n%8=0;
    //m=n/8+1, if n%8!=0
    
    int Input(const char *, int , int , int);  //forming bv element
    void Output(int , int);                    //output bv element
    
public:
    
    BoolVector(int n1 = 1);
    BoolVector(const BoolVector&);
    BoolVector(const char* s);
    BoolVector(const char* s, int);
    BoolVector operator= (const BoolVector&);
    ~BoolVector() { delete[]bv; }
    
    void Scan(int);
    void Print();
    int Weight();
    UC operator[] (int);
    
    bool operator== (BoolVector);
    bool operator!= (BoolVector);
    bool operator< (BoolVector);
    bool operator> (BoolVector);
    
    BoolVector operator & (BoolVector &x);        
    BoolVector & operator &=(BoolVector &x);        
    BoolVector operator |(BoolVector &x);           
    BoolVector & operator |=(BoolVector &x);        
    BoolVector operator ^(BoolVector &x);           
    BoolVector & operator ^=(BoolVector &x);       
    BoolVector operator ~();                       
    BoolVector operator <<(int);                  
    BoolVector  & operator <<=(int);               
    BoolVector operator >>(int);                   
    BoolVector operator >>=(int);                
    
    
    
   
    BoolVector SetUp1 (int pos);            
    BoolVector SetUp0 (int pos);            
    BoolVector Invert (int pos);           
    
    
    BoolVector SetUp1 (int kol, int pos);
    
    BoolVector SetUp0 (int kol, int pos);
  
    BoolVector Invert (int kol, int pos);
    
    
    friend std::ostream & operator<< (ostream &r, BoolVector &V);
    friend std::istream & operator>> (istream &r, BoolVector &V);
    
};
