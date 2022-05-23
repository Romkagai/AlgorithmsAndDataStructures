typedef unsigned char UC;
#include <iostream>
using namespace std;
#include <locale.h>
#include <string.h>
class BoolVector
{
    UC *bv;
    int n, m;
    //n -длина булева вектора,
    //m - количество элементов в массиве bv
    //связь n и m: m=n/8 если n%8=0;
    //m=n/8+1, если n%8!=0
    
    int Input(const char *, int , int , int);  //формирование элемента массива bv
    void Output(int , int);                    //вывод элемента массива bv
    
public:
    
    //конструкторы, деструктор, перегрузка оператора присвоения
    BoolVector(int n1 = 1);
    BoolVector(const BoolVector&);
    BoolVector(const char* s);
    BoolVector(const char* s, int);
    BoolVector operator= (const BoolVector&);
    ~BoolVector() { delete[]bv; }
    
    //ввод, вывод, вес, определение k-й компоненты
    void Scan(int);
    void Print();
    int Weight();
    UC operator[] (int);
    
    //сравнение
    bool operator== (BoolVector);
    bool operator!= (BoolVector);
    bool operator< (BoolVector);
    bool operator> (BoolVector);
    
    //побитовые операции
    BoolVector operator & (BoolVector &x);        //создается новый вектор
    BoolVector & operator &=(BoolVector &x);        //изменяется *this
    BoolVector operator |(BoolVector &x);            //создается новый вектор
    BoolVector & operator |=(BoolVector &x);        //изменяется *this
    BoolVector operator ^(BoolVector &x);            //создается новый вектор
    BoolVector & operator ^=(BoolVector &x);        //изменяется *this
    BoolVector operator ~();                        //изменяется *thi
    BoolVector operator <<(int);                    //создается новый вектор
    BoolVector  & operator <<=(int);                //изменяется *this
    BoolVector operator >>(int);                    //создается новый вектор
    BoolVector operator >>=(int);                //изменяется *this
    
    
    
    //Изменение одной компоненты вектора
    BoolVector SetUp1 (int pos);            //установить в 1 компоненту pos
    BoolVector SetUp0 (int pos);            //сбросить в 0 компоненту pos
    BoolVector Invert (int pos);            //инвертировать компоненту pos
    
    //Изменение нескольких компонент вектора
    BoolVector SetUp1 (int kol, int pos);
    //установить kol компонент начиная с позиции pos, изменяется *this
    BoolVector SetUp0 (int kol, int pos);
    //сбросить  kol компонент начиная с позиции pos, изменяется *this
    BoolVector Invert (int kol, int pos);
    //инвертировать kol компонент начиная с позиции pos, изменяется *this
    
    friend std::ostream & operator<< (ostream &r, BoolVector &V);
    friend std::istream & operator>> (istream &r, BoolVector &V);
    
};
