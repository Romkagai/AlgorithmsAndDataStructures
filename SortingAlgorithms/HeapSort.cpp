#include <iostream>
using namespace std;

//Пирамидальная сортировка

void BuildHeap(int *arr, int n, int i)
{
    int Parent = i;                                     //Индекс родителя
    int leftChild = 2 * i + 1;                          //Индекс левого ребенка
    int rightChild = 2 * i + 2;                         //Индекс правого ребенка
    
    if (leftChild < n && arr[leftChild] > arr[Parent])  //Левый ребенок больше родителя
        Parent = leftChild;                             //Ребенок стал родителем
    
    if (rightChild < n && arr[rightChild] > arr[Parent])//Правый ребенок больше родителя
        Parent = rightChild;                            //Ребенок стал родителем
    
    if (Parent != i)                                    //Если родитель изменился
    {
        swap(arr[i], arr[Parent]);                      //Меняем элементы массива
        BuildHeap(arr, n, Parent);                      //Рекурсией идем дальше по куче с
    }                                                   //"Прошлым родителем"
}

void HeapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)                //Используя родителей из первой половины массива
    {
        BuildHeap(arr, n, i);                           //Ставим их и их детей на своё место
    }
  
    for (int i = n - 1; i >= 0; i--)                    //Достаем максимальные элементы из новой кучи
    {                                                   //Максимальный элемент "всплывает"
        swap(arr[0], arr[i]);                           //Поэтому поместим его в конец
        BuildHeap(arr, i, 0);                           //Без учета максимального элемента (i=n-1; i--), снова
    }                                                   //укомплектуем кучу
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
    HeapSort(arr, n);
    
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    cout << endl;
    delete[] arr;
    return 0;
}
