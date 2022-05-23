#include "List.h"

int main() {
    setlocale(LC_ALL, "russian");
        //-----------------------------------------------------------------
        cout << "1:" << endl;
        List s1;
        s1.AddToHead(1);                                                            // 1
        s1.AddToTail(10);
        s1.Print();
        //-----------------------------------------------------------------
        cout << endl << endl << "2:" << endl;
        List s2(6);
        cout << "S2: " << s2 << endl;
        Node* max, *min;
        max = s2.Max(); min = s2.Min();                                             // 2
        cout << "max: " << max->Key() << endl;
        cout << "min: " << min->Key() << endl;
        s2.Sort();
        cout << "Сортировка S2: " << s2 << endl;
        //-----------------------------------------------------------------
        cout << endl <<"3:" << endl;
        Node* pos = s2.FindPos(2);
        cout << "Второй элемент в S2: " << pos->Key() << endl;                      // 3
        s2.Del(pos);
        cout << "S2 без второго элемента: " << s2;
        //-----------------------------------------------------------------
        cout << endl <<  endl << "4:" << endl;
        pos = s2.FindPos(6);
        cout << "Попробуем найти в S2 шестой элемент: " << pos->Key() << endl;      // 4
        s2.DelTail();
        cout << "S2 без хвоста: " << s2;
        //-----------------------------------------------------------------
        cout << endl << endl << "5:" << endl;
        List s3;
        s3 = s1;
        cout << "S3: " << s3 << endl;
        cout << "S1==S3?" << endl;
        if (s1 == s3)
        {
            cout << "s1 = s3";                                                      // 5
        }
        else
            cout << "s1 != s3" << endl;

        pos = s3.FindKey(15);
        if (pos != 0)
        {
            cout << pos->Key() << endl;
        }
        //-----------------------------------------------------------------
        cout << endl <<"6:" << endl;
        s3.DelHead();
        pos = s3.FindKey(10);
        s3.Del(pos);
        cout << "S3 без головы и элемента 10: " << s3 << endl;
        if (s3.Empty())
        {                                                                           // 6
            cout << "s3 пустой!";
        }
        else
        {
            cout << "s3 не пустой!";
        }
        //-----------------------------------------------------------------
        cout << endl << endl << "7:" << endl;
        int mas[6];
        for (int i = 0; i < 6; i++)
        {
            mas[i] = rand() % 20;
        }
        List s4(mas, 6);
        cout << "S4: " << s4 << endl;
        cout << "Содержит ли S4 в себе элемент 25?" << endl;
        pos = s4.FindKey(25);                                                       // 7
        if (pos != 0)
        {
            cout << pos->Key() << endl;
        }
        pos = s4.FindPos(3);
        s4.AddAfter(25, pos);
        cout << "S4 с добавлением элемента 25 на 4 месте: " << s4;
        //-----------------------------------------------------------------
        cout << endl << endl << "8:" << endl;
        List s5(s2);
        cout << s5 << endl;
        cout << "Попробуем найти 4 в списке S5" << endl;
        if (s5.FindKey(4))
        {
            cout << "4 найдена! Удалим её!";
            pos = s5.FindKey(4);
            s5.Del(pos);                                                            // 8
        }
        else
        {
            cout << "4 не найдена! Добавим её в хвост! " << endl;
            s5.AddToTail(4);
        }
        cout << "Новый список S5: " <<s5;
        //-----------------------------------------------------------------
        cout << endl << endl << "9:" << endl;
        cout << "Добавим в S5 новые элементы"<< endl;
        cin >> s5; // 11 12 13 14 (n=4)
        cout << "S4" << s4 << endl;
        cout << "S5" << s5 << endl;
        cout << "Сравним списки S4 и S5" << endl;                                   // 9
        if (s4 == s5)
        {
            cout << "s4 = s5";
        }
        else
        {cout << "s4 != s5";}
        //-----------------------------------------------------------------
        cout << endl << endl << "10:" << endl;
        cout << "S1: " << s1 << endl;
        cout << "S4: " << s4 << endl;
        cout << "S5" << s5 << endl;                                                 // 10
        s5.AddToTail(s4);
        s5.AddToHead(s1);
        cout << "S5 с добавлением S4 в хвост и S1 в голову: "<< s5 << endl;
        return 0;
}
