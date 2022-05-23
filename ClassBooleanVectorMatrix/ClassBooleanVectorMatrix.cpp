#include "ClassBooleanVectorMatrix.h"

BoolMatrix::BoolMatrix()
{
    m = 1; n = 1;
    BM = new BoolVector[m];
    BM[0]=BoolVector(1);
}

int BoolMatrix::Max(char** s, int m)
{
    int i, max = (int)strlen(s[0]);
    for (i = 0; i < m; i++)
        if ((int)strlen(s[i]) > max) max = (int)strlen(s[i]);
    return max;
}

BoolMatrix::BoolMatrix(int m1, int n1)
{
    m = m1; n = n1;
    BM = new BoolVector[m];
    for (int i = 0; i < m; i++)
    {
        BM[i]=BoolVector(n);
    }
}

BoolMatrix::BoolMatrix(char** s, int m1)
{
    m = m1;
    n = Max(s, m1);
    BM = new BoolVector[m];
    for (int i = 0; i < m; i++)
        BM[i] = BoolVector(s[i], n);
}

BoolMatrix::BoolMatrix(const BoolMatrix& x)
{
    m = x.m;  n = x.n;
    BM = new BoolVector[m];
    for (int i = 0; i < m; i++)
        BM[i] = x.BM[i];
}

BoolMatrix::~BoolMatrix()
{
    delete[]BM;
}

void BoolMatrix::Print()
{
    for (int i = 0; i < m; i++)
        cout << BM[i] << endl;
}

void BoolMatrix::Scan(int l, int k)
{
    if (m != l)
    {
        delete[]BM;
        m = l;
        BM = new BoolVector[m];
    }
    for (int i = 0; i < l; i++)
    {
        BM[i].Scan(k);
        cout << endl;
    }

}

BoolMatrix& BoolMatrix::operator= (const BoolMatrix& B)
{
    if (this != &B)
    {
        if (m != B.m)
        {
            delete[]BM;
            m = B.m;
            BM = new BoolVector[m];
        }
        for (int i = 0; i < m; i++)
            BM[i] = B.BM[i];
        n = B.n;
    }
    return *this;
}

BoolVector& BoolMatrix::operator[] (int i)
{
    try
    {
        if (i < 0) throw 0;
        if (i >= m) throw "Index >= m";
        return BM[i];
    }
    catch (int i)
    {
        cout << "Index < 0" << endl;
        return BM[0];
    }
    catch (char* s)
    {
        cout << s << endl;
        return BM[m - 1];
    }
    catch (...)
    {
        cout << "Wrong index" << endl;
        exit(-1);
    }
}


bool BoolMatrix::operator== (BoolMatrix& B)
{
    if (m != B.m || n != B.n) return false;
    for (int i = 0; i < m; i++)
        if (BM[i] != B.BM[i]) return false;
    return true;
}

bool BoolMatrix::operator!= (BoolMatrix& B)
{
    if (*this == B)return false;
    else return true;
}

BoolMatrix BoolMatrix::SetUp1(int i, int j)
{
    if (i < 0 || i >= m)
        cout << "Wrong index";
    else if (j < 0 || j >= n)
        cout << "Wrong index";
    else BM[i] = BM[i].SetUp1(j);
    return *this;
}

BoolMatrix BoolMatrix::SetUp0(int i, int j)
{

    if (i < 0 || i >= m)
        cout << "Wrong index";
    else if (j < 0 || j >= n)
        cout << "Wrong index";
    else BM[i] = BM[i].SetUp0(j);
    return *this;
}

BoolMatrix BoolMatrix::Invert(int i, int j)
{
    if (i < 0 || i >= m)
        cout << "Wrong index";
    else if (j < 0 || j >= n)
        cout << "Wrong index";
    else BM[i] = BM[i].Invert(j);
    return *this;
}

BoolMatrix BoolMatrix::SetUp1(int i, int kol, int pos)
{
    BM[i].SetUp1(kol, pos);
    return *this;
}

BoolMatrix BoolMatrix::SetUp0(int i, int kol, int pos)
{
    BM[i].SetUp0(kol, pos);
    return *this;

}

BoolMatrix BoolMatrix::Invert(int i, int kol, int pos)
{
    BM[i].Invert(kol, pos);
    return *this;

}

BoolMatrix BoolMatrix::operator& (BoolMatrix& B)
{
    if (m != B.m)
    {
        cout << "Error!";
        BoolMatrix res = *this;
        return res;
    }
    int n1 = n;
    if (n1 < B.n) n1 = B.n;
    BoolMatrix res(m, n1);
    for (int i = 0; i < m; i++)
        res.BM[i] = BM[i] & B.BM[i];
    return res;
}

BoolMatrix& BoolMatrix::operator&= (BoolMatrix& B)
{
    BoolMatrix res = (*this) & B;
    *this = res;
    return *this;
}

BoolMatrix BoolMatrix::operator| (BoolMatrix& B)
{
    if (m != B.m)
    {
        cout << "Error!";
        BoolMatrix res = *this;
        return res;
    }
    int n1 = n;
    if (n1 < B.n) n1 = B.n;
    BoolMatrix res(m, n1);
    for (int i = 0; i < m; i++)
        res.BM[i] = BM[i] | B.BM[i];
    return res;
}

BoolMatrix& BoolMatrix::operator|= (BoolMatrix& B)
{
    BoolMatrix res = (*this) & B;
    *this = res;
    return *this;
}

BoolMatrix BoolMatrix::operator^ (BoolMatrix& B)
{
    if (m != B.m)
    {
        cout << "Error!";
        BoolMatrix res = *this;
        return res;
    }
    int n1 = n;
    if (n1 < B.n) n1 = B.n;
    BoolMatrix res(m, n1);
    for (int i = 0; i < m; i++)
        res.BM[i] = BM[i] ^ B.BM[i];
    return res;
}

BoolMatrix& BoolMatrix::operator^= (BoolMatrix& B)
{
    BoolMatrix res = (*this) & B;
    *this = res;
    return *this;
}

BoolMatrix BoolMatrix::operator~()
{
    for (int i = 0; i < m; i++)~BM[i];
    return *this;
}

ostream& operator<< (ostream& r, BoolMatrix& x)
{
    x.Print();
    return r;
}

istream& operator>> (istream& r, BoolMatrix& x)
{
    x.Scan(x.m, x.n);
    return r;
}

BoolMatrix BoolMatrix::ShiftRight(int i, int k)
{
    BoolMatrix Res = *this;
    Res.BM[i] >>= k;
    return Res;
}

BoolMatrix BoolMatrix::ShiftLeft(int i, int k)
{
    BoolMatrix Res = *this;
    Res.BM[i] <<= k;
    return Res;
}

BoolMatrix& BoolMatrix::ShiftRightEq(int i, int k)
{
    BM[i] >>= k;
    return *this;
}

BoolMatrix& BoolMatrix::ShiftLeftEq(int i, int kol)
{
    BM[i] <<= kol;
    return *this;
}

BoolVector BoolMatrix::Conj()
{
    BoolVector H = BM[0];
    for (int i = 1; i < m; i++)H &= BM[i];
    return H;
}

BoolVector BoolMatrix::Disj()
{
    BoolVector H(n);
    for (int i = 0; i < m; i++)H |= BM[i];
    return H;
}

BoolVector BoolMatrix::Xor()
{
    BoolVector H(n);
    for (int i = 0; i < m; i++)H ^= BM[i];
    return H;
}
