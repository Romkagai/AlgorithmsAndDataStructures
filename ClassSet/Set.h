#pragma once
#include "BoolVector.h"

class Set:public BoolVector
{int M;      //кол-во элементов мн-ва
    
public:
    Set() : BoolVector(256) { M=0; };
    Set(const char *s);
    Set(Set &);
    Set & operator= (const Set &);
    ~Set() {};
    
    Set operator+ (char ch);                // добавление эл-та к мн-ву  (создается новое мн-во)
    Set & operator+= (char ch);             // добавление эл-та к мн-ву (меняется *this)
    Set operator+ (Set &);                  // объединение мн-в (создается новое мн-во)
    Set operator+= (Set &);                 // объединение мн-в (меняется *this)
    
    Set operator- (char ch);                // удаление эл-та из мн-ва (создается новое мн-во)
    Set & operator-= (char ch);             // удаление эл-та из мн-ва (меняется *this)
    Set operator- (Set &);                  // разность мн-в (создается новое мн-во)
    Set operator-= (Set &);                 // разность мн-в (меняется *this)
    
    Set operator* (Set &);                  //пересечение мн-в (создается новое мн-во)
    Set operator*= (Set &);                 //объединение мн-в (меняется *this)
    
    Set operator~ ();                       //дополнение до универсального
    //универсальное мн-во - мн-во из 256 символов
    
    bool operator== (Set S);                //равенство мн-в
    bool operator!= (Set S);                //неравенство мн-в
    
    int Number() {return M;76};
    bool FindKey(char);                     //проверка принадлежности эл-та мн-ву
    
    bool Empty();                           //проверка пустоты множества
    bool NotEmpty();                        //проверка непустоты множества
    
    virtual void Scan(int) override;
    virtual void Print() override;
    
    friend ostream & operator<< (ostream &r, Set &S);
    friend istream & operator>> (istream &r, Set &S);
};

