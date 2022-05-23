#include "Array.h"
//#include "romkagaiLib.h"

int main()
{
    /*setlocale(LC_ALL, "russian");
    srand(time(NULL));
    cout << "Проверим работу шаблона класса с различными типами данных" << endl;
    cout << "Создадим случайный массив с целочисленным типом данных:" << endl;
    cout << "Введите размер массива: "; int n; cin >> n;
    
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    Array <int> Mas1(a,n);
    delete[]a;
    cout << Mas1 << endl;

    cout << "Создадим случайный массив с символьным типом данных:" << endl;
    cout << "Введите размер массива: "; cin >> n;
    char* b = new char[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 10 + 97;
    }
    Array <char> Mas2(b, n);
    delete[]b;
    cout << Mas2 << endl;

    cout << "Создадим случайный массив с типом данных с плавающей точкой:" << endl;
    cout << "Введите размер массива: "; cin >> n;
    float* c = new float[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = rand() / float(100);
    }
    Array <float> Mas3(c, n);
    delete[]c;
    cout << Mas3 << endl;

    cout << "Найдем их max и min:" << endl;
    cout << "1) max=" << Mas1.Max() << "\t" << " min=" << Mas1.Min() << endl;
    cout << "1) max=" << Mas2.Max() << "\t" << " min=" << Mas2.Min() << endl;
    cout << "1) max=" << Mas3.Max() << "\t" << " min=" << Mas3.Min() << endl;

    cout << "Отсортируем все полученные массивы и получим:" << endl;
    Mas1.Sorting();
    Mas2.Sorting();
    Mas3.Sorting();
    cout << "1) " << Mas1;
    cout << "2) " << Mas2;
    cout << "3) " << Mas3;

    cout << "Теперь введите массив состоящий из символов (5 символов):" << endl;
    Array <char> Mas4(5);
    cin >> Mas4;
    cout << "Удалим из него средний элемент:" << endl;
    Mas4.DelPosEq(2);
    cout << Mas4;
    cout << "Выберите элемент для удаления из этого массива (напишите букву):" << endl;
    char k; cin >> k;
    Mas4 -= k;
    cout << "Получим массив:" << endl;
    Mas4.Print();*/


        setlocale(LC_ALL, "russian");
        srand(time(NULL));
        int n = 1;
        cout << "*******" << n << "*******" << endl;
        cout << "Введите mas1" << endl;
        n++;

        Array <char> mas1;
        mas1.Scan(5);
        cout << "Вы ввели:";
        mas1.Print();

        cout << "*******" << n << "*******" << endl;
        n++;
        cout << "Вывод mas2 = mas1 потоковым выводом:" << endl;
        Array <char> mas2 = mas1;
        cout << mas2;

        cout << "*******" << n << "*******" << endl;
        n++;

        cout << "Сравнение mas1 и mas2" << endl;
        if (mas1 == mas2) cout << "Они равны!" << endl;
        else cout << "Они не равны!" << endl;

        cout << "*******" << n << "*******" << endl;
        n++;

        cout << "Добавим 'f' к mas1" << endl;
        mas1 += 'f';
        cout << mas1;
        cout << "Сравнение mas1 и mas2" << endl;
        if (mas1 == mas2) cout << "Они равны!" << endl;
        else cout << "Они не равны!" << endl;


        cout << "*******" << n << "*******" << endl;
        n++;

        Array <char> mas3 = mas1 + 'g';
        cout << "Создадим массив 3 равный массиву 1 с добавленем 'g'" << endl;
        cout << mas3;

        cout << "*******" << n << "*******" << endl;
        n++;

        mas3.DelPosEq(0);
        cout << "Удалим первый элемент mas3" << endl << mas3;

        cout << "*******" << n << "*******" << endl;
        n++;

        Array <char> mas4 = mas3.DelPosNew(5);
        cout << "Создадим массив 4 равный массиву 3 с удалением последнего элемента" << endl;
        cout << mas4;

        cout << "*******" << n << "*******" << endl;
        n++;

        mas1 -= 'a';
        cout << "Удалим 'a' из mas1" << endl;
        cout << "Сравнение mas4 и mas1" << endl;
        if (mas1 == mas4) cout << "Они равны!" << endl;
        else cout << "Они не равны!" << endl;

        cout << "*******" << n << "*******" << endl;
        n++;

        int k;
        cout << "Введите кол-во элементов произвольного массива: ";
        cin >> k;
        char* a = new char[k];
        for (int i = 0; i < k; i++) {
            a[i] = rand() % 10 + 97;
        }
        cout << "Создадим mas5 класса Array:" << endl;
        Array <char> mas5(a, k);
        cout << mas5;

        cout << "*******" << n << "*******" << endl;
        n++;
        char max, min;
        max = mas5.Max();
        min = mas5.Min();
        cout << "Минимальный элемент mas5:" << min << endl << "Максимальный элемент mas5:" << max << endl;

        cout << "*******" << n << "*******" << endl;
        n++;

        mas5.Sorting();
        cout << "Отсортированный массив: " << mas5;

        cout << "*******" << n << "*******" << endl;
        n++;

        Array <char> mas6 = mas1 + mas5;
        cout << "Создаем mas6 путем объединения mas1 и mas5" << endl;
        cout << mas6;

        cout << "*******" << n << "*******" << endl;
        n++;
        Array <char> mas7(4);
        cout << "Ввод mas7 потоковым вводом (4 элемента):" << endl;
        cin >> mas7;
        cout << "Вы ввели:" << mas7 << endl;

        cout << "*******" << n << "*******" << endl;
        n++;

        int indexcheck;
        indexcheck = mas7.FindKey('a');
        cout << "Вхождение элемента 1 в mas7 по индексу: " << indexcheck << endl;
        indexcheck = mas7.FindKey('e');
        cout << "Вхождение элемента 10 в mas7 по индексу: " << indexcheck << endl;
        Array <char> mas8 = mas7 - 10;
        cout << "mas8: " << mas8;

        cout << "*******" << n << "*******" << endl;
        n++;
        mas4 += mas7;
        cout << "Изменим mas4 добавив к нему mas7: " << mas4;
        cout << "Сравнение mas4 и mas6" << endl;
        if (mas4 == mas6) cout << "Они равны!" << endl;
        else cout << "Они не равны!" << endl;

        cout << "*******" << n << "*******" << endl;
        n++;
        cout << "mas4: " <<mas4;
        cout << "mas6: " << mas6;

        mas4 = mas6;

        cout << "Присвоим к mas4 mas6 и получим: mas4: " << mas4;

    }


