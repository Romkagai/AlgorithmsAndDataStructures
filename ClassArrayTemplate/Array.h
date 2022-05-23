using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctime>
#include <locale>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string.h>

#define UI unsigned int

template <class T>
class Array
{
	T* a;
	int n;

public:
	Array(int N = 1);
	Array(T* b, int m);
	Array(const Array <T>&X);
	~Array();

	void ShiftRight(int pos);

	void Scan(int m);
	void Print();

	T& operator[] (int i);
	int FindKey(T);

	Array <T>& operator= (const Array <T>&);
	Array <T>& operator+= (T key);
	Array <T>operator+ (T key);
	Array <T>& operator+= (Array <T>);
	Array <T>operator+ (Array <T>);
	Array <T>& operator-= (T key);
	Array <T>operator- (T key);

	Array <T>& DelPosEq(int pos);
	Array <T>DelPosNew(int pos);

	bool operator== (Array <T>);
	bool operator!= (Array <T>);

	T Max();
	T Min();

	void Sorting();

	template <class T> friend ostream& operator << (ostream& r, Array <T>& x);
	template <class T> friend istream& operator >> (istream& r, Array <T>& x);

};

template <class T> void Array <T>::ShiftRight(int pos)
{
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n -= 1;
}
template <class T> Array <T>::Array(int N)
{
	a = new T[N]; n = N;
}
template <class T> Array <T>::Array(T* b, int m)
{
	a = new T[m];
	for (int i = 0; i < m; i++)
	{
		a[i] = b[i];
	}
	n = m;


}
template <class T> Array <T>::Array(const Array<T>& X)
{
	n = X.n;
	a = new T[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = X.a[i];
	}
}

template <class T> Array <T>:: ~Array()
{
	delete[]a;
}
template <class T> void Array<T>::Scan(int m)
{
	if (n == m)
		for (int i = 0; i < n; i++)
			cin >> a[i];
	else {
		delete[]a;
		a = new T[m];
		for (int i = 0; i < m; i++)
			cin >> a[i];
		n = m;
	}
}
template <class T> void Array<T>::Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
template <class T> T& Array<T>::operator[](int i)
{
	if (i < 0) {
		cout << "Incorrect index: i<0" << endl;
		return a[0];
	}
	if (i > n) {
		cout << "Incorrect index: i>n" << endl;
		return a[n - 1];
	}
	return a[i];

}
template <class T> int Array<T>::FindKey(T key)
{
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}
template <class T> Array<T>& Array<T>::operator=(const Array<T>& X)
{
	if (this != &X)
	{
		delete[]a;
		n = X.n;
		a = new T[n];
		for (int i = 0; i < n; i++)
			a[i] = X.a[i];
	}
	return *this;
}
template <class T> Array <T>& Array <T>::operator+=(T key)
{
	int i;
	T *t = new T[n + 1];
	for (i = 0; i < n; i++)
	{
		t[i] = a[i];
	}
	t[n] = key; //èçìåíåíèå
	delete[]a;
	a = t;
	n++;
	return *this;
}
template <class T> Array <T> Array <T>::operator+(T key)
{
	Array X(n + 1);
	for (int i = 0; i < n; i++)
	{
		X.a[i] = a[i];
	}
	X.a[n] = key;
	return X;
}
template <class T> Array <T>& Array<T>::operator+= (Array <T> X) {
	T* t = new T[n + X.n];
	for (int i = 0; i < n; i++)
	{
		t[i] = a[i];
	}
	for (int i = n; i < n + X.n; i++)
	{
		t[i] = X.a[i - n];
	}
	delete[]a;
	a = t;
	n += X.n;
	return *this;
}
template <class T> Array <T> Array <T>::operator+ (Array <T> X) {
	Array Result(n + X.n);
	for (int i = 0; i < n; i++) {
		Result.a[i] = a[i];
	}
	for (int i = n; i < n + X.n; i++) {
		Result.a[i] = X.a[i - n];
	}
	n += X.n;

	return Result;
}
template <class T> Array <T>& Array <T>::operator-=(T key)
{
	int pos = FindKey(key);
	if (pos + 1) {
		this->ShiftRight(pos);
	}
	else {
		cout << ("Äàííîå çíà÷åíèå îòñóòñòâóåò â ìàññèâå");
	}
	return *this;
}
template <class T> Array <T> Array <T>::operator-(T key)
{
	Array Result(n);
	for (int i = 0; i < n; i++) {
		Result.a[i] = a[i];
	}
	Result -= key;
	return Result;
}
template <class T> Array <T>& Array<T>::DelPosEq(int pos)
{
	try {
		if (pos < 0 || pos >= n) {
			throw ("Èíäåêñ íå âõîäèò â äèàïàçîí");
		}
		this->ShiftRight(pos);
	}
	catch (char* s) {
		cout << "Îøèáêà: " << s << "\nÓäàëÿåì ïåðâûé ýëåìåíò";
		this->ShiftRight(0);
	}
	return *this;
}
template <class T> Array <T> Array <T>::DelPosNew(int pos)
{
	Array Result(n);
	for (int i = 0; i < n; i++) {
		Result.a[i] = a[i];
	}
	try {
		if (pos < 0 || pos >= n) {
			throw ("Èíäåêñ íå âõîäèò â äèàïàçîí");
		}
		Result.ShiftRight(pos);
	}
	catch (char* s) {
		cout << "Îøèáêà: " << s << "\nÓäàëÿåì ïåðâûé ýëåìåíò";
		Result.ShiftRight(0);
	}
	return Result;
}
template <class T> bool Array<T>::operator==(Array <T> X)
{
	int i;
	if (n == X.n) {
		for (i = 0; i < n && a[i] == X.a[i]; i++);
		if (i == n) {
			return true;
		}
	}
	return false;
}
template <class T> bool Array<T>::operator!=(Array <T> X)
{
	return !(*this == X);

}
template <class T> T Array<T>::Max()
{
	T max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}
template <class T> T Array<T>::Min()
{
	T min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}
template <class T> void Array<T>::Sorting()
{
	T t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				t = a[j + 1]; a[j + 1] = a[j]; a[j] = t;
			}
		}
}
template <class T> ostream& operator << (ostream& r, Array<T>& x) {
	for (int i = 0; i < x.n; i++) {
		cout << x.a[i] << ' ';
	}
	cout << "\n";
	return r;
}
template <class T>  istream& operator >> (istream& r, Array<T>& x)
{
	x.Scan(x.n);
	return r;
}
