#include "Set.h"
#include <iostream>
using namespace std;
Set::Set(Set& x) : BoolVector(x)
{
    M = x.M;
}

Set::Set(const char* s)
{
    n = 256;
    m = 32;
    bv = new UC[m];
    int i;
    for (i = 0; i < m; i++) bv[i] = 0;
    for (i = 0; s[i]; i++) SetUp1((int)s[i]);
    M = Weight();
}

Set& Set::operator= (const Set& x)
{
    if(this!=&x){
    this->BoolVector::operator=(x);
        M = this->Weight();}
    return *this;
}

Set Set::operator+(char ch)
{
    Set s = *this;
    s.SetUp1(ch);
    s.M = s.Weight();
    return s;
}

Set& Set::operator+=(char ch)
{
    SetUp1(ch);
    M = Weight();
    return *this;
}

Set Set::operator-(char ch)
{
    Set s = *this;
    s.SetUp0((UC)ch);
    s.M = s.Weight();
    return s;
}

Set& Set::operator-=(char ch)
{
    SetUp0((UC)ch);
    M = Weight();
    return *this;
}

Set Set::operator+(Set& x)
{
    Set s = *this;
    s |= x;
    s.M = s.Weight();
    return s;
}

Set Set::operator+=(Set& x)
{
    *this |= x;
    M = Weight();
    return *this;
}

Set Set::operator*(Set& x)
{
    Set s = *this;
    s &= x;
    s.M = s.Weight();
    return s;
}

Set Set::operator*=(Set &x)
{
    (*this) &= x;
    M = Weight();
    return *this;
}

Set Set::operator-(Set& x)
{
    Set s1 = *this;
    Set s2 = s1 * x;
    s1 ^= s2;
    s1.M = s1.Weight();
    return s1;
}

Set Set::operator-=(Set& x)
{
    Set s1 = (*this) * x;
    *this ^= s1;
    M = Weight();
    return *this;
}

Set Set::operator~()
{
    Set res = *this;
    res.BoolVector::operator~();
    res.M = res.Weight();
    return res;
}

void Set::Print()
{
    if (!(this->Empty()))
    {
        for (int i = 0; i < 256; i++)
        {
            if (operator[](i)=='1')
            {
                cout << UC(i) << ' ';
            }
        }
    }
    else
    {
        cout << "Empty";
    }
    cout << endl;
}

void Set::Scan(int n)
{
    cout << "enter " << n << " elements: ";
    char* s;
    s = new char[n + 1];
    cin >> s;
    Set res(s);
    *this = res;
    delete[] s;
}

bool Set::FindKey(char ch)
{
    if (operator[]((UC)ch))
    {
        return true;
    }
    return false;
}

bool Set::Empty()
{
    if (M == 0)
    {
        return true;
    }
    return false;
}

bool Set::NotEmpty()
{
    if (M != 0)
    {
        return true;
    }
    return false;
}

bool Set::operator==(Set x)
{
    if (this->BoolVector::operator==(x))
    {
        return true;
    }
    return false;
}

bool Set::operator!=(Set x)
{
    Set s = *this;
    int f = 0;
    for (int i = 0; i < M; i++)
        if (s[i] == x[i])
            f++;
    if (f == M)
        return true;
    else return false;
}

ostream& operator<< (ostream& r, Set& x)
{
    x.Print(); return r;
}

istream& operator>>(istream& r, Set& x)
{
    cout << "number of elements";
    char s[257];
    cin >> s;
    Set res(s);
    x = res;
    return r;
}
