#include <locale.h>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;


//Реализация алгоритма прямого слияния для 4-х файлов
void Integration(FILE* A0, FILE* A1, FILE* B0, FILE* B1, int p) {
    int x0, x1;


    fscanf_s(A0, "%d", &x0);
    fscanf_s(A1, "%d", &x1);

    int n = 0;
    while ((feof(A0)==0) && (feof(A1)==0)) {
        int i = 0, j = 0;
        while ((feof(A0)==0) && (feof(A1)==0) && (i < p) && (j < p)) {
            if (x0 < x1) {
                if (n == 0) { fprintf(B0, "%d ", x0); }
                else { fprintf(B1, "%d ", x0); }
                fscanf_s(A0, "%d", &x0);
                i++;
            }
            else {
                if (n == 0) { fprintf(B0, "%d ", x1); }
                else { fprintf(B1, "%d ", x1); }
                fscanf_s(A1, "%d", &x1);
                j++;
            }
        }
        while ((feof(A0)==0) && (i < p)) {
            if (n == 0) { fprintf(B0, "%d ", x0); }
            else { fprintf(B1, "%d ", x0); }
            fscanf_s(A0, "%d", &x0);
            i++;
        }
        while ((feof(A1)==0) && j < p) {
            if (n == 0) { fprintf(B0, "%d ", x1); }
            else { fprintf(B1, "%d ", x1); }
            fscanf_s(A1, "%d", &x1);
            j++;
        }
        n = 1 - n;
    }
    while (feof(A0)==0) {
        if (n == 0) { fprintf(B0, "%d ", x0); }
        else { fprintf(B1, "%d ", x0); }
        fscanf_s(A0, "%d", &x0);
    }
    while (feof(A1)==0) {
        if (n == 0) { fprintf(B0, "%d ", x1); }
        else { fprintf(B1, "%d ", x1); }
        fscanf_s(A1, "%d", &x1);
    }
}


int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    FILE* A; FILE* F0; FILE* F1; FILE* G0; FILE* G1;
    int k, a;
    int p = 1;
    cout << "Введите количество элементов: ";
    cin >> k;

    //Создаем необходимые для алгоритма файлы
    fopen_s(&A, "A.txt", "w");
    for (int i = 0; i < k; i++) {
        a = rand() % 100;
      fprintf(A, "%d ", a); 
    }
    fopen_s(&F0, "F0.txt", "w");
    fopen_s(&F1, "F1.txt", "w");
    fopen_s(&G0, "G0.txt", "w");
    fopen_s(&G1, "G1.txt", "w");
    _fcloseall();

    //Вывод в консоль исходного массива
    fopen_s(&A, "A.txt", "r");
    cout << "Исходный массив: ";
    while (!feof(A)) {
        fscanf_s(A, "%d ", &a);
        cout << a << " ";
    }
    cout << endl;
    _fcloseall();

    //Разбиваем исходный файл
    fopen_s(&A, "A.txt", "r");
    fopen_s(&F0, "F0.txt", "w");
    fopen_s(&F1, "F1.txt", "w");
    int f = 1;
    while (!feof(A)) 
    {
        fscanf_s(A, "%d ", &a);
        if (f % 2 != 0) { fprintf(F0, "%d ", a); }
        else { fprintf(F1, "%d ", a); }
        f++;
    }
    _fcloseall();

    //Флаги для сортировки:
    // flag1=1 – сортировка не закончена;
    // flag2=0 – сливаем F[0] и F[1] в G[0] и G[1];
    // flag2=1 – сливаем G[0] и G[1] в F[0] и F[1];
    bool flag1 = 1, flag2 = 0;

    while (flag1 == 1) {
        if (flag2 == 0) {
            fopen_s(&F1, "F1.txt", "r");
            if (getc(F1) != EOF) {                  //Проверка на пустоту F1
                _fcloseall();
                fopen_s(&F0, "F0.txt", "r");
                fopen_s(&F1, "F1.txt", "r");
                fopen_s(&G0, "G0.txt", "w");
                fopen_s(&G1, "G1.txt", "w");
                Integration(F0, F1, G0, G1, p);     //Сливаем в G0, G1
                _fcloseall();
                flag2 = 1;
            }
            else flag1 = 0;
        }
        else {
            fopen_s(&G1, "G1.txt", "r");
            if (getc(G1) != EOF) {                  //Проверка на пустоту F1
                _fcloseall();
                fopen_s(&F0, "F0.txt", "w");
                fopen_s(&F1, "F1.txt", "w");
                fopen_s(&G0, "G0.txt", "r");
                fopen_s(&G1, "G1.txt", "r");
                Integration(G0, G1, F0, F1, p);     //Сливаем в F0, F1
                _fcloseall();
                flag2 = 0;
            }
            else flag1 = 0;
        }
        p = 2 * p;
    }



    if (flag2 == 0) {
        cout << "Отсортированный массив из файла F0: ";
        fopen_s(&F0, "F0.txt", "r");
        while (!feof(F0)) {
            fscanf_s(F0, "%d ", &a);
            cout << a << " ";
        }
        cout << endl;
    }
    else {
        cout << "Отсортированный массив из файла G0: ";
        fopen_s(&G0, "G0.txt", "r");
        while (!feof(G0)) {
            fscanf_s(G0, "%d ", &a);
            cout << a << " ";
        }
        cout << endl;
    }
    _fcloseall();

    return 0;
}