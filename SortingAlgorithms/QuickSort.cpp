#include <iostream>
using namespace std;

//Сортировка Хоара (3 вариант)

void QuickSort(int *arr, int left, int right)
{
    int i = left, j = right;                    //Задаём левый и правый индексы сортируемого фрагмента
    double middle = arr[(left + right) / 2];    //Вычисляем средний элемент
    do {                                        //do{...} while
       while (arr[i] < middle)                  //Слева ищем индекс элемента, который больше, чем средний
         i++;
       while (arr[j] > middle)                  //Справа ищем индекс элемента, который меньше, чем средний
         j--;
     
       if (i <= j)                              //Если индекс большего, меньше, чем у меньшего
       {
         if (i < j)
         {
             swap(arr[i],arr[j]);               //Меняем элементы под этими индексами местами
         }
         i++;                                   //Увеличиваем i на 1
         j--;                                   //Уменьшаем j на 1
       }
    } while (i <= j);                           //Выполняем, пока возможно поставить элементы на свои места
                                                //Относительно среднего элемента.
                                                //Теперь средний элемент находится на своём месте!
    
    if (i < right)                              //К неотсортированной части массива справа от среднего элемента
       QuickSort(arr, i, right);                //Рекурсивно применяем быструю сортировку
    if (left < j)                               //К неотсортированной части массива слева от среднего элемента
       QuickSort(arr, left, j);                 //Рекурсивно применяем быструю сортировку
}

int main()
{
    setlocale(LC_ALL, "russian");
    srand( static_cast<unsigned int>(time(nullptr)));
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Неотсортированный массив:";
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    QuickSort(arr, 0, n);
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    cout << endl;
    delete[] arr;
    return 0;
}
