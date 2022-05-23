#define UI unsigned int
#include "romkagaiLib.h"

// Бинарный поиск в упорядоченном возрастающем массиве
int BinarySearch(int* a, int n, int k)
{
	int L = 0, R = n - 1;
	int m = (L + R) / 2;
	while (L <= R && a[m] != k)
	{
		m = (L + R) / 2;
		if (a[m] == k) return m;
		if (a[m] > k) R = m - 1;
		else L = m + 1;
	}
	if (L > R) return (-1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n,k;

	puts("Введите количество элементов массива:");
	
	scanf_s("%d", &n);
	int* A = new int[n];
	puts("Элементы массива:");

	for (int i = 0; i < n; i++)
	{
		A[i] = rand() % 100 + 1;
		printf("[%.d] ", A[i]);         //Заполняем массив n случайными числами от 1 до 100
	}

	puts("\nМассив по возрастанию:");   //Отсортируем и выведем массив
	InsertionSort(A, n);

	puts("\nВведите искомый элемент:"); // Ввод искомого элемента
	scanf_s("%d", &k);

	int result = BinarySearch(A, n, k)+1;  // Пользуемся функцией бинарного поиска
	if (result != 0) printf("Элемент расположен на %d-ом месте массива", result);
	else puts("Ошибка! Элемента нет в массиве");
	
}