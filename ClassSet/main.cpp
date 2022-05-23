#include <iostream>
#include "Set.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "~~~~~~~~1~~~~~~~~" << endl;
    char s[257];
    cout << "Введите начальную строку: " << endl; // hello world
    cin.getline(s,256);
    Set s1(s);
    cout << "s1:"; s1.Print();
    int n = s1.Number();
    cout << "Количество элементов в s1: " << n << endl;
    cout << "~~~~~~~~2~~~~~~~~" << endl;
    Set s2(s1);
    cout << "s2:" << s2;
    if (s1 == s2) {
    cout << "s1 == s2" << endl;
    }
    else { cout << "s1 != s2" << endl; }
    cout << "~~~~~~~~3~~~~~~~~" << endl;
    if (s2.FindKey('o'))
    {
        s2 -= 'o';
    }
    else
    {
        s2 += 'o';
    }
    if (s2.FindKey('a'))
    {
        s2 -= 'a';
    }
    else
    {
        s2 += 'a';
    }
    cout << "s2: " << s2;
    if (s1 == s2)
    {
        cout << "s1 = s2" << endl;
    }
    else
    {
        cout << "s1 != s2" << endl;
    }
    cout << "~~~~~~~~4~~~~~~~~" << endl;
    Set s3;
    cout << "s3: " << s3;
    cout << "Проверка s3 на пустоту: ";
    if (s3.Empty())
    {
    cout << "Пустой!" << endl;
    }
    else
    {
    cout << "Не пустой!" << endl;
    }
    cout << "~~~~~~~~5~~~~~~~~" << endl;
    s3.Scan(6);                   //qwerty
    cout << "Проверка s3 на пустоту: ";
    if (s3.Empty())
    {
    cout << "Пустой!" << endl;
    }
    else
    {
    cout << "Не пустой!" << endl;
    }
    cout << "s3: " << s3;
    cout << "~~~~~~~~6~~~~~~~~" << endl;
    Set s4 = s3 - 'y' + 'i';
    cout << "s4: " << s4;
    cout << "~~~~~~~~7~~~~~~~~" << endl;
    Set t1, t2, t3;
    t1 = s2 + s4;
    t2 = s2 * s4;
    t3 = s2 - s4;
    cout << "t1 :" << t1 << endl;
    cout << "t2 :" << t2 << endl;
    cout << "t3 :" << t3 << endl;

    cout << "~~~~~~~~8~~~~~~~~" << endl;
    Set t4, t5;
    t4 = ~s2;
    t5 = t4 * s2;
    cout << "t4 :" << t4 << endl;
    cout << "t5 :" << t5;
    cout << "~~~~~~~~9~~~~~~~~" << endl;
    char char1[257];
    getchar();
    cout << "Введите строку: " << endl;
    cin.getline(char1,256); //hello friend
    Set s5(char1);
    cout << "s5: "; s5.Print();
    cout << "~~~~~~~~10~~~~~~~~" << endl;
    s5 = s5 * s1;
    cout << "s5 = s5*s1: " << s5;
    cout << "~~~~~~~~11~~~~~~~~" << endl;
    s5 = s5 + t2;
    cout << "s5 = s5+t2: " << s5;
    cout << "~~~~~~~~12~~~~~~~~" << endl;
    Set s6 = s1;
    cout << "s6: " << s6;
    if (s5 == s6) {
    cout << "s5 == s6" << endl;
    }
    else { cout << "s5 != s6" << endl; }

    return 0;
}
